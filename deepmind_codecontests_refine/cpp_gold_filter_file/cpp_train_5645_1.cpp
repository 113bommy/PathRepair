#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline long long squ(T x) {
  return (long long)x * x;
}
template <typename T>
inline bool chkmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
template <typename T>
inline bool chkmin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T>
inline T read() {
  T sum = 0, fg = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') fg = -1;
  for (; isdigit(c); c = getchar()) sum = (sum << 3) + (sum << 1) + (c ^ 0x30);
  return fg * sum;
}
const int maxn = 2e5 + 10;
char S[maxn];
int n, m, cnt[26][maxn];
int main() {
  scanf("%s", S + 1), n = strlen(S + 1);
  for (int i = 1; i <= n; i++) {
    ++cnt[S[i] - 'a'][i];
    for (int j = 0; j < 26; j++) cnt[j][i] += cnt[j][i - 1];
  }
  m = read<int>();
  while (m--) {
    int l = read<int>(), r = read<int>();
    if (l == r) {
      printf("Yes\n");
    } else {
      if (S[l] != S[r])
        printf("Yes\n");
      else {
        int Sum = 0;
        for (int j = 0; j < 26; j++) {
          if (j == S[l] - 'a') continue;
          Sum += min(cnt[j][r] - cnt[j][l - 1], 1);
        }
        if (Sum >= 2)
          printf("Yes\n");
        else
          printf("No\n");
      }
    }
  }
  return 0;
}
