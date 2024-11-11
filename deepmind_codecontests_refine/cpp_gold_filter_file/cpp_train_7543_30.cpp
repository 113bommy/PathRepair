#include <bits/stdc++.h>
using namespace std;
const int inf = 987654321;
const long long int INF = 123456789987654321;
int N;
vector<int> arr, chk, chk2;
bool f(int l, int r) {
  for (int i = 0; i < min(l, N - r - 1); i++) {
    if (arr[i] != arr[N - i - 1]) return false;
  }
  chk = vector<int>(N, 0);
  for (int i = min(l, N - r - 1); i <= max(r, N - l - 1); i++) {
    chk[arr[i]]++;
  }
  chk2 = vector<int>(N, 0);
  int len = max(r, N - l - 1) - min(l, N - r - 1) + 1;
  if (len < 2 * (r - l + 1)) {
    for (int i = min(l, N - r - 1); i <= max(r, N - l - 1); i++) {
      if (i < l || r < i) {
        chk2[arr[i]]++;
        if (chk2[arr[i]] > chk[arr[i]] / 2) return false;
      }
    }
  } else {
    for (int i = min(l, N - r - 1); i < min(l, N - r - 1) + (r - l + 1); i++) {
      chk2[arr[i]]++;
    }
    for (int i = min(l, N - r - 1); i < min(l, N - r - 1) + (r - l + 1); i++) {
      chk2[arr[N - 1 - i]]--;
    }
    for (int i = 0; i < N; i++) {
      if (chk2[i]) return false;
    }
    for (int i = min(l, N - r - 1) + (r - l + 1);
         i <= max(r, N - l - 1) - (r - l + 1); i++) {
      if (arr[i] != arr[N - 1 - i]) return false;
    }
  }
  return true;
}
long long int ans = 0;
int main() {
  scanf("%d", &N);
  arr.resize(N);
  chk = vector<int>(N, 0);
  for (int i = 0; i < N; i++) {
    scanf("%d", &arr[i]);
    chk[--arr[i]]++;
  }
  if (N == 1) {
    printf("1");
    return 0;
  }
  int oddcnt = 0;
  for (int i = 0; i < N; i++) {
    if (chk[i] % 2) oddcnt++;
  }
  if (oddcnt > 1) {
    printf("0");
    return 0;
  }
  int s = 0, e = N - 1;
  int idx;
  while (s <= e) {
    int m = (s + e) >> 1;
    if (f(0, m)) {
      idx = m;
      e = m - 1;
    } else
      s = m + 1;
  }
  s = 0, e = N - 1;
  int idx2;
  while (s <= e) {
    int m = (s + e) >> 1;
    if (f(m, N - 1)) {
      idx2 = m;
      s = m + 1;
    } else
      e = m - 1;
  }
  int len = 0;
  for (int i = 0; i < N / 2; i++) {
    if (arr[i] != arr[N - 1 - i]) break;
    len++;
  }
  if (len == N / 2) {
    printf("%I64d", (long long int)N * (N + 1) / 2);
    return 0;
  }
  long long int ans = len * len;
  if (idx < N - len) ans += (len + 1) * (N - len - idx);
  if (len <= idx2) ans += (len + 1) * (idx2 - len + 1);
  if (idx < N - len && len <= idx2) ans--;
  printf("%I64d", ans);
}
