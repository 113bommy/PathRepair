#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, a[1000005], n;
  long long int sum = 0;
  priority_queue<int, vector<int>, greater<int>> c;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (i = 0; i < n; i++) {
    c.push(a[i]);
    if (a[i] > c.top()) {
      sum += a[i] - c.top();
      c.pop();
      c.push(a[i]);
    }
  }
  cout << sum;
  return 0;
}
