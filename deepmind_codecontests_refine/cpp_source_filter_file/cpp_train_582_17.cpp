#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
int n, m, k, sum;
string s;
int f[maxn], a[maxn];
priority_queue<int, vector<int>, greater<int> > q;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> m;
    if (!q.empty() && m > q.top()) {
      sum += (m - q.top());
      q.pop();
      q.push(m);
    }
    q.push(m);
  }
  cout << sum;
  return 0;
}
