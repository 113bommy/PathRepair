#include <bits/stdc++.h>
using namespace std;
int main() {
  string a;
  long long int i, l, r, u, d, ans;
  cin >> a;
  if (a.size() % 2 != 0) {
    printf("-1\n");
    return 0;
  }
  l = r = u = d = 0;
  for (i = 0; i < a.size(); i++) {
    if (a[i] == 'U')
      u++;
    else if (a[i] == 'D')
      d++;
    else if (a[i] == 'L')
      l++;
    else if (a[i] == 'R')
      r++;
  }
  if (u == d && l == r)
    printf("0\n");
  else {
    cout << max(abs(u - d), abs(l - r)) << endl;
  }
}
