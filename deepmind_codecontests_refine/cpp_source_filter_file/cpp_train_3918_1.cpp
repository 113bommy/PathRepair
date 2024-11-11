#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2 * 1e5 + 10;
long long n;
long long sum = 0;
priority_queue<long long, vector<long long>, greater<long long> > q;
int main() {
  std::ios::sync_with_stdio(false);
  cin >> n;
  for (long long i = 0; i < n; i++) {
    long long in;
    cin >> in;
    q.push(in);
  }
  if (n == 1) {
    cout << q.top() << endl;
    return 0;
  }
  int flag = 0;
  while (1) {
    if (!flag && n % 2 == 0) {
      flag = 1;
      long long a = q.top();
      q.pop();
      long long b = q.top();
      q.pop();
      sum += (a + b);
      if (n == 2) break;
      q.push(a + b);
    } else {
      int num = 0;
      long long cnt = 0;
      while (!q.empty() && num < 3) {
        num++;
        cnt += q.top();
        q.pop();
      }
      sum += cnt;
      if (q.empty()) break;
      q.push(cnt);
    }
  }
  cout << sum << endl;
}
