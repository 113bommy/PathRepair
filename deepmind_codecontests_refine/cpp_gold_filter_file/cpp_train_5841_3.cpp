#include <bits/stdc++.h>
using namespace std;
long long int mod = 1000000007;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, a, b, c, d, e, f, q1, q2;
  cin >> n >> a >> b >> c >> d >> e >> f;
  if (c > a && d > b)
    q1 = 1;
  else if (c < a && d > b)
    q1 = 2;
  else if (c < a && d < b)
    q1 = 3;
  else
    q1 = 4;
  if (e > a && f > b)
    q2 = 1;
  else if (e < a && f > b)
    q2 = 2;
  else if (e < a && f < b)
    q2 = 3;
  else
    q2 = 4;
  q1 == q2 ? cout << "YES\n" : cout << "NO\n";
  return 0;
}
