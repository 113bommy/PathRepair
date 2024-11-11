#include <bits/stdc++.h>
using namespace std;
long long int maxi(long long int a, long long int b) { return (a > b) ? a : b; }
long long int mini(long long int a, long long int b) { return (a < b) ? a : b; }
long long int lift(long long int a, long long int b) {
  long long int g = 1;
  for (long long int i = 1; i <= b; i++) {
    g *= a;
  }
  return g;
}
char t[1000000];
int main() {
  long long int n, m, k;
  cin >> n >> m >> k;
  char r[(2 * n) - 1], c[(2 * m) - 1];
  for (long long int i = 0; i < n - 1; i++) r[i] = 'D';
  for (long long int i = n - 1; i < 2 * (n - 1); i++) r[i] = 'U';
  r[2 * (n - 1)] = 'R';
  c[0] = 'D';
  for (long long int i = 1; i < n; i++) c[i] = 'L';
  for (long long int i = n; i < 2 * (n - 1) + 1; i++) c[i] = 'R';
  long long int pos = 0;
  for (long long int i = 0; i < m - 1; i++) {
    for (long long int j = 0; j < (2 * n) - 1; j++) {
      t[pos] = r[j];
      pos++;
    }
  }
  for (long long int i = 0; i < n - 1; i++) {
    for (long long int j = 0; j < (2 * m) - 1; j++) {
      t[pos] = c[j];
      pos++;
    }
  }
  for (long long int i = 0; i < n - 1; i++) {
    t[pos] = 'U';
    pos++;
  }
  for (long long int i = 0; i < n - 1; i++) {
    t[pos] = 'L';
    pos++;
  }
  long long int d = (4 * n * m) - (2 * n) - (2 * m);
  if (k > d)
    cout << "NO\n";
  else {
    cout << "YES\n";
    long long int w = 1, h = 1, s = k;
    for (long long int i = 1; i < k; i++) {
      if (t[i] != t[i - 1]) {
        h++;
      }
    }
    cout << h << endl;
    long long int i;
    for (i = 1; i < k; i++) {
      if (t[i] == t[i - 1]) {
        w++;
      } else {
        cout << w << " " << t[i - 1] << endl;
        w = 1;
      }
    }
    cout << w << " " << t[i - 1] << endl;
  }
}
