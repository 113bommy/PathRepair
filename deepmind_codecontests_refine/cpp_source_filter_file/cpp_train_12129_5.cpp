#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:20000000")
int n;
int a1[1010];
int a2[1010];
int b[1010];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    scanf("%d", &a1[i]);
  }
  for (int i = 1; i < n; i++) {
    scanf("%d", &a2[i]);
  }
  for (int i = 1; i < n; i++) a1[i] += a1[i - 1];
  for (int i = n - 1; i >= 1; i--) a2[i] += a2[i + 1];
  for (int i = 0; i < n; i++) scanf("%d", &b[i]);
  int res1 = 1e9;
  int res2 = 1e9;
  for (int i = 0; i < n; i++) {
    int val = a1[i] + b[i] + a2[i + 1];
    if (val < res2) swap(val, res2);
    if (res2 < res1) swap(res1, res2);
  }
  printf("%d %d", res1 + res2);
  return 0;
}
