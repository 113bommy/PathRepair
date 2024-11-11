#include <bits/stdc++.h>
using namespace std;
int vocala(char c) {
  if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' ||
      c == 'o' || c == 'O' || c == 'u' || c == 'U')
    return 1;
  if (c == 'y' || c == 'Y') return 1;
  return 0;
}
int isprime(long long n) {
  if (n <= 1) return 0;
  if (n <= 3) return 1;
  if (n % 2 == 0 || n % 3 == 0) return 0;
  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return 0;
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
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  long long cnt = 0;
  for (int i = 1; i <= n; ++i) {
    string s;
    cin >> s;
    if (s[0] == 'I') cnt += 20;
    if (s[0] == 'T') cnt += 4;
    if (s[0] == 'O') cnt += 8;
    if (s[0] == 'C') cnt += 6;
    if (s[0] == 'D') cnt += 12;
  }
  cout << cnt << '\n';
  in.close();
  out.close();
  return 0;
}
