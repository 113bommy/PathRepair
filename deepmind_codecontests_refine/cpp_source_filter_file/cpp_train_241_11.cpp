#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000000;
const int MOD = 1000000007;
int main() {
  long long a[3];
  cin >> a[0] >> a[1] >> a[2];
  sort(a, a + 2);
  if (a[0] % 2 == a[1] % 2)
    cout << a[1];
  else
    cout << a[2];
}
