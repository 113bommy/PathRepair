#include <bits/stdc++.h>
using namespace std;
const int N = 255001;
const long double PI = acos(-1);
int n, m, freq[N], a[N], k[N];
signed main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  int s = 0, ss = 0;
  for (int i = 1; i <= m; i++) {
    scanf("%d", &k[i]);
    s += k[i];
  }
  for (int i = 0; i < n; i++) {
    ss = 0;
    for (int ii = 0; ii <= 100; ii++) freq[ii] = 0;
    for (int j = i; j < n; j++) {
      freq[a[j]]++;
      ss++;
      if (freq[a[j]] > k[a[j]]) break;
      if (ss == s) return puts("Yes"), 0;
    }
  }
  puts("No");
}
