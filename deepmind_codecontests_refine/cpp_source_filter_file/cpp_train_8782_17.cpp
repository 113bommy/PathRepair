#include <bits/stdc++.h>
using namespace std;
int main() {
  priority_queue<int> b;
  int n, x, skid = 10000000;
  long long sum = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    if (x < skid) skid = x;
  }
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    b.push(x);
  }
  while (b.size() > skid) {
    for (int i = 1; i <= skid; ++i) {
      sum += b.top();
      b.pop();
    }
    for (int i = 1; (i <= 2 && b.size() > 0); ++i) b.pop();
  }
  if (b.size() > 0) {
    sum += b.top();
    b.pop();
  }
  cout << sum;
  return 0;
}
