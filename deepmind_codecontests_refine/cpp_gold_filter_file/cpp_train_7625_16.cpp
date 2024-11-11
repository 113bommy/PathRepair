#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b, c = 0, d, e, f = 0, g, h, i, j, k, l, m, n, o, p, q, r, s,
                      t, u, v, w, x, y, z;
  long long int cnt = 0, ans = 0, l1, l2, l3, c1 = 0, c2 = 0, c3 = 0, mx = 0,
                mn = 0;
  long long int prevsum = 0, ans1 = 0, ans2 = 0, odd = 0, even = 0, hh, mm;
  string str, str1, str2;
  char ch;
  scanf("%lld", &t);
  while (t--) {
    cin >> str;
    c1 = c2 = c3 = 0;
    for (auto x : str) {
      if (x == 'S')
        c1++;
      else if (x == 'P')
        c2++;
      else
        c3++;
    }
    if (c1 >= c2 && c1 >= c3) {
      for (auto x : str) cout << 'R';
    } else if (c2 >= c1 && c2 >= c3) {
      for (auto x : str) cout << 'S';
    } else {
      for (auto x : str) cout << 'P';
    }
    cout << '\n';
  }
  return 0;
}
