#include <bits/stdc++.h>
using namespace std;
const int MAX = 100005;
const int MOD = 1000000007;
int a[MAX];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    a[i] -= i;
  }
  reverse(a, a + n);
  priority_queue<int> pq;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      pq.push(-a[i]);
      continue;
    }
    if (a[i] < -pq.top()) {
      pq.push(-a[i]);
    } else {
      pq.push(-a[i]);
      pq.push(-a[i]);
      ans += abs(a[i] + pq.top());
      pq.pop();
    }
  }
  cout << ans << endl;
}
