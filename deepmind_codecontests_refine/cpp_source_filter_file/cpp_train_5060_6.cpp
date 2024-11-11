#include <bits/stdc++.h>
using namespace std;
int const lim = 2003;
int a[lim + 3], b[lim + 3], sum[lim + 3];
bool vis[10000000];
bool answer[10000000];
int bas = 4e6;
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < k; i++) scanf("%d", &b[i]);
  int ans = 0;
  sum[0] = a[0];
  vis[sum[0] + bas] = true;
  for (int i = 1; i < n; i++)
    sum[i] = sum[i - 1] + a[i], vis[sum[i] + bas] = true;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < k; j++) {
      bool shit = true;
      int con = b[j] - a[i];
      if (answer[con + bas]) continue;
      answer[con + bas] = true;
      for (int i = 0; i < k; i++) {
        if (!vis[b[i] - con + bas]) {
          shit = false;
          break;
        }
      }
      if (shit) ans++;
    }
  cout << ans << endl;
}
