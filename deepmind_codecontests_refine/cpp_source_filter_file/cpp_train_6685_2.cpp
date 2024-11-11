#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
pair<long long, long long> p[maxn << 1];
int cnt[maxn << 1];
int n;
int main() {
  int t;
  cin >> t;
  while (t--) {
    multiset<int> s;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      long long l, r;
      cin >> l >> r;
      p[2 * i - 1] = make_pair(l, -i);
      p[2 * i] = make_pair(r, i);
      cnt[i] = 0;
    }
    sort(p + 1, p + 2 * n + 1);
    int ans = 0;
    for (int i = 1; i <= 2 * n; i++) {
      if (p[i].second < 0)
        s.insert(-p[i].second);
      else
        s.erase(s.find(p[i].second));
      if (s.size() == 0) ans++;
      if (s.size() == 1 && p[i + 1].first != p[i].first && p[i].second > 0 &&
          p[i + 1].second < 0)
        cnt[*s.begin()]++;
      if (s.size() == 1 && p[i].second < 0 && p[i + 1].second > 0)
        cnt[*s.begin()]--;
    }
    int temp = -1;
    for (int i = 1; i <= n; i++) {
      t = max(t, cnt[i]);
    }
    cout << ans + temp << endl;
  }
  return 0;
}
