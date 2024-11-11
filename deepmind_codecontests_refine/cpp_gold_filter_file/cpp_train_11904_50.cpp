#include <bits/stdc++.h>
const long long inf = 0x3f3f3f3f3f3f3f3LL;
const long long mod = (long long)1e9 + 7;
using namespace std;
template <class T, class T2>
void smin(T& a, T2 val) {
  if (a > val) a = val;
}
template <class T, class T2>
void smax(T& a, T2 val) {
  if (a < val) a = val;
}
const long long N = 5 * (long long)1e5 + 10;
long long n;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  vector<long long> a(3);
  for (long long i = 0; i < 3; ++i) {
    cin >> a[i];
  }
  if (count(a.begin(), a.end(), 0) == 3) {
    cout << 0 << " " << 0 << " " << 0;
    exit(0);
  }
  double D = n / (double)accumulate(a.begin(), a.end(), 0LL);
  ;
  cout << fixed << setprecision(20);
  cout << a[0] * D << " ";
  cout << a[1] * D << " ";
  cout << a[2] * D;
  return 0;
}
