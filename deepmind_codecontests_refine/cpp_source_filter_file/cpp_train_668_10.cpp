#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
  string s;
  cin >> s;
  int n = s.length();
  vector<int> a(n);
  for (int i = 0; i < n; i++) a[i] = s[i] - 'a';
  long p[2] = {0, 0};
  long cnt[2][2] = {{0, 0}, {0, 0}};
  for (int i = 0; i < n; i++) {
    cnt[a[i]][i % 2]++;
    p[0] += cnt[a[i]][1 - (i % 2)];
    p[1] += cnt[a[i]][(i % 2)];
  }
  cout << p[0] << ' ' << p[1] << '\n';
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  solve();
  return 0;
}
