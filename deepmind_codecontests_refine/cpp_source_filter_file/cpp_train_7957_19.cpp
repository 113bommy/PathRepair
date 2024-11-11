#include <bits/stdc++.h>
using namespace std;
int a[10001];
int ans, mx;
int main() {
  string s;
  cin >> s;
  int x = s.size();
  int n;
  cin >> n;
  for (int i = 'a'; i <= 'z'; i++) {
    cin >> a[i];
    mx = max(mx, a[i]);
  }
  for (int i = 1; i <= x; i++) {
    ans += i * a[s[i - 1]];
  }
  for (int i = n + 1; i <= n + x; i++) ans += i * mx;
  cout << ans;
}
