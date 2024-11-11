#include <bits/stdc++.h>
using namespace std;
using namespace std;
int v2[502];
int N, MOD;
int mem[2][502][502];
int dp(int id, int Z, int O) {
  if (id == N) return 1;
  int w = 0;
  if (v2[id] == 0)
    w = dp(id + 1, Z, O);
  else if (v2[id] == 1) {
    w = Z * dp(id + 1, Z - 1, O + 1) + O * dp(id + 1, Z, O - 1);
  } else if (v2[id] == 2) {
    w = (Z < 2 ? 0 : (Z * (Z - 1)) / 2 * dp(id + 1, Z - 2, O + 2)) +
        (O < 2 ? 0 : (O * (O - 1)) / 2 * dp(id + 1, Z, O - 2)) +
        (!Z || !O ? 0 : Z * O * dp(id + 1, Z - 1, O));
  }
  return w;
}
int main() {
  int R;
  cin >> N >> R >> MOD;
  for (int i = 0; i < N; ++i) v2[i] = 2;
  int s = 0;
  for (int i = 0; i < R; ++i) {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '1') v2[i]--;
    }
  }
  for (int i = 0; i < N; ++i) s += v2[i];
  int D = N - R;
  for (int id = N; id >= 0; --id) {
    s -= v2[id];
    for (int Z = max(D / 2 - id, 0); Z <= D - (s + 1) / 2; ++Z) {
      for (int O = 0; O + Z <= N; ++O) {
        if (id == N)
          mem[id & 1][Z][O] = Z == 0 && O == 0;
        else {
          long long w = 0;
          if (v2[id] == 0)
            w = mem[(id + 1) & 1][Z][O];
          else if (v2[id] == 1) {
            w = 1LL * Z * mem[(id + 1) & 1][Z - 1][O + 1] +
                1LL * O * mem[(id + 1) & 1][Z][O - 1];
          } else if (v2[id] == 2) {
            w = (Z < 2 ? 0
                       : 1LL * (Z * (Z - 1)) / 2 *
                             mem[(id + 1) & 1][Z - 2][O + 2]) +
                (O < 2
                     ? 0
                     : 1LL * (O * (O - 1)) / 2 * mem[(id + 1) & 1][Z][O - 2]) +
                (!Z || !O ? 0 : 1LL * Z * O * mem[(id + 1) & 1][Z - 1][O]);
          }
          mem[id & 1][Z][O] = w % MOD;
        }
      }
    }
  }
  cout << mem[0][N - R][0] << endl;
}
