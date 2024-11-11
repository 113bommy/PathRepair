#include <bits/stdc++.h>
using namespace std;
struct node {
  int w, h;
  bool operator<(const node &q) const { return w - h > q.w - q.h; }
} a[1005], b[1005];
int main() {
  int n;
  cin >> n;
  long long ans = 1000000000;
  for (int i = 0; i < n; i++) cin >> b[i].w >> b[i].h;
  for (int j = 1; j <= 1010; j++) {
    int cnt = 0, flag = 1;
    memcpy(a, b, sizeof b);
    for (int i = 0; i < n; i++) {
      if (a[i].h > j && a[i].w > j) {
        flag = 0;
        break;
      } else if (a[i].h > j) {
        swap(a[i].w, a[i].h);
        cnt++;
      }
    }
    if (flag == 0 || cnt * 2 > n) continue;
    sort(a, a + n);
    for (int i = 0; i < n && (cnt + 1) * 2 <= n; i++) {
      if (a[i].w > a[i].h && a[i].w <= j) {
        swap(a[i].w, a[i].h);
        cnt++;
      }
    }
    long long temp = 0;
    for (int i = 0; i < n; i++) temp += a[i].w;
    temp *= j;
    ans = min(ans, temp);
  }
  cout << ans << endl;
  return 0;
}
