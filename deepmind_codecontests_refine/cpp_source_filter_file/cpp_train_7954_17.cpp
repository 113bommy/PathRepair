#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
using namespace std;
int main() {
  string s;
  cin >> s;
  int p, l = 0, r = 0;
  for (int i = 0; i < (int)(s.length()); ++i) {
    if (s[i] == '^') p = i;
  }
  for (int i = 0; s[i] != '^'; i++) {
    if (s[i] >= '1' && s[i] <= '9') {
      l += (s[i] - 48) * (p - i);
    }
  }
  for (int i = p; i < s.length(); i++) {
    if (s[i] >= '1' && s[i] <= '9') {
      r += (s[i] - 48) * (i - p);
    }
  }
  if (l == r)
    cout << "balance";
  else if (l > r)
    cout << "left";
  else
    cout << "right";
}
