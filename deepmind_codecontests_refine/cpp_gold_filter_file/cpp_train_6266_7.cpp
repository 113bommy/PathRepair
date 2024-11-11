#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, ans[N];
int main() {
  for (int i = 1, j = 2, cnt = 0; i < N && j < N; ++cnt) {
    ans[i] = ans[j] = 1;
    i = j * 2 - cnt % 2, j = i + 1;
  }
  scanf("%d", &n);
  printf("%d\n", ans[n]);
  return 0;
}
