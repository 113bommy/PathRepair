#include <bits/stdc++.h>
using namespace std;
int n, d, i;
bool rishe[100100];
vector<int> primes;
int pow1(int a, int b) {
  if (b == 0) return 1;
  long long c = pow1(a, b / 2);
  c = (c * c) % n;
  if (b % 2 == 1) c = (c * a) % n;
  return c;
}
int main() {
  cin >> n;
  if (n == 4) {
    cout << "YES"
         << "\n";
    cout << 1 << "\n" << 3 << "\n" << 2 << "\n" << 4;
  } else if (n == 1) {
    cout << "YES"
         << "\n";
    cout << "1";
  } else {
    int m;
    for (i = 2; i < n; i++) {
      if (n % i == 0) break;
    }
    if (i != n)
      cout << "NO";
    else {
      i = 2;
      m = n - 1;
      while (m != 1) {
        if (m % i == 0) {
          primes.push_back(i);
          while (m % i == 0) m /= i;
        }
        i++;
      }
      for (i = 0; i < primes.size(); i++) {
        int tav = (n - 1) / primes[i];
        for (int j = 1; j < n; j++) {
          if (pow1(j, tav) % n == 1) rishe[j] = 1;
        }
      }
      for (i = 2; i < n; i++) {
        if (rishe[i] == 0) break;
      }
      m = 1;
      cout << "YES" << '\n';
      cout << 1 << "\n";
      for (int j = 0; j < n - 2; j++) {
        cout << (pow1(i, m + n - 1) + n) % n << '\n';
        if (m > 0)
          m = -(m + 1);
        else
          m = -(m - 1);
      }
      cout << n;
    }
  }
}
