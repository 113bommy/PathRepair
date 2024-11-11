#include <bits/stdc++.h>
using namespace std;
long long n, a[1000005], now = 0, res[1000005];
stack<long long> second;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  for (long long i = 1; i <= n; i++) {
    if (now < a[i]) {
      res[i] = now;
      now++;
      while (!second.empty() && now < a[i]) {
        res[second.top()] = now;
        second.pop();
        now++;
      }
    } else {
      second.push(i);
    }
  }
  now--;
  while (!second.empty()) {
    res[second.top()] = now;
    second.pop();
  }
  for (long long i = 1; i <= n; i++) cout << res[i] << " ";
  return 0;
}
