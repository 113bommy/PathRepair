#include <bits/stdc++.h>
using namespace std;
int n;
int a[200005];
int b[200005];
int c[200005];
int x;
int ans;
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  ans = 2 * n;
  int i, j;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    c[a[i]] = 1;
  }
  deque<int> Q;
  for (i = 1; i <= n; i++) {
    cin >> b[i];
    Q.push_back(b[i]);
  }
  int cnt = 0;
  while (Q.front() != 1) {
    cnt++;
    if (c[Q.back() + 1] == 1) {
      c[Q.back() + 1] = 0;
      Q.push_back(Q.back() + 1);
    } else {
      break;
    }
    c[Q.front()] = 1;
    Q.pop_front();
  }
  for (i = 1; i <= n; i++) {
    if (Q.front() != i) break;
    Q.pop_front();
  }
  if (i == n + 1) ans = cnt;
  int k = 0;
  for (i = 1; i <= n; i++) {
    if (b[i]) k = max(k, i + 1 + n - b[i]);
  }
  if (k > 0) ans = min(ans, k);
  cout << ans;
  return 0;
}
