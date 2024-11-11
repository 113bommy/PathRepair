#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const int M = 128;
const int inf = 0x7fffffff;
const long long INF = 9E18;
const int mod = 1e9 + 7;
const int eps = 1e-7;
int a[maxn];
int main() {
  int n, pos;
  scanf("%d%d", &n, &pos);
  deque<int> dq;
  stack<int> s;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    if (a[i] != 0 && i + 1 == pos) a[i] = 0, ans++;
    if (a[i] == 0 && i + 1 != pos) a[i] = 0x3f3f3f;
  }
  sort(a, a + n);
  for (int i = 0; i < n; i++) dq.push_back(a[i]);
  while (!dq.empty()) {
    if (s.empty()) {
      s.push(dq.front());
      dq.pop_front();
    } else {
      int now = s.top();
      if (dq.front() - now > 1) {
        dq.pop_back();
        s.push(now + 1);
        ans++;
      } else {
        s.push(dq.front());
        dq.pop_front();
      }
    }
  }
  cout << ans << endl;
}
