#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long mod = 1e9 + 7;
const int N = (1 << 18) + 5;
int a[N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  int wc = n, t = 1;
  long long ans = 0;
  priority_queue<int, vector<int>, greater<int>> q;
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] == -1) break;
    q.push(a[i]);
    t--;
    if (t == 0) {
      ans += q.top();
      q.pop();
      wc /= 2;
      t = wc;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
