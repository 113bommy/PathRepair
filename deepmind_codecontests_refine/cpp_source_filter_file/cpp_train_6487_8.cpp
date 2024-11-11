#include <bits/stdc++.h>
using namespace std;
long long q;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  if (k < n && k != 1) {
    if (k % 2 == 0)
      cout << m << endl;
    else
      cout << m * m << endl;
  } else if (k == 1 && k > n) {
    long long sum = 1;
    for (int i = 1; i <= n; i++) {
      sum *= m;
      sum %= 1000000007;
    }
    cout << sum << endl;
  } else {
    long long sum = 1;
    for (int i = 1; i <= (n + 1) / 2; i++) {
      sum *= m;
      sum %= 1000000007;
    }
    cout << sum << endl;
  }
}
