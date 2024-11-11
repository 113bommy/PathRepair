#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5 * 1e5 + 10;
int a[MAXN], numl[MAXN], numr[MAXN];
map<int, int> cnt;
long long suml[MAXN], sumr[MAXN];
int main() {
  int n, k;
  while (scanf("%d%d", &n, &k) != EOF) {
    cnt.clear();
    long long total = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      cnt[a[i]]++;
      total += a[i];
    }
    sort(a + 1, a + n + 1);
    int N = unique(a + 1, a + n + 1) - a - 1;
    int L = -1, R = -1;
    numl[0] = 0;
    suml[0] = 0;
    a[0] = a[1];
    for (int i = 1; i <= N; i++) {
      numl[i] = numl[i - 1] + cnt[a[i]];
      suml[i] = suml[i - 1] + 1LL * numl[i - 1] * (a[i] - a[i - 1]);
      if (suml[i] > k && L == -1) L = i - 1;
    }
    numr[N + 1] = 0;
    sumr[N + 1] = 0;
    a[N + 1] = a[N];
    for (int i = N; i >= 1; i--) {
      numr[i] = numr[i + 1] + cnt[a[i]];
      sumr[i] = sumr[i + 1] + 1LL * numr[i + 1] * (a[i + 1] - a[i]);
      if (sumr[i] > k && R == -1) R = i + 1;
    }
    if (L >= R) {
      printf(total % n ? "1\n" : "0\n");
    } else {
      int Min = a[L] + (k - suml[L]) / numl[L];
      int Max = a[R] - (k - sumr[R]) / numr[R];
      if (Min >= Max) {
        printf(total % n ? "1\n" : "0\n");
      } else {
        printf("%d\n", Max - Min);
      }
    }
  }
  return 0;
}
