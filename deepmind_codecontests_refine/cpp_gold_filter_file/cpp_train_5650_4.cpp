#include <bits/stdc++.h>
using namespace std;
const long double pi = acos(-1.0);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int alf = 26;
const int two = 2;
const long double eps = 1e-10;
const long long INF = (long long)(2e18 + 239);
const int BIG = (int)(1e9 + 239);
const int MOD = 998244353;
const long long MOD2 = (long long)MOD * (long long)MOD;
mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const int M = (int)(1e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 20;
const int T = (1 << 20) + 239;
const int B = 500;
const int X = 110;
int n, a[X];
void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  int s = 0;
  for (int i = 0; i < n; i++) s += a[i];
  int up = (s + 1) / 2;
  int pos = -1;
  for (int i = 0; i < n; i++)
    if (a[i] > up) {
      pos = i;
      break;
    }
  if (pos == -1) {
    cout << (s % 2 == 0 ? "HL\n" : "T\n");
    return;
  }
  cout << "T\n";
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
