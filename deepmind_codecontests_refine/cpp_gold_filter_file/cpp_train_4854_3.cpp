#include <bits/stdc++.h>
const int N = 3e5 + 10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
const double eps = 1e-9;
const double pi = acos(-1);
int main() {
  int n;
  scanf("%d", &n);
  long long ans = 0;
  priority_queue<int, vector<int>, greater<int> > q;
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    if (q.empty() || x <= q.top())
      q.push(x);
    else if (x > q.top()) {
      ans += x - q.top();
      q.pop();
      q.push(x);
      q.push(x);
    }
  }
  cout << ans << endl;
  return 0;
}
