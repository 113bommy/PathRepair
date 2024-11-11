#include <bits/stdc++.h>
const double pi = acos(-1.0);
const long long mod = 25 * 1E8;
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long a, b;
  cin >> a >> b;
  long long k = (a % b);
  if (k & 1)
    puts("YES");
  else
    puts("NO");
  return 0;
}
