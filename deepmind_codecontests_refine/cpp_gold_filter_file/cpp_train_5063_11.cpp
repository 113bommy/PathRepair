#include <bits/stdc++.h>
using namespace std;
const double pi = 3.1415926535897932384626433832795;
const double eps = 1e-12;
const int INF = 1 << 30;
const long long LINF = 1ll << 60;
const int BUFFER_SZ = 1 << 10;
const int MOD = 1000 * 1000 * 1000 + 7;
char BUFFER[BUFFER_SZ];
int gi() {
  int x;
  scanf("%d", &x);
  return x;
}
double gd() {
  double x;
  scanf("%lf", &x);
  return x;
}
long long gll() {
  long long x;
  scanf("%lld", &x);
  return x;
}
vector<int> gvi(int n) {
  vector<int> a;
  while (n-- > 0) a.push_back(gi());
  return a;
}
string gs() {
  scanf("%s", BUFFER);
  return string(BUFFER);
}
template <class T>
void print(vector<T> &x, string format) {
  format += "%c";
  for (int i = 0; i < x.size(); ++i)
    printf(format.c_str(), x[i], i + 1 == x.size() ? '\n' : ' ');
}
const int EQ = 0;
const int GR = 2;
const int LV = 1;
long long dp[64][3][3];
int N;
string locked;
long long rec(int a, int b, int eqR, int eqC) {
  long long &r = dp[a][eqR][eqC];
  if (r != -1) return r;
  if (a > b) {
    if (eqR != GR && eqC != GR) return r = 1;
    return r = 0;
  } else {
    r = 0;
    for (int d1 = 0; d1 < 2; ++d1) {
      for (int d2 = 0; d2 < 2; ++d2) {
        if (a == b && d1 != d2) continue;
        if (a < locked.size() && locked[a] - '0' != d1) continue;
        if (b < locked.size() && locked[b] - '0' != d2) continue;
        int _eqR;
        if (eqR == EQ) {
          if (d1 == d2) {
            _eqR = EQ;
          } else if (d1 > d2) {
            _eqR = GR;
          } else if (d1 < d2) {
            _eqR = LV;
          }
        } else {
          _eqR = eqR;
        }
        int _eqC;
        if (eqC == EQ) {
          if (d1 == 1 - d2) {
            _eqC = EQ;
          } else if (d1 > 1 - d2) {
            _eqC = GR;
          } else if (d1 < 1 - d2) {
            _eqC = LV;
          }
        } else {
          _eqC = eqC;
        }
        r += rec(a + 1, b - 1, _eqR, _eqC);
        if (r > LINF) r = LINF;
      }
    }
    return r;
  }
}
long long getN(string pref) {
  memset((dp), (-1), sizeof(dp));
  locked = pref;
  return rec(0, N - 1, EQ, EQ);
}
void solve() {
  N = gi();
  long long K = gll();
  string RES = "";
  if (K >= getN(""))
    printf("-1\n");
  else {
    for (int i = 0; i < N; ++i) {
      RES += "0";
      long long x = getN(RES);
      if (K >= x) {
        K -= x;
        RES[RES.size() - 1] = '1';
      }
    }
    printf("%s\n", RES.c_str());
  }
}
int main() {
  solve();
  return 0;
}
