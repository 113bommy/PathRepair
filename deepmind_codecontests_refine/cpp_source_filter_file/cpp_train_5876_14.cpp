#include <bits/stdc++.h>
using namespace std;
bool vocala(char c) {
  if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' ||
      c == 'o' || c == 'O' || c == 'u' || c == 'U')
    return true;
  if (c == 'Y' || c == 'y') return true;
  return false;
}
int isprime(long long n) {
  if (n == 1) return 0;
  if (n == 2) return 1;
  if (n % 2 == 0) return 0;
  for (int i = 3; i * i <= n; i += 2)
    if (n % i == 0) return 0;
  return 1;
}
int isfibo(long long n) {
  long long a = 5 * n * n + 4;
  long long b = a - 8;
  if (sqrt(a) == int(sqrt(a)) || sqrt(b) == int(sqrt(b))) return 1;
  return 0;
}
int gcd(long long a, long long b) {
  long long r;
  while (b) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
ifstream in("input.txt");
ofstream out("output.txt");
long long const nrmax = 1e18;
string a, b;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, i, t;
  cin >> a >> b;
  if (a.size() != b.size()) {
    cout << "NO";
    return 0;
  }
  n = a.size();
  t = n - 1;
  for (i = 0; i <= n / 2; ++i) {
    if (a[i] != b[t]) {
      cout << "NO";
      return 0;
    }
    --t;
  }
  cout << "YES";
  in.close();
  out.close();
  return 0;
}
