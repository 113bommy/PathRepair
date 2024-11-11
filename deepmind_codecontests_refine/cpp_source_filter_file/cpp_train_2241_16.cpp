#include <bits/stdc++.h>
using namespace std;
const long long int N = 100;
long long int n, a, b, c, d, x[N];
char mp[N][N];
bool mark[N][N];
string s;
int32_t main() {
  bool is = false;
  for (long long int i = 0; i < 100; i++) {
    for (long long int j = 0; j < 100; j++) {
      mp[i][j] = '.';
    }
  }
  cout << "YES" << '\n';
  cin >> a >> b >> c >> d >> n;
  for (long long int i = 0; i < n; i++) {
    cin >> x[i];
  }
  if (b < d) {
    swap(a, c);
    swap(b, d);
    is = 1;
  }
  for (long long int i = 1; i <= b; i++) {
    for (long long int j = 1; j <= a; j++) {
      mark[i][j] = true;
    }
  }
  for (long long int i = 1; i <= d; i++) {
    for (long long int j = 1; j <= c + a; j++) {
      mark[i][j] = true;
    }
  }
  long long int l, r;
  if (b - d % 2) {
    l = b, r = 1;
  } else {
    l = b, r = a;
  }
  long long int i = 0, h = x[0];
  while (true) {
    mark[l][r] = false;
    if (h) {
      h--;
      mp[l][r] = 'a' + i;
    } else {
      i++;
      h = x[i] - 1;
      mp[l][r] = 'a' + i;
    }
    if (mark[l][r - 1]) {
      r--;
      continue;
    }
    if (mark[l][r + 1]) {
      r++;
      continue;
    }
    if (mark[l - 1][r]) {
      l--;
      continue;
    }
    break;
  }
  if (is) {
    for (long long int i = 1; i < 100; i++) {
      long long int hh = a + c + 2;
      reverse(mp[i], mp[i] + hh);
    }
  }
  for (long long int i = 1; i <= b; i++) {
    for (long long int j = 1; j <= a + c; j++) {
      cout << mp[i][j];
    }
    cout << '\n';
  }
  return 0;
}
