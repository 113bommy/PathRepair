#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n, t, k, d, t1, t2;
  cin >> n >> t >> k >> d;
  t1 = n / k;
  if (n % k != 0) t1++;
  n *= t;
  if (t1 - d > t)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
