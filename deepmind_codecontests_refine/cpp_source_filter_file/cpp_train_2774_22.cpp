#include <bits/stdc++.h>
using namespace std;
int main() {
  ios ::sync_with_stdio(0);
  cin.tie(0);
  long long n;
  int k;
  cin >> n >> k;
  long long n1 = 0, n2 = 0;
  long long mod = INT_MAX;
  for (int i = 0; i < k; ++i) {
    long long x;
    cin >> x;
    if (n % x < mod) {
      mod = n % x;
      n1 = i + 1;
      n2 = n / x;
    }
  }
  cout << n1 << ' ' << n2;
  return 0;
}
