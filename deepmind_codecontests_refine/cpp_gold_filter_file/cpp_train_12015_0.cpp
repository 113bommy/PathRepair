#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i = 0;
  long long temp;
  long long sum = 0;
  long long d_max = 0;
  long long ans;
  cin >> n;
  while (i < n) {
    cin >> temp;
    sum += temp;
    if (temp > d_max) {
      d_max = temp;
    }
    i++;
  }
  ans = (sum - 1) / (n - 1) + 1;
  if (ans < d_max) ans = d_max;
  cout << ans << endl;
  return 0;
}
