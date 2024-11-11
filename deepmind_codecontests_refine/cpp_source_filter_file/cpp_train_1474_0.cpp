#include <bits/stdc++.h>
using namespace std;
long long n, i, m[6222000], k, a, b, x, y, sum, z, m1[5000];
string s;
int main() {
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> m[i];
  }
  sort(m, m + n);
  for (i = 1; i < n; i++) {
    if (m[i] == m[i - 1])
      z++;
    else
      z = 0;
    if (z == 2) {
      cout << "NO";
      return 0;
    }
  }
  for (i = 1; i < n; i++) {
    if (m[i] == m[i - 1]) k++;
  }
  cout << "YES\n" << n - k << endl;
  cout << m[i] << " ";
  for (i = 1; i < n; i++) {
    if (m[i] != m[i - 1]) cout << m[i] << " ";
  }
  cout << endl << k << endl;
  reverse(m, m + n);
  for (i = 0; i < n - 1; i++) {
    if (m[i] == m[i + 1]) cout << m[i] << " ";
  }
}
