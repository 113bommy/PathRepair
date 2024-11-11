#include <bits/stdc++.h>
using namespace std;
const int N = (1 << 20) + 5;
const int mod = 10007;
int a[N];
priority_queue<int, vector<int>, greater<int> > q;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int p = n >> 1;
  long long ans = 0;
  int now = n;
  q.push(a[n]);
  if (a[n] == -1) {
    puts("0");
    return 0;
  }
  while (1) {
    ans += q.top();
    q.pop();
    int t = p;
    while (t--) {
      now--;
      if (a[now] == -1) {
        printf("%lld", ans);
        return 0;
      }
      q.push(a[now]);
    }
    p >>= 1;
  }
  return 0;
}
