#include <bits/stdc++.h>
using namespace std;
int n, a[333], cnt[333];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", a + i);
  string ans = "";
  for (int i = 0; i + 1 < n; ++i) {
    int flag = 0;
    while (cnt[i] < a[i]) {
      if (ans.size() && ans[ans.size() - 1] == 'P') ans += "RL";
      flag = 1;
      ans += "PR";
      ++cnt[i];
      if (cnt[i + 1] < a[i + 1]) {
        ans += "P";
        ++cnt[i + 1];
      }
      if (cnt[i] < a[i]) {
        ans += "L";
        flag = 0;
      }
    }
    if (!flag) ans += "R";
  }
  if (ans[ans.size() - 1] == 'P') ans += "LR";
  while (cnt[n - 1] < a[n - 1]) {
    ans += "PLR";
    ++cnt[n - 1];
  }
  puts(ans.c_str());
  return 0;
}
