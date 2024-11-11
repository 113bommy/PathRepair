#include <bits/stdc++.h>
using namespace std;
long long a[1000006];
long long l[1000006];
long long r[1000006];
long long n;
void compute() {
  stack<int> s;
  for (int i = 0; i < n; ++i) {
    while (!s.empty() && a[i] <= a[s.top()]) s.pop();
    if (s.empty())
      l[i] = -1;
    else
      l[i] = s.top();
    s.push(i);
  }
  while (s.size()) s.pop();
  for (int i = n - 1; i >= 0; --i) {
    while (!s.empty() && a[i] < a[s.top()]) s.pop();
    if (s.empty())
      r[i] = n;
    else
      r[i] = s.top();
    s.push(i);
  }
  while (s.size()) s.pop();
}
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  long long ans = 0;
  compute();
  for (int i = 0; i < n; ++i) {
    ans -= ((i - l[i]) * (r[i] - i)) * a[i];
  }
  for (int i = 0; i < n; ++i) a[i] = -1 * a[i];
  compute();
  for (int i = 0; i < n; ++i) {
    ans += ((i - l[i]) * (r[i] - i)) * (-1 * a[i]);
  }
  cout << ans << endl;
}
