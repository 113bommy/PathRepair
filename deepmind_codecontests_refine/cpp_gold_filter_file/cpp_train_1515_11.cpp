#include <bits/stdc++.h>
using namespace std;
int main() {
  int t[5], f[101], sum = 0, ans = 0;
  fill(f, f + 101, 0);
  cin >> t[0] >> t[1] >> t[2] >> t[3] >> t[4];
  for (int i = 0; i < 5; i++) {
    sum += t[i];
    f[t[i]]++;
  }
  for (int i = 0; i <= 100; i++)
    if (f[i] > 1)
      if ((f[i] * i > ans)) ans = min(f[i] * i, i * 3);
  cout << sum - ans;
}
