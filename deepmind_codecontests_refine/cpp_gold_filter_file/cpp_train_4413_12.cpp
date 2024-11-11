#include <bits/stdc++.h>
using namespace std;
int n, a, b;
int l[101];
int main() {
  scanf("%d", &n);
  int s = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &l[i]);
    s += l[i];
  }
  scanf("%d%d", &a, &b);
  int s0 = 0;
  if (a > b) swap(a, b);
  for (int i = a; i < b; i++) {
    s0 += l[i];
  }
  cout << min(s - s0, s0);
}
