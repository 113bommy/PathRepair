#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  long long a[] = {0, 4, 10, 20, 35, 56, 83, 116, 155, 198, 244, 292};
  if (n < 12)
    cout << a[n];
  else
    cout << 292 + 49 * (n - 11);
  return 0;
}
