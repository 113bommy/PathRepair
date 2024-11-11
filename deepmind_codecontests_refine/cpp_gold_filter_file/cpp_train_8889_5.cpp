#include <bits/stdc++.h>
using namespace std;
const long long p = 1000000009;
long long n, m, k;
long long edos(long long exp) {
  if (exp == 0) return 1;
  long long ret = edos(exp / 2);
  if (exp % 2 == 1) return (ret * (ret * 2) % p) % p;
  return (ret * ret) % p;
}
long long f(long long a) { return (k * (edos(a + 1) - 2)) % p; }
int main() {
  cin >> n >> m >> k;
  long long bols = n / k * (k - 1) + n % k;
  if (m <= bols)
    cout << m << endl;
  else {
    long long dob = k * (m - bols);
    long long puntx2 = f(m - bols);
    cout << (p + m - dob + puntx2) % p << endl;
  }
  cin >> n;
}
