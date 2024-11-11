#include <bits/stdc++.h>
using namespace std;
char s[100005];
int cnt[33], sum[33], bit[33];
stack<char> sta;
string ans = "";
int get(int x) {
  int res = 0;
  while (x >= 1) {
    res += bit[x];
    x -= x & (-x);
  }
  return res;
}
void add(int x) {
  while (x <= 26) {
    bit[x]++;
    x += x & (-x);
  }
}
int main() {
  scanf("%s", s + 1);
  for (int i = 1; s[i]; ++i) cnt[s[i] - 'a']++;
  for (int i = 2; i <= 26; ++i) sum[i] = sum[i - 1] + cnt[i - 2];
  for (int i = 1; s[i]; ++i) {
    sta.push(s[i]);
    add(s[i] - 'a' + 1);
    while (!sta.empty() && get(sta.top() - 'a') == sum[sta.top() - 'a' + 1])
      ans += sta.top(), sta.pop();
  }
  while (!sta.empty()) ans += sta.top(), sta.pop();
  cout << ans << endl;
  return 0;
}
