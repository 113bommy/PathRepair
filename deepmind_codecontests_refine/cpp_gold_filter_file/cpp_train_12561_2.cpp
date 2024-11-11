#include <bits/stdc++.h>
const int N = 1e6 + 5;
const int mod = 1e9 + 7;
const int MOD = mod - 1;
const int inf = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-10;
using namespace std;
int n;
int A, B;
int a[N], b[N];
priority_queue<int, vector<int>, greater<int>> q;
int main() {
  long long ans = 0;
  cin >> n >> A >> B;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    if (a[i] > b[i]) q.push(a[i] - b[i]);
  }
  for (int i = 0; i < n; i++) ans += b[i];
  while (q.size() > B) q.pop();
  if (!B) return 0 * printf("%lld\n", ans);
  long long tans = ans;
  for (int i = 0; i < n; i++) {
    long long x = a[i] * (1LL << A);
    if (q.size() && a[i] - b[i] >= q.top())
      tans = max(tans, ans - (a[i] - b[i]) + x - b[i]);
    else {
      if (q.size() < B)
        tans = max(tans, ans + x - b[i]);
      else
        tans = max(tans, ans - q.top() + x - b[i]);
    }
  }
  while (q.size()) {
    tans += q.top();
    q.pop();
  }
  printf("%lld\n", tans);
}
