#include <bits/stdc++.h>
using namespace std;
template <typename T>
void maxtt(T& t1, T t2) {
  t1 = max(t1, t2);
}
template <typename T>
void mintt(T& t1, T t2) {
  t1 = min(t1, t2);
}
bool debug = 0;
int n, m, k;
string direc = "URDL";
const long long MOD2 = (long long)998244353 * (long long)998244353;
long long ln, lk, lm;
void etp(bool f = 0) {
  puts(f ? "YES" : "NO");
  exit(0);
}
void addmod(int& x, int y, int mod = 998244353) {
  assert(y >= 0);
  x += y;
  if (x >= mod) x -= mod;
  assert(x >= 0 && x < mod);
}
void et(int x = -1) {
  printf("%d\n", x);
  exit(0);
}
long long fastPow(long long x, long long y, int mod = 998244353) {
  long long ans = 1;
  while (y > 0) {
    if (y & 1) ans = (x * ans) % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return ans;
}
long long gcd1(long long x, long long y) { return y ? gcd1(y, x % y) : x; }
int tr[400135][26], be[400135], cnt;
void add(int rt, int num, int id) {
  if (tr[rt][num] == 0) tr[rt][num] = ++cnt;
  be[id] = tr[rt][num];
}
char ins[400135];
vector<int> qs[400135];
const int maxn = 400135;
int acbe[400135];
vector<int> mp[400135];
struct Aca {
  int next[maxn][26], fail[maxn];
  int root, L;
  int newNode() {
    for (int i = 0; i < 26; i++) next[L][i] = -1;
    L++;
    return L - 1;
  }
  void init() {
    L = 0;
    root = newNode();
  }
  void insert(int val) {
    int now = root;
    int len = strlen(ins);
    for (int i = 0; i < len; i++) {
      int temp = ins[i] - 'a';
      if (next[now][temp] == -1) {
        next[now][temp] = newNode();
      }
      now = next[now][temp];
    }
    acbe[val] = now;
  }
  void build() {
    queue<int> que;
    fail[root] = root;
    for (int i = 0; i < 26; i++) {
      if (next[root][i] == -1) {
        next[root][i] = root;
      } else {
        fail[next[root][i]] = root;
        mp[root].push_back(next[root][i]);
        que.push(next[root][i]);
      }
    }
    while (!que.empty()) {
      int now = que.front();
      que.pop();
      for (int i = 0; i < 26; i++) {
        int t = next[now][i];
        if (t == -1) {
          next[now][i] = next[fail[now]][i];
        } else {
          fail[t] = next[fail[now]][i];
          mp[next[fail[now]][i]].push_back(t);
          que.push(t);
        }
      }
    }
  }
} ac;
int dfn, st[400135], ed[400135];
void dfs(int x, int pa) {
  st[x] = ++dfn;
  for (int c : mp[x])
    if (c != pa) {
      dfs(c, x);
    }
  ed[x] = ++dfn;
}
const int MN = (1 << 21) + 5;
struct mb {
  int M, T[MN];
  void init(int sz) {
    for (M = 1; sz + 2 > M; M <<= 1)
      ;
  }
  void init(int sz, int val) {
    for (M = 1; sz + 2 > M; M <<= 1)
      ;
    for (int(i) = 0; (i) < (int)(MN); (i)++) T[i] = val;
  }
  void clear() { memset(T, 0, sizeof T); }
  void upt(int l, int r, int val) {
    for (l = l + M - 1, r = r + M + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
      if (~l & 1) T[l ^ 1] += val;
      if (r & 1) T[r ^ 1] += val;
    }
  }
  int qy(int l) {
    int ans = 0;
    l += M;
    while (l >= 1) {
      ans += T[l];
      l >>= 1;
    }
    return ans;
  }
} T;
int Ans[400135];
void cal(int x, int pos) {
  for (int id : qs[x]) {
    int w = acbe[id];
    Ans[id] = T.qy(st[w]) - T.qy(ed[w]);
  }
  for (int(j) = 0; (j) < (int)(26); (j)++)
    if (tr[x][j]) {
      int w = ac.next[pos][j];
      T.upt(1, st[w], 1);
      cal(tr[x][j], w);
      T.upt(1, st[w], -1);
    }
}
void fmain(int tid) {
  scanf("%d", &n);
  for (int(i) = 1; (i) <= (int)(n); (i)++) {
    int t;
    char ope[2];
    scanf("%d", &t);
    if (t == 1) {
      scanf("%s", ope);
      add(0, ope[0] - 'a', i);
    } else {
      scanf("%d%s", &k, ope);
      add(be[k], ope[0] - 'a', i);
    }
  }
  scanf("%d", &m);
  ac.init();
  for (int(i) = 1; (i) <= (int)(m); (i)++) {
    scanf("%d%s", &k, ins);
    qs[be[k]].push_back(i);
    ac.insert(i);
  }
  ac.build();
  dfs(0, -1);
  T.init(dfn);
  cal(0, 0);
  for (int(i) = 1; (i) <= (int)(m); (i)++) printf("%d\n", Ans[i]);
}
int main() {
  int t = 1;
  for (int(i) = 1; (i) <= (int)(t); (i)++) {
    fmain(i);
  }
  return 0;
}
