#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 5;
const int INF = 2e9;
const long long MOD = 1e9 + 7;
int arr[MAXN], N;
int calc(int pos, int diff) {
  int RES = 0;
  for (int i = 1; i <= N; i++)
    RES = max(RES, abs(pos + (i - 1) * diff - arr[i]));
  return RES;
}
struct res_type {
  int val, diff, ini;
} RES;
int main() {
  scanf("%d", &N);
  RES.val = INF;
  for (int i = 1; i <= N; i++) scanf("%d", &arr[i]);
  sort(arr + 1, arr + N + 1);
  for (int diff = 0; diff <= 5; diff++) {
    int L = -10000, R = 10000;
    while (R - L > 5) {
      int mid1 = L + (R - L) / 3;
      int mid2 = R - (R - L) / 3;
      if (calc(mid1, diff) > calc(mid2, diff))
        L = mid1;
      else
        R = mid2;
    }
    for (int i = L; i <= R; i++) {
      int val = calc(i, diff);
      if (val < RES.val) {
        RES.val = val;
        RES.diff = diff;
        RES.ini = i;
      }
    }
  }
  printf("%d\n", RES.val);
  printf("%d %d", RES.ini, RES.diff);
  return 0;
}
