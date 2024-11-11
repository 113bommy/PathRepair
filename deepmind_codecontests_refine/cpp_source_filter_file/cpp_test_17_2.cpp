#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
long long a[N], tr[N], n;
int lowbit(int x) { return x & -x; }
int sum(int x) {
  long long res = 0;
  for (int i = x; i; i -= lowbit(i)) res += tr[i];
  return res;
}
void add(int x, int c) {
  for (int i = x; i <= n; i += lowbit(i)) tr[i] += c;
}
void solve() {
  cin >> n;
  vector<int> q;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    q.push_back(a[i]);
  }
  sort(q.begin(), q.end());
  q.erase(unique(q.begin(), q.end()), q.end());
  for (int i = 1; i <= n; i++)
    a[i] = lower_bound(q.begin(), q.end(), a[i]) - q.begin() + 1;
  for (int i = 1; i <= n; i++) tr[i] = 0;
  int res = 0;
  for (int i = 1; i <= n; i++) {
    int head = sum(a[i] - 1), tail = sum(n) - sum(a[i]);
    if (head <= tail) {
      res += head;
      add(a[i], 1);
    } else {
      res += tail;
      add(a[i], 1);
    }
  }
  cout << res << "\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
