#include <bits/stdc++.h>
using namespace std;
int a[200000];
int c[200010];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    c[a[i]]++;
  }
  int l = 0, r = -1, lm = 0, rm = -1, cnt = 0, mm = -1;
  for (int i = 0; i < 200000; i++) {
    r++;
    if (c[i] < 2) {
      cnt += c[i];
      if (cnt > mm) {
        lm = l;
        rm = r;
        mm = cnt;
      }
      cnt = c[i];
      l = i;
      r = i;
      continue;
    }
    cnt += c[i];
  }
  if (cnt > mm) {
    lm = l;
    rm = r;
    mm = cnt;
  }
  while (c[lm] == 0) lm++;
  while (c[rm] == 0) rm--;
  int ma;
  cout << mm << '\n';
  for (int i = lm; i <= rm; i++) {
    ma = c[i] / 2 + c[i] % 2;
    c[i] -= ma;
    for (int j = 0; j < ma; j++) {
      cout << i << ' ';
    }
  }
  for (int i = rm; i >= lm; i--) {
    for (int j = 0; j < c[i]; j++) {
      cout << i << ' ';
    }
  }
  return 0;
}
