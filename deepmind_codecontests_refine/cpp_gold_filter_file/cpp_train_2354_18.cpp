#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000005];
bool input() {
  if (scanf("%d", &n) == -1) return false;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  return true;
}
void solve() {
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] & 1) cnt++;
  }
  if (cnt > 0) {
    printf("First\n");
  } else {
    printf("Second\n");
  }
}
int main() {
  while (input()) {
    solve();
  }
  return 0;
}
