#include <bits/stdc++.h>
using namespace std;
struct sd {
  int a;
  int p;
};
const int maxn = 100005;
int n, cnt, first, ans;
sd d[maxn];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> d[i].a >> d[i].p;
    if (i != 0) {
      if (d[i].p >= d[i - 1].p) {
        cnt += d[i].a;
      } else {
        ans += first * cnt;
        cnt = d[i].a;
        first = d[i].p;
      }
    } else {
      cnt = d[i].a;
      first = d[i].p;
    }
  }
  ans += first * cnt;
  cout << ans;
}
