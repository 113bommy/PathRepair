#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
int a[maxn], ans[maxn], cnt, maxi, s, idx;
bool mark[maxn];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    if (i == 1 or i == n) mark[i] = true;
    if (a[i] == a[i - 1]) mark[i] = true, mark[i - 1] = true;
  }
  for (int i = 1; i <= n; i++) {
    if (mark[i] == false)
      s++;
    else
      maxi = max(s, maxi), s = 0;
  }
  cout << maxi / 2 + (maxi % 2) << endl;
  for (int i = 1; i <= n; i++) {
    if (mark[i] == false)
      cnt++;
    else {
      if (idx != 0 and mark[i - 1] == false) {
        for (int j = idx; j <= idx + (cnt / 2); j++) ans[j] = a[idx];
        for (int j = idx + (cnt / 2); j < i; j++) ans[j] = a[i];
      }
      cnt = 0;
      idx = i;
      ans[i] = a[i];
    }
  }
  for (int i = 1; i <= n; i++) cout << ans[i] << " ";
  return (cout << endl, 0);
}
