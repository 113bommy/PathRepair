#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long T, n, a[N];
priority_queue<long long> q;
multiset<long long> s;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  long long res = 0, cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (!q.empty() && -q.top() < a[i]) {
      long long val = -q.top();
      res += a[i] - val;
      cnt++;
      s.insert(a[i]);
      if (s.find(val) != s.end()) {
        s.erase(s.find(val));
        q.push(-val);
        cnt--;
      }
      q.pop();
    }
    q.push(-a[i]);
  }
  cout << res << '\n';
  return 0;
}
