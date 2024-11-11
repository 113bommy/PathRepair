#include <bits/stdc++.h>
using namespace std;
long long comb(long long n) { return (n * (n + 1)) / 2; }
int main() {
  int T = 1;
  while (T--) {
    int n;
    cin >> n;
    long long int ans = 0;
    vector<int> a(n);
    for (long long int i = (0); (i) <= (n - 1); (i)++) cin >> a[i];
    a.push_back(1000000007);
    int c = 1;
    int ref = a[0];
    for (long long int i = (1); (i) <= (n); (i)++) {
      if (a[i] == ref)
        c++;
      else {
        ref = a[i];
        ans += comb(c);
        c = 1;
      }
    }
    cout << ans;
  }
  return 0;
}
