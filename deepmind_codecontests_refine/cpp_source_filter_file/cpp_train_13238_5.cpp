#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long a, n, m, sum = 0;
  cin >> n >> m;
  priority_queue<int> q;
  stack<int> k;
  while (n--) {
    cin >> a;
    if (sum + a <= m) {
      cout << k.size() << " ";
      q.push(a);
      sum += a;
    } else {
      while (sum + a > m) {
        int tmp = q.top();
        q.pop();
        k.push(tmp);
        sum -= tmp;
      }
      cout << k.size() << " ";
      while (!k.empty() && sum > m && k.top() <= a) {
        int tmp = k.top();
        k.pop();
        q.push(tmp);
        sum += tmp;
      }
      sum += a;
      q.push(a);
    }
  }
  return 0;
}
