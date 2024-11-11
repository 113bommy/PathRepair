#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  s = '#' + s;
  int n = s.size();
  vector<int> pa(n + 3, 0);
  vector<int> pb(n + 3, 0);
  if (s[1] == 'a')
    pa[1]++;
  else
    pb[1]++;
  for (int i = 2; i <= n; i++) {
    if (s[i] == 'a') pa[i]++;
    pa[i] += pa[i - 1];
    if (s[i] == 'b') pb[i]++;
    pb[i] += pb[i - 1];
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      int a = pa[n] - pa[j] + pa[i];
      int b = pb[j] - pb[i];
      ans = max(a + b, ans);
    }
  }
  cout << ans << "\n";
  return 0;
}
