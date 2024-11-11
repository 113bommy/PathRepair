#include <bits/stdc++.h>
using namespace std;
void cline() { cout << '\n'; }
template <typename T, typename... V>
void cline(T t, V... v) {
  cout << t;
  if (sizeof...(v)) cout << ' ';
  cline(v...);
}
void cspc() { cout << ' '; }
template <typename T, typename... V>
void cspc(T t, V... v) {
  cout << t;
  if (sizeof...(v)) cout << ' ';
  cspc(v...);
}
const int N = 1e6 + 4;
double checker = 1e-6;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  double a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  double alpha_max = 1e8;
  double alpha_min = 0;
  for (int i = 0; i < n; i++) {
    double toi = i + 1;
    alpha_max = min(alpha_max, (double)(10 * (a[i] + 1) / toi));
    alpha_min = max(alpha_min, (double)(10 * a[i] / toi));
  }
  int nm = (int)((alpha_max - checker) * (n + 1) / 10);
  int nn = (int)(alpha_min * (n + 1) / 10);
  if (nm == nn) {
    cline("unique");
    cspc(nn);
  } else {
    cspc("not unique");
  }
  return 0;
}
