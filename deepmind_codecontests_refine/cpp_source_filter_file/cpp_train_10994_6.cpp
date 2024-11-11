#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
const int MX = 1e9 + 7;
const int inf = 1e9 + 9;
const int mask = (1 << 19);
int n, m;
int dp[mask];
int exist[N];
map<int, int> M;
int findMeks(int val) {
  if (val < mask) return dp[val];
  bool meksik[31];
  for (int i = 0; i < 31; ++i) meksik[i] = false;
  for (int j = 0; j < 30; ++j) {
    int cur = (val >> (j + 1)) | (val & ((1 << j) - 1));
    if (cur != val) meksik[findMeks(cur)] = true;
  }
  for (int i = 0; i < 31; ++i)
    if (!meksik[i]) return i;
}
void rozloz(int x) {
  for (int i = 2; i * i <= x; ++i) {
    int cur = 0;
    while (x % i == 0) {
      x /= i;
      ++cur;
    }
    if (cur) M[i] |= 1 << cur;
  }
  if (x > 1) M[x] |= 1;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    rozloz(x);
  }
  dp[0] = 0;
  for (int i = 1; i < mask; ++i) {
    for (int j = 0; j < 19; ++j) {
      int cur = (i >> (j + 1)) | (i & ((1 << j) - 1));
      if (cur != i) exist[dp[cur]] = i;
    }
    for (int j = 0; j < 20; ++j)
      if (exist[j] < i) {
        dp[i] = j;
        break;
      }
  }
  int ksor = 0;
  for (pair<int, int> v : M) ksor ^= findMeks(v.second);
  if (ksor == 0)
    puts("Arpa");
  else
    puts("Mojtaba");
  return 0;
}
