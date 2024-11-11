#include <bits/stdc++.h>
using namespace std;
long long a[12] = {0, 4, 10, 20, 35, 56, 83, 116, 155, 198, 244, 292}, n;
int main() {
  cin >> n;
  if (n <= 11)
    cout << a[n] << endl;
  else
    cout << a[11] + (n - 11) * 98 / 2 << endl;
  return 0;
}
