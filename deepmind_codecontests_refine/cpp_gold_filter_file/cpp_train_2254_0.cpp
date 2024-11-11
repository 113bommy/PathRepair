#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)1e6 + 100;
const int mod = (int)1e9 + 7;
const long long BIG = (long long)1e18 + 14;
int t, n, cnt[29];
string second, ans;
int main() {
  cin >> t;
  for (int tt = (1); tt <= (t); ++tt) {
    cin >> second;
    ans = "";
    n = ((int)(second).size());
    second = '+' + second;
    memset(cnt, 0, sizeof(cnt));
    for (auto c : second) cnt[c - '0']++;
    for (int i = (n); i >= (1); --i) {
      if (((int)(ans).size())) break;
      cnt[second[i] - '0']--;
      char ch = second[i];
      for (int cur = (ch - '0' - 1); cur >= (0); --cur) {
        if (i == 1 && !cur) break;
        cnt[cur]++;
        second[i] = char(cur + '0');
        vector<int> add;
        int del = n - i;
        for (int dig = (0); dig <= (9); ++dig)
          if (cnt[dig] % 2) add.push_back(dig);
        if (((int)(add).size()) <= del &&
            (del - ((int)(add).size())) % 2 == 0) {
          int cnt9 = del - ((int)(add).size()), pos = 0;
          for (int j = (n); j >= (i + 1); --j) {
            if (pos < ((int)(add).size()))
              second[j] = char(add[pos++] + '0');
            else
              second[j] = '9';
          }
          ans = second;
          break;
        }
        cnt[cur]--;
      }
      second[i] = ch;
    }
    if (!((int)(ans).size()))
      for (int i = (1); i <= (n - 1); ++i) ans += '9';
    ans.erase(ans.begin());
    cout << ans << endl;
  }
}
