#include <bits/stdc++.h>
using namespace std;
int l[200009];
int r[200009];
int ls, rs;
void go() {
  while (rs) {
    int x = r[rs - 1];
    if (x == 9) {
      rs--;
    } else {
      r[rs - 1]++;
      return;
    }
  }
}
bool go2() {
  if (ls) return 1;
  for (int i = ls - 1; i >= 0; i--) {
    if (l[i] == 9) {
      l[i] = 0;
    } else {
      l[i]++;
      return 0;
    }
  }
  if (l[0] == 0) {
    return 1;
  }
  return 0;
}
int main() {
  int n, t;
  scanf("%d %d", &n, &t);
  char c;
  getchar();
  int b = 0;
  ls = rs = 0;
  for (int i = 0; i < n; i++) {
    c = getchar();
    if (c == '.') {
      b = 1;
      continue;
    }
    int x = c - '0';
    if (b) {
      r[rs++] = x;
    } else {
      l[ls++] = x;
    }
  }
  for (int i = 0; i < rs; i++) {
    if (r[i] >= 5) {
      rs = i;
      t--;
      go();
      break;
    }
  }
  while (rs && t != 0) {
    t--;
    if (r[rs - 1] >= 5) {
      rs--;
      if (rs == 0) break;
      go();
    }
  }
  if (rs == 0) {
    int x = go2();
    if (x) cout << 1;
  }
  for (int i = 0; i < ls; i++) {
    cout << l[i];
  }
  if (rs) cout << ".";
  for (int i = 0; i < rs; i++) cout << r[i];
}
