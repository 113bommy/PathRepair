#include <bits/stdc++.h>
using namespace std;
long long solve() {
  long long a, b;
  long long x, y, z;
  long long res = 0;
  cin >> a >> b;
  cin >> x >> y >> z;
  long long arr[4];
  arr[0] = 2 * x;
  arr[1] = arr[2] = y;
  arr[3] = 3 * z;
  if (a != arr[0] + arr[1]) res += (arr[0] + arr[1]) - a;
  if (b != arr[2] + arr[3]) res += (arr[2] + arr[3]) - b;
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << solve() << endl;
  return 0;
}
