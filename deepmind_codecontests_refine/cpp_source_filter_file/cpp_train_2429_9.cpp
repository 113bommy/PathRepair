#include <bits/stdc++.h>
int s, i, j, n, k, kx, ky;
char z;
std ::vector<char> a;
std ::vector<char> b;
void sol1() {
  for (i = 0; i < n; i++) {
    if (a[i] > b[i]) {
      printf("NO");
      return;
    }
  }
  printf("YES");
}
void sol() {
  getchar();
  for (i = 0; i < n; i++) {
    z = getchar();
    a.push_back(z);
  }
  for (i = 0; i < n; i++) {
    z = getchar();
    b.push_back(z);
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  for (i = 0; i < n; i++) {
    if (a[i] < b[i]) {
      sol1();
      return;
    }
  }
  printf("YES");
  return;
}
int main() {
#pragma comment(linker, "/STACK:16777216")
  while (scanf("%d", &n) != EOF) {
    sol();
  }
  return 0;
}
