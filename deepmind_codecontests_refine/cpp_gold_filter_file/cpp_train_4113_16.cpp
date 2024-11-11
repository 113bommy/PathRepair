#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6;
int arr[maxn];
struct team {
  int x, y, val;
} ans[maxn];
bool cmp(team n, team m) { return n.val > m.val; }
int main() {
  int n;
  while (cin >> n) {
    n <<= 1;
    int ct = 0;
    for (int i = 2; i <= n; i++) {
      for (int j = 1; j < i; j++) {
        cin >> ans[++ct].val;
        ans[ct].x = i, ans[ct].y = j;
      }
    }
    sort(ans + 1, ans + 1 + ct, cmp);
    fill(arr, arr + maxn, 0);
    for (int i = 1; i <= ct; i++) {
      int x = ans[i].x, y = ans[i].y;
      if (arr[x] || arr[y]) continue;
      arr[x] = y, arr[y] = x;
    }
    for (int i = 1; i <= n; i++) {
      cout << arr[i] << (i == n ? '\n' : ' ');
    }
  }
  return 0;
}
