#include <bits/stdc++.h>
using namespace std;
long long z[2000000], ans[2000000];
int main() {
  long long n, k, l = 0, r = 0;
  cin >> n >> k;
  string s;
  cin >> s;
  z[0] = n;
  for (long long i = 1; i <= n; i++) {
    if (r <= i) {
      l = r = i;
      while (r < n && s[r] == s[r - l]) r++;
      z[i] = r - l;
    } else {
      long long k = i - l;
      if (z[k] < r - l)
        z[i] = z[k];
      else {
        l = i;
        while (r < n && s[r] == s[r - l]) r++;
        z[i] = r - l;
      }
    }
  }
  for (long long i = 1; k * i <= n; i++) {
    if (z[i] >= k * i - i) {
      l = k * i;
      r = min(n + 1, (k + 1) * i + 1);
      while (r - l > 1) {
        long long mid = (l + r) / 2;
        if (z[i] >= mid - i)
          l = mid;
        else
          r = mid;
      }
      ans[k * i]++;
      ans[r]--;
    }
  }
  for (long long i = 1; i <= n; i++) ans[i] += ans[i - 1];
  for (long long i = 0; i < n; i++) cout << (bool)ans[i + 1];
  cout << endl;
  return 0;
}
