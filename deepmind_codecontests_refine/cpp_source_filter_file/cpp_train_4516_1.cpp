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
int n, m, offer[(int)1e5 + 10], buy[int(1e4) + 10];
int main() {
  long long sum = 0;
  cin >> m;
  for (int i = 0; i < int(m); ++i) scanf("%d", &offer[i]);
  cin >> n;
  for (int i = 0; i < int(n); ++i) scanf("%d", &buy[i]);
  int idx = n - 1;
  sort(buy, buy + n);
  sort(offer, offer + m);
  while (idx >= 0) {
    if (idx - offer[0] >= 0) {
      for (int i = offer[0]; i > 0; i--) sum += buy[idx--];
      idx -= 2;
    } else
      for (; idx >= 0; idx--) sum += buy[idx];
  }
  cout << sum << endl;
  return 0;
}
