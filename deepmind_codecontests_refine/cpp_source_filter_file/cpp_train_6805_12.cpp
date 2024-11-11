#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
void solve() {
  long long a, b, x, y;
  cin >> x >> y;
  long long n = x + y;
  string line1 = "", line2 = "";
  a = x, b = y;
  line1 += "a";
  a--;
  for (long long i = 1; i < n; i++) {
    if (i & 2) {
      if (line1[i - 1] == 'a' and b > 0)
        line1 += 'b', b--;
      else if (line1[i - 1] == 'b' and a > 0)
        line1 += 'a', a--;
      else if (a > 0)
        line1 += 'a', a--;
      else if (b > 0)
        line1 += 'b', b--;
    } else {
      if (line1[i - 1] == 'a' and a > 0)
        line1 += 'a', a--;
      else if (line1[i - 1] == 'b' and b > 0)
        line1 += 'b', b--;
      else if (a > 0)
        line1 += 'a', a--;
      else if (b > 0)
        line1 += 'b', b--;
    }
  }
  a = x, b = y;
  line2 += "b";
  b--;
  for (long long i = 1; i < n; i++) {
    if (i & 2) {
      if (line2[i - 1] == 'a' and b > 0)
        line2 += 'b', b--;
      else if (line2[i - 1] == 'b' and a > 0)
        line2 += 'a', a--;
      else if (a > 0)
        line2 += 'a', a--;
      else if (b > 0)
        line2 += 'b', b--;
    } else {
      if (line2[i - 1] == 'a' and a > 0)
        line2 += 'a', a--;
      else if (line2[i - 1] == 'b' and b > 0)
        line2 += 'b', b--;
      else if (a > 0)
        line2 += 'a', a--;
      else if (b > 0)
        line2 += 'b', b--;
    }
  }
  long long p1 = 0, v1 = 0, p2 = 0, v2 = 0;
  for (long long i = 0; i < n - 1; i++)
    if (line1[i] == line1[i + 1])
      p1++;
    else
      v1++;
  for (long long i = 0; i < n - 1; i++)
    if (line2[i] == line2[i + 1])
      p2++;
    else
      v2++;
  if (p1 > p2) {
    cout << p1 << ' ' << v1;
  } else if (p2 > p1) {
    cout << p2 << ' ' << v2;
  } else if (v1 > v2) {
    cout << p1 << ' ' << v1;
  } else {
    cout << p2 << ' ' << v2;
  }
}
void solve(bool testcase) {
  long long t;
  cin >> t;
  while (t--) solve();
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
