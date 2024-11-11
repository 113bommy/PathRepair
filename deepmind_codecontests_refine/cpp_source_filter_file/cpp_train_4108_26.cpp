#include <bits/stdc++.h>
using namespace std;
int n;
long long res;
int Cnt[100005];
long long T[100005];
long long DP[100005];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &T[i]);
    Cnt[T[i]]++;
  }
  sort(T + 1, T + n + 1);
  for (int i = 1; i <= n; i++) {
    DP[i] = max(DP[i - 1], DP[max(0, i - 2)] + (long long)Cnt[i] * i);
    res = max(res, DP[i]);
  }
  printf("%lld\n", res);
}
