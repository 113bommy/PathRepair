#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
char a[1000001];
int main() {
  int q, w, e, r, t, y = 1, c;
  int h1[26], h2[26];
  int ans = 0;
  cin >> q >> t;
  for (w = 0; w < t; w++) {
    h1[w] = 0;
    h2[w] = 0;
  }
  scanf("%s", a);
  int t1 = 0;
  for (w = 0; a[w]; w++) {
    r = y;
    y = (y + y - h2[a[w] - 'a']) % p;
    if (y < 0) {
      y += p;
    }
    h2[a[w] - 'a'] = r;
    h1[a[w] - 'a'] = w + 1;
    t1++;
  }
  for (w = 0; w < q; w++) {
    c = 0;
    for (e = 0; e < t; e++) {
      if (h1[e] < h1[c]) {
        c = e;
      }
    }
    r = y;
    y = (y + y - h2[c]) % p;
    if (y < 0) {
      y += p;
    }
    h2[c] = r;
    h1[c] = t1 + w;
  }
  cout << y;
  return 0;
}
