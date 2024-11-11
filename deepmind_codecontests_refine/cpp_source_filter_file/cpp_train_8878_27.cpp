#include <bits/stdc++.h>
using namespace std;
int a, ans = 1e6;
string b;
string mask(int a) {
  stringstream ss;
  ss << a;
  string s = ss.str();
  string ans = "";
  for (int i = 0; i < s.length(); i++)
    if (s[i] == '7' || s[i] == '4') ans += s[i];
  return ans;
}
void rec(int num) {
  if (num >= 1e5) return;
  if (mask(num) == b && num >= a) {
    ans = min(ans, num);
    return;
  }
  for (int i = 0; i <= 9; i++)
    if (num * 10 + i != 0) rec(num * 10 + i);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> a >> b;
  rec(0);
  cout << ans << endl;
  return 0;
}
