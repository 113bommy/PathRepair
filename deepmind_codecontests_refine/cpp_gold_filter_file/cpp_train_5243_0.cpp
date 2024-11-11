#include <bits/stdc++.h>
using namespace std;
bool possible(int z) {
  for (int i = 1; i <= z; i++) {
    if ((z - (i / 2)) % (i + 1) == 0) return false;
  }
  return true;
}
int ar[] = {1,       2,       4,       6,        12,      16,      18,
            30,      60,      88,      106,      126,     520,     606,
            1278,    2202,    2280,    3216,     4252,    4422,    9688,
            9940,    11212,   19936,   21700,    23208,   44496,   86242,
            110502,  132048,  216090,  756838,   859432,  1257786, 1398268,
            2976220, 3021376, 6972592, 13466916, 20996010};
long long mod = 1000000007LL;
long long bigmod(int p) {
  if (p == 0) return 1;
  if (p % 2 == 0) {
    long long x = bigmod(p / 2);
    return (x * x) % mod;
  } else
    return (2LL * bigmod(p - 1)) % mod;
}
int main() {
  int n;
  scanf("%d", &n);
  cout << ((bigmod(ar[n - 1]) - 1) % mod + mod) % mod << endl;
  return 0;
}
