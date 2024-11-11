#include <bits/stdc++.h>
using namespace std;

long long a[7];
int main()
{
  for (int i = 0; i < 7; i++){
    cin >> a[i];
  }

  long long m = min(min(a[0], a[3]), a[4]);
  /*
  a[0] -= m;
  a[3] -= m;
  a[4] -= m;
  */

  long long ans = 0;
  for (int i = 0; i <= min(m, 1000000ll); i++){
    ans = max(ans, 3 * i + (a[0] - i) / 2 * 2 + (a[3] - i) / 2 * 2 + (a[4] - i) / 2 * 2);
  }

  cout << ans + a[1] << endl;
}
