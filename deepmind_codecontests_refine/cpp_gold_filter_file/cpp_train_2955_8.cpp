#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
int m1[MAXN], m2[MAXN], a[MAXN], M1[MAXN], M2[MAXN];
int main() {
  ios::sync_with_stdio(false);
  memset(m1, 127, sizeof m1);
  memset(m2, 127, sizeof m2);
  for (int i = 0; i < MAXN; i++) M1[i] = M2[i] = -m1[0];
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i == 0)
      m1[i] = i;
    else if (a[i] < a[m1[i - 1]])
      m1[i] = i;
    else
      m1[i] = m1[i - 1];
    if (i == 0)
      M1[i] = i;
    else if (a[i] > a[M1[i - 1]])
      M1[i] = i;
    else
      M1[i] = M1[i - 1];
  }
  M2[n - 1] = m2[n - 1] = n - 1;
  for (int i = n - 2; i >= 0; i--) {
    m2[i] = m2[i + 1];
    if (a[i] < a[m2[i]]) m2[i] = i;
    M2[i] = M2[i + 1];
    if (a[i] > a[M2[i]]) M2[i] = i;
  }
  for (int i = 1; i < n - 1; i++) {
    int x = a[m1[i - 1]], y = a[i], z = a[m2[i + 1]];
    if (x < y and z < y) {
      cout << 3 << endl;
      cout << m1[i - 1] + 1 << " " << i + 1 << " " << m2[i + 1] + 1 << endl;
      return 0;
    }
    x = a[M1[i - 1]], y = a[i], z = a[M2[i + 1]];
    if (x > y and z > y) {
      cout << 3 << endl;
      cout << M1[i - 1] + 1 << " " << i + 1 << " " << M2[i + 1] + 1 << endl;
      return 0;
    }
  }
  cout << 0 << endl;
  return 0;
}
