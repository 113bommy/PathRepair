#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    k--;
    while (k--) {
      string x = to_string(n);
      sort(x.begin(), x.end());
      if (x[0] == '0') break;
      n = n + (x[0] - '0') * (x[x.size() - 1] - '0');
    }
    cout << n;
  }
}
