#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 5;
const long long linf = 1e18 + 5;
const int N = 1000 + 5;
int n;
bool h[N];
pair<int, int> a[N];
int main() {
  ios ::sync_with_stdio(0);
  cin >> n;
  long long ans = linf;
  for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
  for (int i = 1; i <= 1000; i++) {
    memset(h, 0, sizeof(h));
    int cnt = 0;
    long long sum = 0;
    bool flag = 1;
    for (int j = 1; j <= n; j++) {
      if (a[j].second > i) {
        flag &= a[j].first <= i;
        cnt++;
        sum += a[j].second;
      } else {
        sum += a[j].first;
        h[j] = 1;
      }
    }
    if (flag and cnt <= n / 2) {
      vector<int> v;
      for (int j = 1; j <= n; j++)
        if (h[j] and a[j].first <= i and a[j].second < a[j].first)
          v.push_back(a[j].first - a[j].second);
      sort(v.begin(), v.end());
      reverse(v.begin(), v.end());
      for (int j = 0; j <= min((int)v.size() - 1, n / 2 - cnt); j++)
        sum -= v[j];
      ans = min(ans, sum * i);
    }
  }
  cout << ans << '\n';
  return 0;
}
