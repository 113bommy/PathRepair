#include <bits/stdc++.h>
using namespace std;
int a[222222];
int b[222222];
int p[222222];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    --a[i];
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &b[i]);
    --b[i];
    p[b[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    b[i] = p[a[i]];
  }
  for (int i = 0; i + 1 < n; i++) {
    if (b[i + 1] < b[i]) {
      cout << n - 1 - i;
      return 0;
    }
  }
  cout << 0;
  return 0;
}
