#include <bits/stdc++.h>
using namespace std;
long long run(long long x) { return x; }
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  long long sum = (n + 1) * n / 2;
  for (long long i = 1; i <= n; i++) {
    char ch = s[i - 1];
    if ((ch - '0') % 2 != 0) {
      sum -= run(i);
    }
  }
  cout << sum << endl;
  return 0;
}
