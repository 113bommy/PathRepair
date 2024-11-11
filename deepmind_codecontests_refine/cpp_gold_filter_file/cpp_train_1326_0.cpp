#include <bits/stdc++.h>
const long long mod = 1e9 + 7;
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long a, b;
  cin >> a >> b;
  long long left = 7 - max(a, b);
  if (left == 1)
    cout << "1/6";
  else if (left == 2)
    cout << "1/3";
  else if (left == 3)
    cout << "1/2";
  else if (left == 4)
    cout << "2/3";
  else if (left == 5)
    cout << "5/6";
  else if (left == 6)
    cout << "1/1";
  return 0;
}
