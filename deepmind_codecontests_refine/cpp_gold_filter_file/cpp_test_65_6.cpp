#include <bits/stdc++.h>
using namespace std;
int n, a[200005];
string str;
pair<int, int> ans[200005];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  sort(a, a + n);
  cin >> str;
  int now = n - 1, l = 0, r = n - 1;
  while (now >= 0) {
    if (now == 0) {
      ans[now] = pair<int, int>(a[l], str[now] == 'L' ? 0 : 1);
      break;
    }
    if (str[now] != str[now - 1]) {
      ans[now] = pair<int, int>(a[r], str[now] == 'L' ? 0 : 1);
      now--;
      r--;
    } else {
      if (now == 1 || str[now] == str[now - 2]) {
        ans[now - 1] = pair<int, int>(a[r], str[now] == 'L' ? 0 : 1);
        ans[now] = pair<int, int>(a[r - 1], str[now] == 'L' ? 1 : 0);
        now -= 2;
        r -= 2;
      } else if ((r - l + 1) & 1) {
        ans[now - 1] = pair<int, int>(a[r], str[now] == 'L' ? 0 : 1);
        ans[now] = pair<int, int>(a[l], str[now] == 'L' ? 0 : 1);
        now -= 2;
        r--;
        l++;
      } else {
        ans[now - 1] = pair<int, int>(a[r], str[now] == 'L' ? 0 : 1);
        ans[now] = pair<int, int>(a[l], str[now] == 'L' ? 1 : 0);
        now -= 2;
        r--;
        l++;
      }
    }
  }
  for (int i = 0; i < n; i++)
    printf("%d %c\n", ans[i].first, ans[i].second ? 'R' : 'L');
  return 0;
}
