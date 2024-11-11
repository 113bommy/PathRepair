#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000100;
int l[maxn], r[maxn], a[maxn];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i <= maxn - 1; i++) l[i] = i;
  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    l[y] = x;
    r[x] = y;
  }
  int dem = 0;
  for (int i = r[0]; i; i = r[i]) {
    dem += 2;
    a[dem] = i;
    l[i] = i;
  }
  int luu;
  for (int i = 0; i <= maxn - 1; i++) {
    if (l[l[i]] == l[i] && i != l[i]) luu = l[i];
  }
  dem = 1;
  for (int i = luu; i; i = r[i]) {
    a[dem] = i;
    dem += 2;
  }
  for (int i = 1; i <= n; i++) cout << a[i] << ' ';
}
