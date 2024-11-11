#include <bits/stdc++.h>
using namespace std;
int *v;
vector<int> xl, xr;
int main() {
  int n;
  scanf("%d", &n);
  string str;
  cin >> str;
  xl.clear();
  xr.clear();
  v = new int[n];
  bool r = false, l = false;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    if (str[i] == 'R')
      xl.push_back(x);
    else
      xr.push_back(x);
    if (str[i] == 'L' && r) {
      l = true;
      continue;
    }
    if (str[i] == 'R') {
      r = true;
    }
  }
  if (!l) {
    printf("-1\n");
    return 0;
  }
  int ans = 200000000;
  int lenl = xl.size(), lenr = xr.size();
  for (int i = 0; i < lenr; i++) {
    int it = lower_bound(xl.begin(), xl.end(), xr[i]) - xl.begin();
    if (it == lenl) continue;
    ans = min(ans, (xl[it] - xr[i]) / 2);
  }
  if (ans != 200000000)
    printf("%d\n", ans);
  else
    printf("-1\n");
  delete[] v;
  return 0;
}
