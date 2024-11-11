#include <bits/stdc++.h>
using namespace std;
const int N = 364000;
const int MOD = 1000000007;
priority_queue<int> Q1, Q2;
set<int> S;
int main() {
  int res = 1, n, x;
  char cmd[10];
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s %d", cmd, &x);
    if (cmd[1] == 'D') {
      if (!Q1.empty() && Q1.top() > x)
        Q1.push(x);
      else if (!Q2.empty() && -Q2.top() < x)
        Q2.push(-x);
      else
        S.insert(x);
    } else {
      if (S.count(x))
        res = res * 2 % MOD;
      else if (!Q1.empty() && Q1.top() == x)
        Q1.pop();
      else if (!Q2.empty() && -Q2.top() == x)
        Q2.pop();
      else {
        res = 0;
        break;
      }
      for (set<int>::iterator itr = S.begin(); itr != S.end(); itr++)
        if (*itr < x)
          Q1.push(*itr);
        else if (*itr > x)
          Q2.push(-*itr);
      S.clear();
    }
  }
  res = 1LL * res * (S.size() + 1) % MOD;
  cout << res << endl;
  return 0;
}
