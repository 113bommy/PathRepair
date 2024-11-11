#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
  if (a.first.first != b.first.first) return a.first.first > b.first.first;
  return a.second < b.second;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> vec(n), ans(n);
  for (int i = 0; i < n; i++) cin >> vec[i];
  vector<pair<pair<int, int>, int>> sec(q);
  for (int i = 0; i < q; i++)
    cin >> sec[i].first.second >> sec[i].first.first, sec[i].second = i;
  sort(sec.begin(), sec.end(), cmp);
  for (int i = n - 1; i >= sec[0].first.first; i--) ans[i] = vec[i];
  multiset<int> st;
  for (int i = 0; i < sec[0].first.first; i++) st.insert(vec[i]);
  if (st.size()) {
    bool rev;
    int b = 0, mx = 0;
    for (int i = sec[0].first.first; i; i--) {
      while (b < q && sec[b].first.first == i) {
        if (mx <= sec[b].second) rev = sec[b].first.second == 1;
        mx = max(mx, sec[b].second);
        b++;
      }
      auto it = st.end();
      it--;
      if (rev)
        ans[i - 1] = *it, st.erase(it);
      else
        ans[i - 1] = *st.begin(), st.erase(st.begin());
    }
  }
  for (int i = 0; i < n; i++) cout << ans[i] << " ";
  cout << "\n";
  return 0;
}
