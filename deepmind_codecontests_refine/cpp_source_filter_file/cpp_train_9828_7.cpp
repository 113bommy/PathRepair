#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
long long sum;
int n, tmp;
map<int, int> m;
priority_queue<int, vector<int>, greater<int> > q, q2;
int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    int x = read();
    sum += x;
    m[x]++;
  }
  for (map<int, int>::reverse_iterator i = m.rbegin(); i != m.rend(); i++) {
    int A = i->first, num = i->second;
    while (tmp && num) {
      tmp--;
      num--;
      q2.push(A);
    }
    while (num >= 2 && (!q.empty() && q.top() < 2 * A)) {
      if (q.top() < A)
        q2.push(A), q2.push(A);
      else
        q2.push(2 * A - q.top()), q2.push(q.top());
      num -= 2;
      q.pop();
    }
    while (num && !q.empty() && q.top() < A) q.pop(), q.push(A);
    while (!q2.empty()) q.push(q2.top()), q2.pop();
    tmp += num;
  }
  while (!q.empty()) {
    sum -= q.top();
    q.pop();
  }
  cout << sum << endl;
  return 0;
}
