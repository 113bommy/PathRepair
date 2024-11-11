#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  if (n == 0 || n == 1) {
    cout << 0 << endl;
    return;
  }
  long long a[n];
  vector<int> pos;
  long long even = n / 2, odds = n - even;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] != 0) {
      if (a[i] & 1)
        odds--;
      else
        even--;
      pos.push_back(i);
    }
  }
  if (pos.size() == 0) {
    cout << 1 << endl;
    return;
  }
  vector<pair<int, int>> good;
  int bad = 0;
  for (int i = 1; i < pos.size(); ++i) {
    if (pos[i] - pos[i - 1] != 1) {
      if (a[pos[i]] % 2 == a[pos[i - 1]] % 2) {
        good.push_back({pos[i], pos[i - 1]});
      }
    }
    if (a[pos[i]] % 2 != a[pos[i - 1]] % 2) bad++;
  }
  sort(good.begin(), good.end(), [&](pair<int, int> a, pair<int, int> b) {
    return a.first - a.second < b.first - b.second;
  });
  long long ans = bad;
  for (auto i : good) {
    int k = i.first - i.second - 1;
    if (a[i.first] & 1 && odds >= k)
      odds -= k;
    else if (!(a[i.first] & 1) && even >= k)
      even -= k;
    else
      ans += 2;
  }
  if (a[0] == 0) {
    int cnt = 0;
    while (a[cnt] == 0) cnt++;
    if (a[cnt] & 1 && odds >= cnt)
      odds -= cnt;
    else if (!(a[cnt] & 1) && even >= cnt)
      even -= cnt;
    else
      ans += 2;
  }
  if (a[n - 1] == 0) {
    int cnt = 0, i = n - 1;
    while (a[i] == 0) cnt++, --i;
    if (!(a[i] & 1 && odds >= cnt || !(a[i] & 1) && even >= cnt)) ans++;
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}
