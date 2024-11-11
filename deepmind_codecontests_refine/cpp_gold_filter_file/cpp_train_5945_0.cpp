#include <bits/stdc++.h>
using namespace std;
set<int> factors(long long n) {
  set<int> fs;
  for (int i = sqrt(n) + 1 - 1; i >= 1; i--)
    if (n % i == 0) {
      fs.insert(-i);
      fs.insert(-n / i);
    }
  return fs;
}
int main() {
  ios::sync_with_stdio(false);
  long long a, b;
  cin >> a >> b;
  set<int> fa = factors(a), fb = factors(b);
  long long s = a + b;
  for (int i = sqrt(s) + 1 - 1; i >= 1; i--) {
    if (s % i == 0) {
      auto ai = fa.lower_bound(-i);
      auto bi = fb.lower_bound(-i);
      if ((ai != fa.end() && a / -*ai <= s / i) ||
          (bi != fb.end() && b / -*bi <= s / i)) {
        cout << 2 * (i + s / i) << endl;
        return 0;
      }
    }
  }
  return 0;
}
