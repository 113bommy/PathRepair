#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, i, cnt = 0, sum = 0;
  cin >> t;
  long long int ar[t];
  for (i = 0; i < t; i++) cin >> ar[i];
  for (i = 0; i < t; i++) {
    sum = sum + ar[i];
    if (ar[i] % 2 == 0) cnt++;
  }
  if (cnt == 0 && sum % 2 == 0)
    cout << "0";
  else if (cnt == 0 && sum % 2 != 0)
    cout << t;
  else if (cnt > 1 && sum % 2 == 0)
    cout << cnt;
  else if (cnt > 1 && sum % 2 != 0)
    cout << t - cnt;
}
