#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, x, count = 0;
  cin >> n >> x;
  for (long long i = 1; i < n; i++) {
    if (x % i == 0) {
      if (x / i <= n) count++;
    }
  }
  cout << count;
  return 0;
}
