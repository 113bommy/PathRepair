#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a[100000], b[100000], na, nb, k, m, i;
  cin >> na >> nb >> k >> m;
  for (i = 0; i < na; i++) cin >> a[i];
  for (i = 0; i < nb; i++) cin >> b[i];
  if (b[nb - m] > a[k - 1])
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
