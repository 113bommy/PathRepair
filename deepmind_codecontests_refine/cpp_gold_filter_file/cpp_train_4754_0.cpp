#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a[15], arr[15] = {0};
  for (int i = 0; i < 14; i++) cin >> a[i];
  long long rem[15];
  long long tot[15];
  for (int i = 0; i < 14; i++) {
    tot[i] = a[i] / 14;
    rem[i] = a[i] % 14;
  }
  long long ans = 0;
  for (int i = 0; i < 14; i++) {
    long long temp = a[i];
    a[i] = 0;
    long long sum = 0;
    for (int i = 0; i < 14; i++) arr[i] = a[i];
    for (int j = 0; j < rem[i]; j++) {
      arr[(i + j + 1) % 14] = (a[(i + j + 1) % 14] + 1);
    }
    for (int j = 0; j < 14; j++) {
      if ((arr[j] + tot[i]) % 2 == 0) {
        sum += arr[j] + tot[i];
      }
    }
    ans = max(ans, sum);
    a[i] = temp;
  }
  cout << ans;
  return 0;
}
