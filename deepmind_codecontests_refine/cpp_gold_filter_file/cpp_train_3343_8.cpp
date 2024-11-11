#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int ans = 0, f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) ans = (ans << 3) + (ans << 1) + (c ^ 48);
  return ans * f;
}
int BASE = 113, mod = 19260817;
unsigned long long Hash[1000005], base[1000005];
long long Hash2[1000005], base2[1000005];
char s[100005], t[1000005];
int ls, lt;
unsigned long long table[5];
long long table2[5];
int valid(int st, int k, int len) {
  if (!table[k])
    return table[k] = Hash[st + len - 1] - Hash[st - 1] * base[len],
           table2[k] =
               ((Hash2[st + len - 1] - Hash2[st - 1] * base2[len]) % mod +
                mod) %
               mod,
           1;
  else
    return (Hash[st + len - 1] - Hash[st - 1] * base[len] == table[k]) &&
           (((Hash2[st + len - 1] - Hash2[st - 1] * base2[len]) % mod + mod) %
                mod ==
            table2[k]);
}
int check(int a, int b) {
  table[0] = table[1] = 0;
  table2[0] = table2[1] = 0;
  for (int i = 1, j, k = 1; i <= lt; i = j + 1, k++) {
    int t = s[k] - '0';
    j = i - 1 + (t ? b : a);
    if (!valid(i, t, (t ? b : a))) return 0;
  }
  if (table[0] == table[1] && table2[0] == table2[1]) return 0;
  return 1;
}
void init(int n) {
  base[0] = base2[0] = 1;
  for (int i = 1; i <= n; i++) {
    Hash[i] = Hash[i - 1] * BASE + t[i], base[i] = base[i - 1] * BASE;
    Hash2[i] = (Hash2[i - 1] * BASE % mod + t[i]) % mod,
    base2[i] = base2[i - 1] * BASE % mod;
  }
}
int main() {
  cin >> s + 1 >> t + 1;
  int a = 0, b = 0;
  int ans = 0;
  ls = strlen(s + 1), lt = strlen(t + 1);
  init(lt);
  for (int i = 1; i <= ls; i++) (s[i] == '0' ? ++a : ++b);
  for (int i = 1; i <= lt / a; i++) {
    int tmp = lt - a * i;
    if (!tmp) break;
    if (tmp % b == 0) {
      ans += check(i, tmp / b);
    }
  }
  cout << ans << endl;
  return 0;
}
