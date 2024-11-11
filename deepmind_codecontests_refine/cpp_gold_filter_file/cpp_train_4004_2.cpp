#include <bits/stdc++.h>
using namespace std;
long long int poww(long long int a, long long int b) {
  long long int k = a;
  b = b - 1;
  while (b--) a = a * k;
  return a;
}
int main() {
  std::ios::sync_with_stdio(false);
  long long int a, b, c, k;
  cin >> a >> b >> c;
  vector<int> d;
  long long int ans = 0;
  for (int i = 0; i < 82; ++i) {
    long long int k = poww(i, a);
    if (b * k + c > 0 && b * k + c < 1000000000) {
      long long int x = b * k + c;
      long long int sum = 0;
      while (x > 0) {
        sum = sum + x % 10;
        x = x / 10;
      }
      if (sum == i) {
        ans++;
        d.push_back(b * k + c);
      }
    }
  }
  cout << ans << endl;
  for (int i = 0; i < (int)(d.size()) - 1; ++i) {
    cout << d[i] << " ";
  }
  if ((int)(d.size())) cout << d[(int)(d.size()) - 1] << endl;
  return 0;
}
