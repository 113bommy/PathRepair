#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
const int M = 4 * N;
int n;
int Mod;
int Phi;
int a[N];
int Inv[N];
vector<int> Primes;
vector<int> Powers[30 * N];
int Tree1[M], Lazy1[M];
int Tree2[M], Lazy2[M];
vector<int> Tree3[M];
void add_self(int& x, int y) {
  if ((x += y) >= Mod) x -= Mod;
}
int add(int x, int y) { return add_self(x, y), x; }
int mul(int x, int y) { return (long long)x * y % Mod; }
void mul_self(int& x, int y) { x = mul(x, y); }
int fp(int x, int y) {
  if (!y) return 1;
  if (y & 1) return mul(x, fp(x, y - 1));
  return fp(mul(x, x), y >> 1);
}
int inv(int x) { return fp(x, Phi - 1); }
void FactMod() {
  int Temp = Mod;
  for (int x = 2; x * x <= Temp; x++)
    while (Temp % x == 0) Primes.push_back(x), Temp /= x;
  if (Temp > 1) Primes.push_back(Temp);
  sort(Primes.begin(), Primes.end());
  Primes.erase(unique(Primes.begin(), Primes.end()), Primes.end());
}
int Log(int& x, int y) {
  int Res = 0;
  while (x && x % y == 0) Res++, x /= y;
  return Res;
}
void Merge(int Node) {
  Tree1[Node] = add(Tree1[(Node << 1)], Tree1[(Node << 1 | 1)]);
  Tree2[Node] = add(Tree2[(Node << 1)], Tree2[(Node << 1 | 1)]);
  for (int i = 0; i < Primes.size(); i++)
    mul_self(Tree1[Node], Powers[Tree3[Node][i]][i]);
}
void PushLazy(int Node, int Len) {
  if (Lazy1[Node] != 1) {
    mul_self(Tree1[Node], Lazy1[Node]);
    if (Len > 1) {
      mul_self(Lazy1[(Node << 1)], Lazy1[Node]);
      mul_self(Lazy1[(Node << 1 | 1)], Lazy1[Node]);
    }
    Lazy1[Node] = 1;
  }
  if (Lazy2[Node] != 1) {
    mul_self(Tree2[Node], Lazy2[Node]);
    if (Len > 1) {
      mul_self(Lazy2[(Node << 1)], Lazy2[Node]);
      mul_self(Lazy2[(Node << 1 | 1)], Lazy2[Node]);
    }
    Lazy2[Node] = 1;
  }
}
void PutLazy(int Node, int Len, int x) {
  int y = x;
  for (int i = 0; i < Primes.size(); i++) Tree3[Node][i] += Log(x, Primes[i]);
  mul_self(Lazy1[Node], x);
  mul_self(Lazy2[Node], x);
  PushLazy(Node, Len);
  mul_self(Tree1[Node], y / x);
}
void Build(int Node = 1, int L = 1, int R = n) {
  Tree1[Node] = Tree2[Node] = 0;
  Lazy1[Node] = Lazy2[Node] = 1;
  Tree3[Node].assign(Primes.size(), 0);
  if (L == R) {
    int x = a[L];
    Tree1[Node] = x % Mod;
    for (int i = 0; i < Primes.size(); i++) Tree3[Node][i] = Log(x, Primes[i]);
    Tree2[Node] = x % Mod;
    return;
  }
  Build((Node << 1), L, ((L + R) >> 1));
  Build((Node << 1 | 1), ((L + R) >> 1) + 1, R);
  Merge(Node);
}
void Update1(int i, int j, int x, int Node = 1, int L = 1, int R = n) {
  PushLazy(Node, R - L + 1);
  if (j < i || R < L) return;
  if (j < L || R < i) return;
  if (i <= L && R <= j) return PutLazy(Node, R - L + 1, x);
  Update1(i, j, x, (Node << 1), L, ((L + R) >> 1));
  Update1(i, j, x, (Node << 1 | 1), ((L + R) >> 1) + 1, R);
  Merge(Node);
}
queue<int> Values;
void Update2(int i, int x, int Node = 1, int L = 1, int R = n) {
  PushLazy(Node, R - L + 1);
  if (i < L || R < i) return;
  if (L == R) {
    int OldNode = Node;
    for (int j = 0; j < Primes.size(); j++) {
      int y = Log(x, Primes[j]);
      Node = OldNode;
      int Sum = 0;
      while (!Values.empty()) Values.pop();
      for (int Last = -1; Node; Last = Node, Node >>= 1) {
        int Can = min(y, Tree3[Node][j]);
        y -= Can;
        Tree3[Node][j] -= Can;
        Sum += Can;
        Values.push(Can);
      }
      Node = OldNode;
      for (int Last = -1; Node; Last = Node, Node >>= 1) {
        if (Last == (Node << 1)) {
          mul_self(Tree1[(Node << 1 | 1)], Powers[Sum][j]);
          Tree3[(Node << 1 | 1)][j] += Sum;
        }
        if (Last == (Node << 1 | 1)) {
          mul_self(Tree1[(Node << 1)], Powers[Sum][j]);
          Tree3[(Node << 1)][j] += Sum;
        }
        Sum -= Values.front();
        Values.pop();
        if (Last != -1) Merge(Node);
      }
      assert(!y);
    }
    Node = OldNode;
    mul_self(Tree2[Node], Inv[x]);
    Tree1[Node] = Tree2[Node];
    for (int i = 0; i < Primes.size(); i++)
      mul_self(Tree1[Node], Powers[Tree3[Node][i]][i]);
    return;
  }
  Update2(i, x, (Node << 1), L, ((L + R) >> 1));
  Update2(i, x, (Node << 1 | 1), ((L + R) >> 1) + 1, R);
  Merge(Node);
}
int Query(int i, int j, int Node = 1, int L = 1, int R = n) {
  PushLazy(Node, R - L + 1);
  if (j < i || R < L) return 0;
  if (j < L || R < i) return 0;
  if (i <= L && R <= j) return Tree1[Node];
  int staff = 1;
  for (int k = 0; k < Primes.size(); k++)
    mul_self(staff, Powers[Tree3[Node][k]][k]);
  return mul(staff, add(Query(i, j, (Node << 1), L, ((L + R) >> 1)),
                        Query(i, j, (Node << 1 | 1), ((L + R) >> 1) + 1, R)));
}
int main() {
  cin >> n >> Mod;
  FactMod();
  Phi = Mod;
  for (int p : Primes) Phi /= p, Phi *= (p - 1);
  for (int i = 1; i < N; i++) Inv[i] = inv(i);
  for (int i = 0; i < 30 * N; i++) Powers[i].assign(Primes.size(), 1);
  for (int i = 1; i < N; i++)
    for (int j = 0; j < Primes.size(); j++)
      Powers[i][j] = mul(Primes[j], Powers[i - 1][j]);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  Build();
  int q;
  cin >> q;
  while (q--) {
    int T;
    scanf("%d", &T);
    if (T == 1) {
      int L, R, x;
      scanf("%d%d%d", &L, &R, &x);
      Update1(L, R, x);
    } else if (T == 2) {
      int i, x;
      scanf("%d%d", &i, &x);
      Update2(i, x);
    } else {
      int L, R;
      scanf("%d%d", &L, &R);
      printf("%d\n", Query(L, R) % Mod);
    }
  }
}
