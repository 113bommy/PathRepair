#include <bits/stdc++.h>
using namespace std;
int divisors(int n, int x) {
  int d1, d2;
  if (n <= x) {
    d1 = n;
    d2 = x;
  } else {
    d1 = x;
    d2 = n;
  }
  int loop = sqrt(d1);
  for (int i = loop; i >= 2; i--) {
    if (d1 % i == 0 && d2 % i == 0) {
      return i;
    }
  }
  return 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int sum = 0;
  for (int i = 2; i <= n - 1; i++) {
    int t = n;
    while (t > 0) {
      int p = t % i;
      sum += p;
      t /= i;
    }
  }
  int divi = divisors(sum, n - 2);
  cout << sum / divi << "/" << (n - 2) / divi << endl;
}
