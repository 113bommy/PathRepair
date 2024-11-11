#include <bits/stdc++.h>
using namespace std;
int l[1000000], k[1000000], s;
bool df[1000000];
int n, flag = 1, a;
bool bin(int g) {
  if (l[g - 1] <= s) return true;
  for (int i = 0; i < g; i++)
    if (l[i] + k[g - i - 2] + a * min(i, g - i - 1) <= s) return true;
  return false;
}
int main() {
  int b;
  cin >> n >> a >> b >> s;
  string hj;
  cin >> hj;
  if (hj[0] == 'w')
    l[0] = 1 + b;
  else
    l[0] = 1;
  if (hj[n - 1] == 'w')
    k[0] = 1 + b;
  else
    k[0] = 1;
  for (int i = 1; i < n; i++) {
    if (hj[i] == 'w')
      l[i] = l[i - 1] + 1 + b + a;
    else
      l[i] += (l[i - 1] + 1 + a);
    if (hj[n - i - 1] == 'w')
      k[i] = k[i - 1] + b + a + 1;
    else
      k[i] = k[i - 1] + a + 1;
  }
  if (bin(n)) {
    cout << n;
    return 0;
  }
  int r = 0, f = n;
  while (f - r > 1) {
    int m = (f + r) / 2;
    if (bin(m))
      r = m;
    else
      f = m;
  }
  cout << r;
}
