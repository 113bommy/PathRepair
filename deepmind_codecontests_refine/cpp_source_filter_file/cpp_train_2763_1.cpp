#include <bits/stdc++.h>
using namespace std;
int a[100];
int b[100];
int c[100];
int d[100];
int main() {
  int n;
  int p = 0;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    a[i] = s[i] - '0';
  }
  for (int i = 0; i < n; i++) {
    if ((a[i] > 0) || (a[i] < 4)) {
      p += 1;
      i = 1000;
    }
  }
  for (int i = 0; i < n; i++) {
    if ((a[i] == 7) || (a[i] == 9) || (a[i] == 0)) {
      p += 2;
      i = 1000;
    }
  }
  for (int i = 0; i < n; i++)
    if ((a[i] == 1) || (a[i] == 4) || (a[i] == 7) || (a[i] == 0)) {
      p += 3;
      i = 1000;
    }
  for (int i = 0; i < n; i++)
    if ((a[i] == 3) || (a[i] == 6) || (a[i] == 9) || (a[i] == 0)) {
      p += 4;
      i = 1000;
    }
  if (p == 10)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
