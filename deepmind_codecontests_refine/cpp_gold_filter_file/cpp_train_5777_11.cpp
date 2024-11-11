#include <bits/stdc++.h>
using namespace std;
int N;
void read() { scanf("%d", &N); }
int a[1000000];
int abs(int x) { return x > 0 ? x : -x; }
void solve() {
  if (N == 4) {
    printf("4\n3 1 4 2\n");
    return;
  }
  int idx = 0;
  for (int i = 1; i <= N; i += 2) a[idx++] = i;
  for (int j = 2; j <= N; j += 2)
    if (abs(a[idx - 1] - j) > 1) a[idx++] = j;
  printf("%d\n", idx);
  for (int i = 0; i < idx; i++) printf("%d ", a[i]);
}
int main() {
  read();
  solve();
  return 0;
}
