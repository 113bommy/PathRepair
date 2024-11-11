#include <bits/stdc++.h>
using namespace std;
const int MAX_N = int(4e5) + 7;
const int PRIME = 31;
int n, d, p[MAX_N];
char s[MAX_N], ans[MAX_N];
int hash_f[MAX_N], hash_b[MAX_N];
bool check(int i, int c) {
  ++i;
  int hf = hash_f[i] - hash_f[i - d - c];
  int hb = (hash_b[i] - hash_b[i - d - c] * p[d + c]) * p[i - d - c];
  return hf == hb;
}
bool solve(int pos, bool ok) {
  if (pos == n) return ok;
  char ch = ok ? 'a' : s[pos];
  for (; ch <= 'z'; ++ch) {
    ans[pos] = ch;
    hash_f[pos + 1] = hash_f[pos] + ans[pos] * p[pos + 1];
    hash_b[pos + 1] = hash_b[pos] * PRIME + ans[pos] * PRIME;
    if ((pos - d + 1 >= 0 && check(pos, 0)) ||
        (pos - d - 0 >= 0 && check(pos, 1)))
      continue;
    if (solve(pos + 1, ok || (ch > s[pos]))) return true;
  }
  return false;
}
int main() {
  scanf("%d %s", &d, s);
  n = strlen(s);
  p[0] = 1;
  for (int i = 1; i <= n; ++i) p[i] = p[i - 1] * PRIME;
  printf("%s\n", solve(0, 0) ? ans : "Impossible");
  return 0;
}
