#include <bits/stdc++.h>
using namespace std;
long long gcd(int a, int b) {
  if (!b) return a;
  return gcd(b, a % b);
}
int main() {
  long long n, k;
  cin >> n >> k;
  long long a = 1;
  long long b = n * (k - 1) + 1;
  long long val = b;
  long long sum = 0;
  for (int(i) = (0); (i) < (n); (i)++) {
    sum += val;
    val = val + n - k + 1;
  }
  cout << sum << endl;
  for (int(i) = (0); (i) < (n); (i)++) {
    for (int(j) = (0); (j) < (n); (j)++) {
      if (j < k - 1) {
        cout << a << " ";
        a++;
      } else {
        cout << b << " ";
        b++;
      }
    }
    cout << endl;
  }
  return 0;
}
