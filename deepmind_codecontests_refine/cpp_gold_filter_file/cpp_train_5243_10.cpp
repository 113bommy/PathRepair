#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
vector<long long> sol;
const long long ans[] = {
    1,      2,       4,       6,       12,      16,      18,       30,
    60,     88,      106,     126,     520,     606,     1278,     2202,
    2280,   3216,    4252,    4422,    9688,    9940,    11212,    19936,
    21700,  23208,   44496,   86242,   110502,  132048,  216090,   756838,
    859432, 1257786, 1398268, 2976220, 3021376, 6972592, 13466916, 20996010};
long long ex(long long base, long long e) {
  if (e == 0) return 1;
  long long res = ex(base, e / 2);
  res = (res * res) % mod;
  if (e % 2 == 1) res = (res * base) % mod;
  return res;
}
int main() {
  int n;
  cin >> n;
  cout << (ex(2, ans[n - 1]) - 1 + mod) % mod << endl;
}
