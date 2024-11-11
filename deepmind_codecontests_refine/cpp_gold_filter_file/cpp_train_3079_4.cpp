#include <bits/stdc++.h>
const int MAXN = 1e5 + 5;
const int INF = 1e9 + 10;
const int mod = 1e9;
const int prime = 271;
using namespace std;
struct it {
  long long l, r, pos;
};
priority_queue<long long> p_q;
bool cmp(it a, it b) { return a.l < b.l; }
int main() {
  long long n, k, l, ans = 0;
  cin >> n >> k;
  vector<it> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].l >> a[i].r;
    a[i].pos = i + 1;
  }
  sort(a.begin(), a.end(), cmp);
  for (int i = 0; i < n; i++) {
    p_q.push(-a[i].r);
    if (p_q.size() > k) p_q.pop();
    if (p_q.size() == k && ans < -p_q.top() - a[i].l + 1) {
      ans = -p_q.top() - a[i].l + 1;
      l = a[i].l;
    }
  }
  if (!ans)
    for (int i = 0; i <= k; i++) cout << i << endl;
  else {
    cout << ans << endl;
    for (int i = 0; i < n && k; i++) {
      if (a[i].l <= l && (l + ans - 1) <= a[i].r) cout << a[i].pos << " ", k--;
    }
  }
  return 0;
}
