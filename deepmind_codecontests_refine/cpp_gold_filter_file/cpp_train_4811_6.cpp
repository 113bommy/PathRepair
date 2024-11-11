#include <bits/stdc++.h>
using namespace std;
int t, n, k;
string s1, s;
char c[200010];
int main() {
  cin >> n >> k;
  s = "v";
  string a;
  cin >> s1;
  s += s1;
  a = s;
  int len = n - k;
  for (int i = 1; i <= len; i++) {
    a[i + k] = a[i];
  }
  while (a < s) {
    if (a[k] < '9')
      a[k]++;
    else {
      int f = k;
      while (a[f] == '9' && f > 1) --f;
      a[f]++;
      for (int i = f + 1; i <= k; i++) a[i] = '0';
      for (int i = 1; i <= len; i++) a[i + k] = a[i];
    }
    for (int i = 1; i <= len; i++) a[i + k] = a[i];
  }
  cout << n << endl;
  a.erase(0, 1);
  cout << a << endl;
  return 0;
}
