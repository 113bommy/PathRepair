#include <bits/stdc++.h>
const int N = 1000010;
int a[N];
int prime[N];
int P;
int fuPi(int a) {
  for (int i = 0; i < P; i++)
    if (prime[i] >= a) return i;
  return -1;
}
int fdPi(int b) {
  for (int i = P - 1; i >= 0; i--)
    if (prime[i] <= b) return i;
  return -1;
}
int max(int a, int b) { return a > b ? a : b; }
int islok(int a, int b, int k) {
  int head = fuPi(a), end = fdPi(b);
  if (head == -1) return -1;
  if (end - head + 1 < k) return -1;
  int ans = 0;
  if (k == 1) {
    ans = max(ans, prime[head] - a - 1);
    ans = max(ans, b - prime[end] - 1);
    for (int i = head; i < end; i++)
      ans = max(ans, prime[i + 1] - prime[i] - 1);
    return ans;
  }
  for (int i = head; i + k - 2 <= end; i++) {
    int be = (i == head) ? a : (prime[i - 1] + 1);
    int ee = ((i + k - 2) == end) ? b : (prime[i + k - 1] - 1);
    ans = max(ee - be + 1, ans);
  }
  return ans;
}
int main() {
  for (int i = 2; i <= N; i++) {
    if (a[i] == 0) {
      a[i] = i;
      if (i < 1000)
        for (int j = i * i; j <= N; j += i) a[j] = i;
      prime[P++] = i;
    }
  }
  int a, b, k;
  int l;
  while (~scanf("%d %d %d", &a, &b, &k)) {
    int ans = islok(a, b, k) + 1;
    if (ans != 0)
      printf("%d\n", ans);
    else
      puts("-1");
  }
}
