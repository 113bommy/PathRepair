#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  vector<long long> s;
  for (int i = 0; i < 59; i++) {
    long long int j = i + 1;
    long long x = (1LL << j) - 1LL;
    s.push_back(x);
  }
  cin >> t;
  while (t--) {
    long long int n, ans = 0;
    cin >> n;
    int i = 0;
    while (n > 0) {
      int x = n & 1;
      if (x == 1) {
        ans = ans + s[i];
      }
      i++;
      n = n >> 1;
    }
    cout << ans << endl;
  }
  return 0;
}
