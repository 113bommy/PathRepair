#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long m[n];
  for (int i = 0; i < n; i++) cin >> m[i];
  long long l[n];
  long long r[n];
  l[0] = m[0];
  stack<int> lst;
  lst.push(0);
  for (int i = 1; i < n; i++) {
    while (!lst.empty() and m[lst.top()] > m[i]) {
      lst.pop();
    }
    if (lst.empty()) {
      l[i] = (i + 1) * m[i];
    } else {
      int j = lst.top();
      l[i] = l[j] + m[i] * (i - j);
    }
    lst.push(i);
  }
  reverse(m, m + n);
  r[0] = m[0];
  stack<int> rst;
  rst.push(0);
  for (int i = 1; i < n; i++) {
    while (!rst.empty() and m[rst.top()] > m[i]) {
      rst.pop();
    }
    if (rst.empty()) {
      r[i] = (i + 1) * m[i];
    } else {
      int j = rst.top();
      r[i] = r[j] + m[i] * (i - j);
    }
    rst.push(i);
  }
  reverse(m, m + n);
  reverse(r, r + n);
  long long max_val = INT_MIN;
  int max_idx = 0;
  for (int i = 0; i < n; i++) {
    if (l[i] + r[i] - m[i] > max_val) {
      max_val = l[i] + r[i] - m[i];
      max_idx = i;
    }
  }
  for (int i = max_idx + 1; i < n; i++) m[i] = min(m[i - 1], m[i]);
  for (int i = max_idx - 1; i >= 0; i--) m[i] = min(m[i + 1], m[i]);
  for (int i = 0; i < n; i++) cout << m[i] << " ";
}
