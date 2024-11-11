#include <bits/stdc++.h>
using namespace std;
struct hlydl {
  int a;
  int h;
} t[200005];
bool cmp(hlydl x, hlydl y) { return x.a < y.a; }
int main() {
  int tt;
  cin >> tt;
  for (int ii = 1; ii <= tt; ii++) {
    memset(t, 0, sizeof(t));
    int minn = 999999999;
    int ans = 0;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> t[i].a, t[i].h = i;
    for (int i = n; i >= 1; i--)
      if (t[i].a < minn) minn = t[i].a, ans++;
    cout << ans << endl;
  }
  return 0;
}
