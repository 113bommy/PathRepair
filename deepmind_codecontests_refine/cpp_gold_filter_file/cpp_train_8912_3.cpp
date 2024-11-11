#include <bits/stdc++.h>
using namespace std;
int f = 100002;
int a[100007] = {};
int b[200007] = {};
int main() {
  int n, z = 0;
  string s;
  cin >> n;
  cin >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0')
      a[i] = a[i - 1] - 1;
    else
      a[i] = a[i - 1] + 1;
    if (b[a[i] + f] == 0)
      b[a[i] + f] = i + 1;
    else if (z < i + 1 - b[a[i] + f])
      z = i + 1 - b[a[i] + f];
  }
  for (int i = 0; i < n; i++) {
    if (a[i] == 0 && z < i + 1) z = i + 1;
  }
  cout << z;
}
