#include <bits/stdc++.h>
using namespace std;
long long int max(long long int a, long long int b) {
  if (b > a)
    return b;
  else
    return a;
}
int main() {
  long long int a, b, c, d, e, f, g;
  int n;
  cin >> n;
  vector<long long int> values(n, 0);
  vector<long long int> saylar(101, 0);
  for (int i = 0; i < n; i++) {
    cin >> values[i];
    saylar[values[i]]++;
  }
  long long int maxi = -1, eded = -1;
  for (int i = 0; i < 101; i++)
    if (saylar[i] > maxi) maxi = saylar[i], eded = i;
  long long int ans = 0;
  for (int i = 0; i < 10; i++) {
    vector<long long int> kalues(n, 0), tezesaylar(2 * n + 10, -1);
    for (int j = 0; j < n; j++) {
      if (values[j] == i)
        kalues[j] = -1;
      else if (values[j] == eded)
        kalues[j] = 1;
      else
        kalues[j] = 0;
    }
    long long int sum = 0, mum = 0;
    tezesaylar[0] = -1;
    for (int j = 0; j < n; j++) {
      mum += kalues[j];
      sum = mum;
      if (sum < 0) sum = -sum + n;
      if (tezesaylar[sum] != -1)
        ans = max(ans, j - tezesaylar[sum]);
      else if (sum == 0)
        ans = max(ans, j + 1);
      else
        tezesaylar[sum] = j;
    }
  }
  cout << ans << endl;
  return 0;
}
