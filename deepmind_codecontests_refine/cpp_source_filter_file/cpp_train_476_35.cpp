#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("omit-frame-pointer")
#pragma GCC optimize("unroll-loops")
const int MAXINT = 2147483640;
const long long MAXLL = 9223372036854775800LL;
const long long MAXN = 1000000;
const double pi = 3.1415926535897932384626433832795;
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  srand(time(0));
  long long s, t1, t2, v1, v2;
  long long sum1 = 0, sum2 = 0;
  cin >> s >> t1 >> t2 >> v1 >> v2;
  sum1 = t1 + t1 + v1 * s;
  sum2 = t2 + t2 + v2 * s;
  if (sum1 < sum2)
    cout << "First" << endl;
  else if (sum2 < sum1)
    cout << "Second" << endl;
  else
    cout << "Friendship" << endl;
  return 0;
}
