#include <bits/stdc++.h>
using namespace std;
long long ans;
long long arr[6010];
long long way(long long x) {
  if ((x > 3000) || ((arr[x] == 0) && (x != 1))) return 0;
  long long a, b, max_e;
  a = arr[2 * x] + way(2 * x);
  b = arr[(2 * x) + 1] + way((2 * x) + 1);
  max_e = a;
  if (max_e < b) max_e = b;
  ans += (max_e - a) + (max_e - b);
  return max_e;
}
int main() {
  long long n, i, l;
  cin >> n;
  l = 1;
  for (i = 1; i <= n + 1; i++) {
    l = l * 2;
  }
  l = l - 2;
  for (i = 2; i <= l + 1; i++) {
    cin >> arr[i];
  }
  l = way(1);
  cout << ans;
  return 0;
}
