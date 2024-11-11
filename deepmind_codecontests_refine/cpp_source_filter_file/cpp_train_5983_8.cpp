#include <bits/stdc++.h>
using namespace std;
int n, p, upsAndDowns, poslednja, prva;
short howMuch[100002], df[100002];
char c[100002];
int diff(char c1, char c2) {
  int x, y;
  x = c1 - c2;
  y = 26 + c2 - c1;
  if (x > y) x = y;
  return x;
}
int manji(int x, int y) {
  if (x > y) x = y;
  return x;
}
int main() {
  cin >> n >> p;
  int i;
  for (i = 1; i <= n; i++) cin >> c[i];
  for (i = 1; i <= n / 2; i++) {
    if (c[i] > c[n + 1 - i])
      df[i] += diff(c[i], c[n + 1 - i]);
    else
      df[i] += diff(c[n + 1 - i], c[i]);
    upsAndDowns += df[i];
  }
  for (i = 1; i <= (n + 1) / 2; i++)
    if (df[i]) {
      prva = i;
      break;
    }
  for (i = (n + 1) / 2; i > prva; i--) {
    if (df[i]) {
      break;
    }
  }
  poslednja = i;
  if (!prva) {
    cout << 0;
    return 0;
  }
  if (p > (n + 1) / 2) p = n + 1 - p;
  if (p < prva) {
    cout << upsAndDowns + poslednja - p;
  } else if (p <= poslednja) {
    cout << upsAndDowns + manji(poslednja - p, p - prva) + poslednja - p;
  } else {
    cout << upsAndDowns + p - prva;
  }
  return 0;
}
