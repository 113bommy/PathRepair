#include <bits/stdc++.h>
using namespace std;
void file() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
}
int dx[8] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[8] = {0, 0, -1, 1, 1, -1, -1, 1};
int n, a, b, l, t, m, ans;
long long s[5000006], acc[5000006];
bool valid(int x) {
  long long qq = acc[l + x];
  if (l) {
    qq -= acc[l - 1];
  }
  bool f = (s[l + x] <= t && qq <= 1LL * t * m);
  if (f) {
    ans = max(ans, x + l + 1);
  }
  return f;
}
int main() {
  scanf("%d%d%d", &a, &b, &n);
  for (int i = 0; i < 5000006; i++) {
    s[i] = 1LL * (i)*b + a;
    acc[i] += acc[i - 1] + s[i];
  }
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d", &l, &t, &m);
    ans = -1;
    l--;
    int low = 0, high = 5000001 - l;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (high - low < 2) {
        valid(low);
        valid(high);
        break;
      }
      if (valid(mid)) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
