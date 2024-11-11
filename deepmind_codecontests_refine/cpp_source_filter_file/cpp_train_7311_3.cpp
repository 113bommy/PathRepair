#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
template <typename T>
inline T read() {
  T ans = 0, flag = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') flag = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    ans = ans * 10 + c - 48;
    c = getchar();
  }
  return ans * flag;
}
int n;
long long s[maxn], a[maxn];
int cnt[maxn];
int main() {
  n = read<int>();
  for (register int i(1), end_i(n); i <= end_i; i++) {
    s[i] = s[i - 1] + read<int>();
    a[i] = s[i];
  }
  sort(a, a + 1 + n);
  int m = unique(a, a + 1 + n) - a;
  for (register int i(1), end_i(n); i <= end_i; i++)
    s[i] = lower_bound(a, a + 1 + m, s[i]) - a;
  cnt[s[0]] = 1;
  int j = 0;
  long long ans = 0;
  for (register int i(1), end_i(n); i <= end_i; i++) {
    cnt[s[i]]++;
    while (cnt[s[i]] > 1) cnt[s[j++]]--;
    ans += i - j;
  }
  cout << ans << endl;
  return 0;
}
