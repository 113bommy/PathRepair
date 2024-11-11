#include <bits/stdc++.h>
using namespace std;
inline long long rel() {
  long long x;
  cin >> x;
  return x;
}
inline int rei() {
  int x;
  cin >> x;
  return x;
}
inline string res() {
  string x;
  cin >> x;
  return x;
}
long long c[100005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n = rei();
  string s = res();
  for (int i = 0; i <= n - 1; i++) cin >> c[i];
  long long h, ha, har, hard, ans;
  h = ha = har = hard = ans = 0;
  for (int i = 0; i <= n - 1; i++) {
    if (s[i] == 'h')
      h = h + c[i];
    else if (s[i] == 'a')
      ha = min(h, ha + c[i]);
    else if (s[i] == 'r')
      har = min(h, min(ha, har + c[i]));
    else if (s[i] == 'd')
      hard = min(min(h, ha), min(har, hard + c[i]));
    ans = max(hard, ans);
  }
  cout << ans;
}
