#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
int n, m;
int a[maxn][maxn];
int b[maxn];
int c[maxn];
int useb[maxn];
int usec[maxn];
void conv() {
  memset(b, 0, sizeof(b));
  memset(c, 0, sizeof(c));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      b[i] += a[i][j];
      c[j] += a[i][j];
    }
}
int main() {
  bool check;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> a[i][j];
  conv();
  check = 1;
  while (check) {
    for (int i = 0; i < n; i++)
      if (b[i] < 0) {
        useb[i] = useb[i] ^ 1;
        for (int j = 0; j < m; j++) a[i][j] *= -1;
      }
    conv();
    for (int j = 0; j < m; j++)
      if (c[j] < 0) {
        usec[j] = usec[j] ^ 1;
        for (int i = 0; i < n; i++) a[i][j] *= -1;
      }
    conv();
    check = 0;
    for (int i = 0; i < n; i++)
      if (b[i] < 0) check = 1;
    for (int j = 0; j < m; j++)
      if (c[j] < 0) check = 1;
  }
  int cnt1 = 0, cnt2;
  for (int i = 0; i < n; i++)
    if (useb[i]) cnt1++;
  for (int j = 0; j < m; j++)
    if (usec[j]) cnt2++;
  cout << cnt1 << " ";
  for (int i = 0; i < n; i++)
    if (useb[i]) cout << i + 1 << " ";
  cout << endl << cnt2 << " ";
  for (int j = 0; j < m; j++)
    if (usec[j]) cout << j + 1 << " ";
  return 0;
}
