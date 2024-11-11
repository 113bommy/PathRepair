#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2002;
int N;
int d[11];
int u[11];
int hash[11][MAXN][MAXN];
string s;
string q[11];
set<int> S;
map<int, int> H[11];
int main() {
  cin >> s;
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> q[i] >> d[i] >> u[i];
  for (int k = 1; k <= N; k++)
    for (int i = 0; i < ((int)q[k].size()); i++) {
      int h = 0;
      for (int j = i; j < ((int)q[k].size()); j++) {
        h = h * 257 + q[k][j];
        H[k][h]++;
      }
    }
  int res = 0;
  for (int i = 0; i < ((int)s.size()); i++) {
    int h = 0;
    for (int j = i; j < ((int)s.size()); j++) {
      h = h * 157LL + s[j];
      if (S.find(h) == S.end()) {
        S.insert(h);
        bool ok = 1;
        for (int k = 1; k <= N; k++)
          if (H[k][h] < d[k] || H[k][h] > u[k]) {
            ok = 0;
            break;
          }
        res += ok;
      }
    }
  }
  printf("%d\n", res);
  return 0;
}
