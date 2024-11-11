#include <bits/stdc++.h>
using namespace std;
int a[1000100];
stack<pair<int, int> > Box;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  long long ans = 0;
  int mx = 0;
  for (int i = 0; i < n; i++) {
    mx = max(mx, a[i]);
    ans += mx - a[i];
    int x = i - mx;
    int cnt = 1;
    if (!Box.empty() && Box.top().first >= x) {
      ans += (Box.top().first - x) * Box.top().second;
      cnt += Box.top().second;
      Box.pop();
    }
    Box.push(make_pair(x, cnt));
  }
  printf("%I64d\n", ans);
}
