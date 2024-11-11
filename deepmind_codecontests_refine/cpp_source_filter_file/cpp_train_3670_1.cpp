#include <bits/stdc++.h>
using namespace std;
int ar[505], br[505];
char ch[505];
int n, m;
void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &ar[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &br[i]);
  if (n & 1 && ar[n / 2 + 1] != br[n / 2 + 1]) {
    printf("No\n");
    return;
  }
  map<pair<int, int>, int> mp;
  for (int i = 1; i <= n / 2; i++) {
    if (ar[i] > ar[n - i + 1]) swap(ar[i], ar[n - i + 1]);
    mp[{ar[i], ar[n - i + 1]}]++;
  }
  for (int i = 1; i <= n / 2; i++) {
    if (br[i] > br[n - i + 1]) swap(br[i], br[n - i + 1]);
    if (mp[{ar[i], ar[n - i + 1]}] == 0) {
      printf("No\n");
      return;
    }
    mp[{ar[i], ar[n - i + 1]}]--;
  }
  printf("Yes\n");
}
int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
