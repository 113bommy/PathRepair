#include <bits/stdc++.h>
using namespace std;
int f[234567], n, w, ans = 0, el[234567], a[234567];
void build() {
  int j = 0;
  for (int i = 1; i < n; i++) {
    while (j && el[i] != el[j]) j = f[j - 1];
    if (el[i] == el[j]) j++;
    f[i] = j;
  }
}
void fnd() {
  int j = 0;
  for (int i = 0; i < n; i++) {
    if (j && a[i] != el[j]) j = f[j - 1];
    if (a[i] == el[j]) j++;
    if (j == w) {
      ans++;
      j = f[j - 1];
    }
  }
}
int main() {
  cin >> n >> w;
  int prev = 0;
  for (int i = 0, x; i < n; i++) {
    scanf("%d", &x);
    if (i) a[i - 1] = x - prev;
    prev = x;
  }
  prev = 0;
  for (int i = 0, x; i < w; i++) {
    scanf("%d", &x);
    if (i) el[i - 1] = x - prev;
    prev = x;
  }
  w--;
  n--;
  build();
  fnd();
  if (!w) ans++;
  cout << ans << endl;
}
