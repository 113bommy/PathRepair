#include <bits/stdc++.h>
using namespace std;
long long int get(long long int x) {
  long long int y = 1, ans = 0;
  while (y < x) {
    y = y * 2;
    if (y <= x)
      ans++;
    else
      break;
  }
  return ans;
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    long long int n, m, k, a = 0, b = 0, ans = 1, x = 0, y = 0;
    cin >> a >> b >> m;
    if (a == b) {
      cout << "1 " << a << "\n";
      continue;
    }
    n = get(b / (a + 1));
    long long int arr[51] = {};
    long long int rem = b - (1ll << n) * (a + 1);
    long long int cur = a + 1, sum = a;
    vector<long long int> sol;
    sol.push_back(n + 2);
    sol.push_back(a);
    for (int i = 0; i < n; i++) {
      x = (1ll << (n - i - 1));
      if (rem >= x) {
        k = min(m - 1, rem / x);
        rem -= k * x;
        cur += k;
      }
      sol.push_back(cur);
      sum += cur;
      cur = sum + 1;
    }
    if (rem >= 0 && rem < m) {
      sol.push_back(cur + rem);
      for (auto i : sol) cout << i << " ";
    } else {
      cout << "-1";
    }
    cout << "\n";
  }
  return 0;
}
