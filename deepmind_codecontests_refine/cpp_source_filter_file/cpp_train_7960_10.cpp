#include <bits/stdc++.h>
using namespace std;
string word, ans = "";
bool cmp(int a, int b) { return a > b; }
void solve(char idx) {
  if (idx == '1')
    return;
  else if (idx == '2' || idx == '3' || idx == '5' || idx == '7')
    ans += idx;
  else if (idx == '4')
    ans += "223";
  else if (idx == '6')
    ans += "235";
  else if (idx == '8')
    ans += "22227";
  else if (idx == '9')
    ans += "22337";
}
int main() {
  int n;
  cin >> n >> word;
  for (int i = 0; i < n; i++) solve(word[i]);
  sort(ans.begin(), ans.end(), cmp);
  cout << ans;
  return 0;
}
