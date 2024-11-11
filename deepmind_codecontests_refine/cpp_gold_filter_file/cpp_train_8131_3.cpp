#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  long long min;
  long long a[100010];
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  int flag = 0;
  queue<long long> b;
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    b.push(a[i]);
  }
  min = 0;
  long long t = 0;
  while (k--) {
    while (!b.empty() && b.front() == min) {
      b.pop();
    }
    if (!b.empty()) {
      min = b.front();
      cout << b.front() - t << endl;
      t = b.front();
      b.pop();
    } else
      cout << 0 << endl;
  }
  return 0;
}
