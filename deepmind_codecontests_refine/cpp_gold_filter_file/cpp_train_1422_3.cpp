#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9;
const int mod = (int)1e9 + 7;
const int MAXN = (int)3e5 + 5;
void solve() {
  int n;
  long double t;
  cin >> n >> t;
  pair<long long, long long> arr[n];
  long double tmp = 0;
  long double ml = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i].first;
    ml += arr[i].first;
  }
  for (int i = 0; i < n; i++) {
    cin >> arr[i].second;
    tmp += arr[i].first * arr[i].second;
    swap(arr[i].first, arr[i].second);
  }
  sort(arr, arr + n);
  long double a = 1000000000000;
  a = (long double)1 / a;
  if (abs(t - (tmp / ml)) < a) {
    cout << fixed << setprecision(10) << ml;
    return;
  } else if (tmp / ml > t) {
    for (int i = n - 1; i >= 0; i--) {
      if ((tmp / ml) - t > a) {
        long double l = 0, r = arr[i].second;
        while (l < r) {
          long double m = (l + r) / 2;
          if (abs((tmp - m * arr[i].first) / (ml - m) - t) < a) {
            l = m;
            break;
          }
          if ((tmp - m * arr[i].first) / (ml - m) > t) {
            l = m + a;
          } else {
            r = m - a;
          }
        }
        tmp -= (l * arr[i].first);
        ml -= l;
      }
    }
  } else {
    for (int i = 0; i < n; i++) {
      if (t - (tmp / ml) > a) {
        long double l = 0, r = arr[i].second;
        while (l < r) {
          long double m = (l + r) / 2;
          if (abs(t - (tmp - m * arr[i].first) / (ml - m)) < a) {
            l = m;
            break;
          }
          if ((tmp - m * arr[i].first) / (ml - m) < t) {
            l = m + a;
          } else {
            r = m - a;
          }
        }
        tmp -= (l * arr[i].first);
        ml -= l;
      }
    }
  }
  cout << fixed << setprecision(10) << ml;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  while (t--) {
    solve();
  }
}
