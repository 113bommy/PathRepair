#include <bits/stdc++.h>
using namespace std;
bool solve(int n, int s) {
  long long sum = n * 1ll * (n + 1) / 2;
  if (sum < s) return false;
  return sum % 2 == s % 2;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    int d = abs(a - b);
    if (d == 0) {
      cout << "0\n";
      continue;
    }
    int cnt = 1;
    while (solve(cnt, d)) cnt++;
    cout << cnt << endl;
  }
  return 0;
}
