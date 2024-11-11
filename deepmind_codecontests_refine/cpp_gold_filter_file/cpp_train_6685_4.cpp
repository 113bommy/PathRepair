#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5 + 7;
int n;
pair<int, int> a[maxn];
int ans[maxn];
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int l, r;
    cin >> l >> r;
    a[2 * i - 1] = make_pair(l, -i);
    a[2 * i] = make_pair(r, i);
    ans[i] = 0;
  }
  sort(a + 1, a + 2 * n + 1);
  multiset<int> s;
  int c = 0;
  for (int i = 1; i <= 2 * n; i++) {
    if (a[i].second < 0) {
      s.insert(-a[i].second);
    } else {
      s.erase(s.find(a[i].second));
    }
    if (s.size() == 0) {
      c++;
    }
    if (s.size() == 1 && a[i].second > 0 && a[i + 1].second < 0 &&
        a[i + 1].first > a[i].first) {
      ans[*s.begin()]++;
    }
    if (s.size() == 1 && a[i].second < 0 && a[i + 1].second > 0)
      ans[*s.begin()] = -1;
  }
  int Ans = -n;
  for (int i = 1; i <= n; i++) Ans = max(Ans, ans[i]);
  cout << c + Ans << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
