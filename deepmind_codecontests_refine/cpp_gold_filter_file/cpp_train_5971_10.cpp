#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1000000007;
const long long BIG = 1446803456761533460;
const int Big = 336860180;
stringstream sss;
const long long int maxd = 1000000010;
long long int T, n, m;
long long int calc(long long int d, long long int m) {
  long long int dm = d * m;
  long long int n = 1;
  long long int s = 0;
  long long int c = 1;
  long long int i = 0;
  while (i < d) {
    if (c > dm / (d - i) + 1) break;
    c = c * (d - i) / (i + 1);
    if (c > dm / (i + 1) + 1 || s + c * (i + 1) > dm) break;
    s += c * (i + 1);
    n += c;
    ++i;
  }
  n += (dm - s) / (i + 1);
  return n;
}
void MAIN() {
  cin >> T;
  for (long long int t = (0); t < (T); ++t) {
    cin >> n >> m;
    m = min(m, (n / 2));
    long long int l = -1, r = maxd;
    while (r - l > 1) {
      long long int d = (l + r) / 2;
      if (calc(d, m) >= n)
        r = d;
      else
        l = d;
    }
    cout << r << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(10);
  sss << R"(
5
4 1
4 2
7 3
1 1
42 7
    )";
  MAIN();
  return 0;
}
