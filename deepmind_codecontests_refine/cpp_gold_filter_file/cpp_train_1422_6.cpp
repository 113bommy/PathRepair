#include <bits/stdc++.h>
using namespace std;
const int MaxN = 200005;
int n, t;
pair<int, int> a[MaxN];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> t;
  long long Sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first;
    Sum += a[i].first;
  }
  long long temp = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].second;
    temp += 1LL * a[i].first * a[i].second;
  }
  if (Sum * t == temp) {
    cout << Sum;
    return 0;
  }
  sort(a + 1, a + n + 1,
       [&](pair<int, int> x, pair<int, int> y) { return x.second < y.second; });
  if (temp > Sum * t) {
    reverse(a + 1, a + n + 1);
  }
  for (int i = 1; i <= n; i++) {
    temp -= 1LL * a[i].first * a[i].second;
    Sum -= a[i].first;
    long double part = (long double)(temp - t * Sum) / (t - a[i].second);
    if (part >= 0) {
      cout << fixed << setprecision(15) << Sum + part;
      return 0;
    }
  }
  Sum = 0;
  cout << fixed << setprecision(15) << Sum;
  return 0;
}
