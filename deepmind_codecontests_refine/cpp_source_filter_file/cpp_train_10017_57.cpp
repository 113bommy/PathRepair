#include <bits/stdc++.h>
using namespace std;
long long kol1, kol2, sum, n;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    if (a % 2 == 0)
      kol1++;
    else
      kol2++;
    sum += a;
  }
  if (sum % 2 == 0) {
    cout << kol2;
  } else {
    cout << kol1;
  }
}
