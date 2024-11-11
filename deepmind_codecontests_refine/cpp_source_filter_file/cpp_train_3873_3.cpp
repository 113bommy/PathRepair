#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
long long n, k, mx = 0, mn = 1e9;
map<char, int> mp;
long long a[N];
void solve() {
  int n;
  mp.clear();
  string a, s;
  cin >> n >> a >> s;
  for (int i = 0; i < n; i++) {
    mp[a[i]]++;
    mp[s[i]]++;
  }
  bool q = 0;
  for (auto x : mp) {
    if (x.second % 2) {
      q = 1;
    }
  }
  if (q) {
    printf("No\n");
    return;
  }
  int cnt = 0;
  vector<pair<int, int> > v;
  for (int i = 0; i < n; i++) {
    if (a[i] == s[i]) continue;
    for (int j = i + 1; j < n; j++) {
      if (a[i] == a[j]) {
        swap(a[i], s[j]);
        v.push_back({i + 1, j + 1});
        cnt++;
        break;
      } else if (a[i] == s[j]) {
        cnt += 2;
        swap(a[j], s[j]);
        swap(s[i], a[j]);
        v.push_back({j + 1, j + 1});
        v.push_back({j + 1, i + 1});
        break;
      }
    }
  }
  printf("Yes\n%d\n", cnt);
  for (auto x : v) {
    printf("%d %d\n", x.first, x.second);
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
