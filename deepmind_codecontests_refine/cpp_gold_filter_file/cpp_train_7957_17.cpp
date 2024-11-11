#include <bits/stdc++.h>
using namespace std;
int k, w[31], ans, cnt, cur;
string s;
int main() {
  cin >> s >> k;
  for (int i = 1; i <= 26; i++) {
    cin >> w[i];
  }
  cur = s.size() + 1;
  for (int i = 0; i < s.size(); i++) {
    cnt = w[s[i] - 'a' + 1] * (i + 1);
    ans += cnt;
  }
  sort(w + 1, w + 27);
  for (int i = 1; i <= k; i++) {
    cnt = w[26] * cur;
    cur++;
    ans += cnt;
  }
  cout << ans;
}
