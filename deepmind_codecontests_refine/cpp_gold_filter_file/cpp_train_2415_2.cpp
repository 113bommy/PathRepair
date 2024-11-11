#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  while (cin >> n) {
    if (n == 1) {
      cout << "1\n";
      continue;
    }
    vector<long long> p;
    for (int i = 2; (long long)i * i <= n && n > 1; i++) {
      if (n % i) continue;
      p.push_back(i);
      while (n % i == 0) n /= i;
    }
    if (n > 1) {
      p.push_back(n);
    }
    if (p.size() != 1) {
      cout << "1\n";
    } else {
      cout << p[0] << '\n';
    }
  }
  return 0;
}
