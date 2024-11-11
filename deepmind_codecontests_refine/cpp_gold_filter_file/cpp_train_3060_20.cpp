#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
const int MOD = 1e9 + 7;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
vector<int> all[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(10);
  long long n, l, t;
  while (cin >> n >> l >> t) {
    vector<long long> v(2 * n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      v[i + n] = v[i] + l;
    }
    double ans = 0, prob = 0.25;
    double full = t / l;
    t %= l;
    for (int it = 0; it < 2; it++) {
      for (int i = 0, j = 0, j1 = 0; i < n; i++) {
        ans += (n - 1) * 2 * prob * full;
        while (j - i < n && v[i] + 2 * t >= v[j]) j++;
        while (j1 - i < n && v[i] + 2 * (t - (l + 1) / 2) >= v[j1]) j1++;
        ans += max(0, j - i - 1) * prob;
        ans += max(0, j1 - i - 1) * prob;
      }
      reverse(v.begin(), v.end());
      for (int i = 0; i < 2 * n; i++) {
        v[i] = 2 * l - v[i];
      }
    }
    cout << ans / 2 << '\n';
  }
}
