#include <bits/stdc++.h>
using namespace std;
const int B = 1000000007;
const int N = 1000000;
int d[N + 1];
int pop(int i) {
  int a = 0;
  for (; i > 0; i -= i & (-i)) a = (a + d[i]) % B;
  return a;
}
int push(int i, int a) {
  a = (a + B - pop(i) + pop(i - 1)) % B;
  for (; i <= N; i += i & (-i)) d[i] = (d[i] + a) % B;
  return 0;
}
int n, a, r;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a);
    int r = int64_t(a) * (pop(a) + 1LL) % B;
    push(a, r);
  }
  printf("%d", pop(N));
  return 0;
}
