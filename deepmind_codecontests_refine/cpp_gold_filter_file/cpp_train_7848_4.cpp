#include <bits/stdc++.h>
using namespace std;
long long n;
vector<long long> a;
long long nume, deno;
long long sum;
long long gcd(long long a, long long b) {
  long long c;
  while (a != 0) {
    c = a;
    a = b % a;
    b = c;
  }
  return b;
}
int main() {
  cin >> n;
  a.resize(n);
  for (long long i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  sort(a.begin(), a.end());
  for (long long i = n - 1; i > 0; --i) nume += a[i] * i;
  sort(a.rbegin(), a.rend());
  for (long long i = n - 1; i > 0; --i) nume -= a[i] * i;
  nume *= 2;
  nume += sum;
  deno = n;
  long long div = gcd(nume, deno);
  nume /= div;
  deno /= div;
  cout << nume << ' ' << deno << '\n';
}
