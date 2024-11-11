#include <bits/stdc++.h>
using namespace std;
int fen[1001000], cnt, b[1001000];
pair<pair<int, int>, int> a[1001000];
map<int, int> mp;
void add(int val, int x) {
  for (; x; x -= x & -x) fen[x] = max(fen[x], val);
}
int get(int x) {
  int ans = 0;
  for (; x < 1001000; x += x & -x) ans = max(fen[x], ans);
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  int n, ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i].first.first;
  for (int i = 0; i < n; i++)
    cin >> a[i].first.second, b[i] = a[i].first.second;
  for (int i = 0; i < n; i++) cin >> a[i].second;
  sort(b, b + n);
  for (int i = 0; i < n; i++)
    if (!mp[b[i]]) mp[b[i]] = ++cnt;
  sort(a, a + n);
  reverse(a, a + n);
  for (int i = 0; i < n; i++) {
    int k = i;
    while (k < n && a[k].first.first == a[i].first.first) {
      if (get(mp[a[k].first.second]) > a[k].second) ans++;
      k++;
    }
    k = i;
    while (i < n && a[i].first.first == a[k].first.first)
      add(a[i].second, mp[a[i].first.second]), i++;
    i--;
  }
  cout << ans << endl;
  return 0;
}
