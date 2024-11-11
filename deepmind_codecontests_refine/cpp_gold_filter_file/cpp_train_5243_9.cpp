#include <bits/stdc++.h>
using namespace std;
int p[40] = {1,       2,       4,       6,        12,      16,      18,
             30,      60,      88,      106,      126,     520,     606,
             1278,    2202,    2280,    3216,     4252,    4422,    9688,
             9940,    11212,   19936,   21700,    23208,   44496,   86242,
             110502,  132048,  216090,  756838,   859432,  1257786, 1398268,
             2976220, 3021376, 6972592, 13466916, 20996010};
long long int Power(int x) {
  if (x == 0) return 1;
  long long int Q = Power(x / 2);
  Q = (Q * Q) % 1000000007LL;
  if (x & 1)
    return (Q * 2) % 1000000007LL;
  else
    return Q;
}
int n;
int main() {
  scanf("%d", &n);
  cout << (Power(p[n - 1]) + 1000000007LL - 1) % 1000000007LL << endl;
  return 0;
}
