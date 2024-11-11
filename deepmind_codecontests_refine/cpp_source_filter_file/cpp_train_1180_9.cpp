#include <bits/stdc++.h>
using namespace std;
const int N = 400 * 1000;
int n, k, a[N], b[N] = {};
long long int r = 0;
map<int, int> mp;
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  int m = 0;
  for (int i = 0, t; i < n; ++i) {
    cin >> t;
    if (mp.count(t))
      a[i] = mp[t];
    else
      a[i] = mp[t] = m++;
  }
  for (int i = 0, j = 0; i < n; ++i) {
    ++b[a[i]];
    if (b[a[i]] == k) {
      int c = 1;
      while (a[j] != a[i]) {
        --b[a[j++]];
        ++c;
      }
      r += c * (n - i);
      --b[a[i]];
      ++j;
    }
  }
  cout << r << '\n';
  return 0;
}
