#include <bits/stdc++.h>
using namespace std;
long long memo[50][50][2][2];
bool mark[50][50][2][2];
long long f(const string& s, int begin, int end, int rev, int inv) {
  if (begin > end) return 1;
  long long& count = memo[begin][end][rev][inv];
  if (mark[begin][end][rev][inv]) return count;
  count = 0, mark[begin][end][rev][inv] = true;
  for (int k1 = 0; k1 < 2; ++k1)
    if (s[begin] != '1' - k1)
      for (int k2 = 0; k2 < 2; ++k2)
        if (s[end] != '1' - k2)
          if (begin != end || k1 == k2)
            if ((rev || k1 <= k2) && (inv || k1 <= 1 - k2)) {
              const int nrev = (rev || k1 < k2) ? 1 : 0;
              const int ninv = (inv || k1 < 1 - k2) ? 1 : 0;
              count += f(s, begin + 1, end - 1, nrev, ninv);
            }
  return count;
}
int main() {
  int n;
  long long k;
  scanf("%d %I64d", &n, &k);
  string s(n, '.');
  s[0] = '0';
  memset(mark, false, sizeof(mark));
  if (k < f(s, 0, n - 1, 0, 0)) {
    for (int i = 1; i < n; ++i)
      for (s[i] = '0'; s[i] < '1'; ++s[i]) {
        memset(mark, false, sizeof(mark));
        const long long next = f(s, 0, n - 1, 0, 0);
        if (k >= next)
          k -= next;
        else
          break;
      }
    printf("%s\n", s.c_str());
  } else
    printf("-1\n");
  return 0;
}
