#include <bits/stdc++.h>
using namespace std;
const int N = int(3e5), mod = int(1e9) + 7;
int second[N], d[N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &second[i], &d[i]);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      pair<int, int> p1, p2, p3;
      int mx = 0;
      {
        int cnt = 0;
        p1 = make_pair(second[i], 0);
        p2 = make_pair(second[j], 1);
        p3 = make_pair(second[i] + d[i], 0);
        if ((p1 < p2 && p2 < p3) || (p1 > p2 && p2 > p3)) {
          cnt++;
        }
        p1 = p3;
        p3 = make_pair(second[j] + d[j], 1);
        if ((p2 < p1 && p1 < p3) || (p2 > p1 && p1 > p3)) {
          cnt++;
        }
        p2 = p3;
        mx = max(mx, cnt);
      }
      {
        int cnt = 0;
        p1 = make_pair(second[i], 1);
        p2 = make_pair(second[j], 0);
        p3 = make_pair(second[j] + d[j], 0);
        if ((p2 < p1 && p1 < p3) || (p2 > p1 && p1 > p3)) {
          cnt++;
        }
        p2 = p3;
        p3 = make_pair(second[i] + d[i], 1);
        if ((p1 < p2 && p2 < p3) || (p1 > p2 && p2 > p3)) {
          cnt++;
        }
        p1 = p3;
        mx = max(mx, cnt);
      }
      ans += mx;
    }
  }
  cout << ans;
  return 0;
}
