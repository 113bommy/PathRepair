#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
const int MAXN = 2e5 + 5;
long long n, m, k, a[MAXN], sum;
long long b[MAXN];
map<int, int> mp;
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b, b + n);
  for (int i = 0; i < m * k; i++) {
    sum += b[n - 1 - i];
  }
  long long i = 0, j = n - m * k, minim = b[j], c = 0;
  while (1) {
    if (b[j] != minim) break;
    mp[minim]++;
    j++;
  }
  i = 0;
  cout << sum << endl;
  while (i < n) {
    if (a[i] > minim) {
      c++;
    } else if (a[i] == minim && mp[minim] > 0) {
      c++;
      mp[minim]--;
    }
    if (c == m) {
      cout << i + 1 << " ";
      c = 0;
      k--;
    }
    if (k == 1) exit(0);
    i++;
  }
}
