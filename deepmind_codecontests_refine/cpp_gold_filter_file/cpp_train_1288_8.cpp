#include <bits/stdc++.h>
using namespace std;
long long int expo(long long int n) {
  long long int t;
  if (n == 0)
    return 1;
  else if (n == 1)
    return 2;
  t = expo(n / 2);
  if (n % 2) {
    return t * t * 2;
  } else
    return t * t;
}
long long int exponentMod(long long int A, long long int B, long long int C) {
  if (A == 0) return 0;
  if (B == 0) return 1;
  long long int y;
  if (B % 2 == 0) {
    y = exponentMod(A, B / 2, C);
    y = (y * y) % C;
  } else {
    y = A % C;
    y = (y * exponentMod(A, B - 1, C) % C) % C;
  }
  return (long long int)((y + C) % C);
}
int main() {
  long long int n, k;
  cin >> n >> k;
  if (3 * k > n) {
    cout << "-1\n";
  } else {
    long long int p = n - 3 * k;
    for (int i = 1; i <= k; i++) {
      cout << i << " " << i << " ";
    }
    for (int i = 1; i <= k; i++) {
      cout << i << " ";
    }
    for (int i = 0; i < p; i++) {
      cout << (i) % (k) + 1 << " ";
    }
  }
}
