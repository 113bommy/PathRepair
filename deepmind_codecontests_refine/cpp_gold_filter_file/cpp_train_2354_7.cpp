#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int a[N];
int main() {
  int n, f = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (a[i] & 1) f = 1;
  }
  printf(f ? "First" : "Second");
  return 0;
}
