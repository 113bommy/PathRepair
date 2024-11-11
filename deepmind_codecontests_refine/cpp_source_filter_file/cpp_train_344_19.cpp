#include <bits/stdc++.h>
using namespace std;
int cnt[500];
int main() {
  string s, t;
  cin >> s >> t;
  int n = s.size();
  int i;
  for (i = 0; i < n; ++i) ++cnt[s[i]];
  string ans;
  int j;
  for (i = 0; i < n; ++i)
    if (cnt[t[i]] > 0) {
      ans += (char)t[i];
      --cnt[t[i]];
    } else {
      break;
    }
  if (i < n) {
    while (i >= 0) {
      for (j = t[i] + 1; j < 500; ++j)
        if (cnt[j] > 0) break;
      if (j < 500) {
        ans += (char)j;
        --cnt[j];
        for (i = 0; i < 500; ++i)
          while (cnt[i] > 0) {
            ans += (char)i;
            --cnt[i];
          }
        break;
      } else {
        --i;
        if (i >= 0) {
          ++cnt[t[i]];
          ans.erase(ans.begin() + ans.size() - 1);
        }
      }
    }
    if (i < 0)
      cout << -1 << endl;
    else
      cout << ans << endl;
  } else
    cout << ans << endl;
  return 0;
}
