#include <bits/stdc++.h>
using namespace std;
int flag, sum, ans, cnt, mini = INT_MAX, maxi;
const int N = 1e5 + 3;
int save[N];
int main() {
  long long x, y, z;
  scanf("%lld %lld %lld", &x, &y, &z);
  long long x1 = x % z;
  long long y1 = y % z;
  long long z1 = (x1 + y1) / z;
  cout << x / z + y / z + z1 << " ";
  cout << (z1 != 0 ? z - max(x1, y1) : 0);
}
