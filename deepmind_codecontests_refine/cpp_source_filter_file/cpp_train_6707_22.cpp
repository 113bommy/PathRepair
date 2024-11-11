#include <bits/stdc++.h>
using namespace std;
int a[30];
int main() {
  int i, n, x, p;
  string s;
  cin >> s;
  n = s.length();
  for (i = 0; i < n; i++) {
    a[s[i] - 'a']++;
  }
  x = min(a[19], min(a[8], min((a[4] / 3), ((a[13] + 1) / 3))));
  cout << x;
}
