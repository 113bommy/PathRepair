#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  if (n == k) {
    long long count = 1;
    for (int i = 1; i <= (n + 1) / 2; i++) {
      count = count * m % 1000000007;
    }
    cout << count;
  } else {
    if (k == 1 || k > n) {
      long long count = 1;
      for (int i = 1; i <= n; i++) count = count * m % 1000000007;
      cout << count;
    } else {
      cout << pow(m, 1 + (k & 1));
    }
  }
}
