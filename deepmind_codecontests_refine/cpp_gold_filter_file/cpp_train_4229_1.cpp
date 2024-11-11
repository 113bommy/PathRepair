#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  long long L;
  scanf("%d%I64d", &n, &L);
  int a[100001];
  int l = 0, h = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    if (h < a[i]) h = a[i];
  }
  long long s = 0LL;
  while (l < h) {
    int mid = (l + h + 1) / 2;
    long long sum = 0LL;
    for (int i = 0; i < n; i++) {
      if (mid > a[i])
        sum += a[i];
      else
        sum += mid;
    }
    if (sum > L)
      h = mid - 1;
    else {
      l = mid;
      s = sum;
    }
  }
  long long sum = 0LL;
  for (int i = 0; i < n; i++) sum += a[i];
  if (sum < L)
    printf("-1");
  else {
    queue<int> Q;
    queue<int> P;
    for (int i = 0; i < n; i++)
      if (a[i] > l) {
        Q.push(a[i] - l);
        P.push(i);
      }
    for (int i = 0; i < (L - s); i++) {
      int b = Q.front();
      int c = P.front();
      Q.pop();
      P.pop();
      if (b > 1) {
        P.push(c);
        Q.push(b - 1);
      }
    }
    while (!P.empty()) {
      int b = P.front();
      printf("%d ", b + 1);
      P.pop();
    }
  }
  return 0;
}
