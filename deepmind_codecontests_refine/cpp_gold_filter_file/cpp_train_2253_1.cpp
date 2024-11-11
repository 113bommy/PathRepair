#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500, MAXT = 200100;
int M[MAXT];
vector<int> V[MAXN];
vector<pair<int, int> > C[MAXN][MAXN];
int t;
int sol[MAXN][MAXN], cnt[MAXN][MAXN];
bool pass[MAXN][MAXN];
queue<pair<int, int> > W, L;
void WChildren(pair<int, int> p) {
  sol[p.first][p.second] = 1;
  vector<int> P = V[p.first], R = V[p.second];
  for (int i = (0); i < (int)(C[p.first][p.second].size()); i++) {
    pair<int, int> kid = C[p.first][p.second][i];
    if (pass[kid.first][kid.second]) continue;
    cnt[kid.first][kid.second]--;
    if (!cnt[kid.first][kid.second]) {
      pass[kid.first][kid.second] = true;
      L.push(kid);
    }
  }
}
void LChildren(pair<int, int> p) {
  sol[p.first][p.second] = 0;
  vector<int> P = V[p.first], R = V[p.second];
  for (int i = (0); i < (int)(C[p.first][p.second].size()); i++) {
    pair<int, int> kid = C[p.first][p.second][i];
    if (pass[kid.first][kid.second]) continue;
    W.push(kid);
    pass[kid.first][kid.second] = true;
  }
}
void correte() {
  while (W.size()) W.pop();
  while (L.size()) L.pop();
  sol[0][0] = 0;
  for (int i = (1); i < (int)(495); i++) {
    L.push(make_pair(0, i));
    L.push(make_pair(i, 0));
  }
  while (W.size() || L.size()) {
    while (W.size()) {
      WChildren(W.front());
      W.pop();
    }
    while (L.size()) {
      LChildren(L.front());
      L.pop();
    }
  }
}
int HASH(vector<int> &VV) {
  int ans = 0;
  for (int i = (0); i < (int)(5); i++) {
    ans *= 9;
    ans += VV[i];
  }
  return ans;
}
void getmapping() {
  for (int i = (0); i < (int)(MAXN); i++) V[i].clear();
  for (int i = (0); i < (int)(MAXT); i++) M[i] = 0;
  vector<int> X = {8, 0, 0, 0, 0};
  M[HASH(X)] = 0;
  V[0] = X;
  int tot = 1;
  for (int a = (0); a < (int)(8); a++)
    for (int b = (0); b < (int)(9); b++)
      for (int c = (0); c < (int)(9); c++)
        for (int d = (0); d < (int)(9); d++)
          for (int e = (0); e < (int)(9); e++) {
            if (a + b + c + d + e != 8) continue;
            X = {a, b, c, d, e};
            M[HASH(X)] = tot;
            V[tot++] = X;
          }
}
void getchildren() {
  for (int i = (0); i < (int)(495); i++)
    for (int j = (0); j < (int)(495); j++) {
      C[i][j].clear();
      cnt[i][j] = 0;
    }
  int it = 0;
  for (int ti = (1); ti < (int)(495); ti++)
    for (int tj = (1); tj < (int)(495); tj++) {
      vector<int> A = V[ti], B = V[tj], Aux = A;
      for (int i = (1); i < (int)(5); i++)
        for (int j = (1); j < (int)(5); j++)
          if (A[i] && B[j]) {
            Aux[i]--;
            Aux[(i + j) % 5]++;
            int pi = M[HASH(B)], pj = M[HASH(Aux)];
            C[pi][pj].push_back(make_pair(ti, tj));
            cnt[ti][tj]++;
            Aux[i]++;
            Aux[(i + j) % 5]--;
          }
    }
}
int main() {
  getmapping();
  getchildren();
  for (int i = (0); i < (int)(500); i++)
    for (int j = (0); j < (int)(500); j++) pass[i][j] = false;
  for (int i = (0); i < (int)(500); i++)
    for (int j = (0); j < (int)(500); j++) sol[i][j] = 2;
  correte();
  int t;
  scanf("%d", &t);
  for (int cs = (0); cs < (int)(t); cs++) {
    int st;
    scanf("%d", &st);
    vector<int> A(5, 0), B(5, 0);
    for (int i = (0); i < (int)(8); i++) {
      int x;
      scanf("%d", &x);
      A[x]++;
    }
    for (int i = (0); i < (int)(8); i++) {
      int x;
      scanf("%d", &x);
      B[x]++;
    }
    if (st) swap(A, B);
    switch (sol[M[HASH(A)]][M[HASH(B)]]) {
      case 0:
        cout << (st ? "Alice" : "Bob") << endl;
        break;
      case 1:
        cout << (st ? "Bob" : "Alice") << endl;
        break;
      case 2:
        cout << "Deal" << endl;
        break;
      default:
        assert(false);
    }
  }
  return 0;
}
