#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return (b == 0 ? a : gcd(b, a % b)); }
long long lcm(long long a, long long b) { return (a * (b / gcd(a, b))); }
bool getbit(int num, int idx) { return (num >> idx & 1) == 1; }
int setbit(int num, int idx, bool val) {
  if (val == true) return (num | (1 << idx));
  return num & ~(1 << idx);
}
int flipbit(int num, int idx) { return num ^ (1 << idx); }
int cntbits(int mask) {
  int res = 0;
  while (mask) mask &= (mask - 1), res++;
  return res;
}
int main() {
  long long n, k;
  cin >> n >> k;
  if (k >= n * (n - 1) / 2)
    cout << "no solution" << endl;
  else {
    for (int i = 0; i < int(n); ++i)
      cout << 0 << " " << (int)1e9 - i * 10 << endl;
  }
  return 0;
}
