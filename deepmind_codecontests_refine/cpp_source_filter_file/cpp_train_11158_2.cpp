#include <bits/stdc++.h>
using namespace std;
const long double pi = acos(-1);
const long long inf = 1LL << 30;
const double eps = 1e-9;
const long long mod = 1e9 + 7;
const int N = 0;
int c[] = {'a', 'b', 'c'};
char a[3], b[3];
int n;
bool ok(string s) {
  for (int i = 0; i < 3 * n - 1; i++) {
    if (s[i] == a[0] && s[i + 1] == a[1]) return 0;
    if (s[i] == b[0] && s[i + 1] == b[1]) return 0;
  }
  return 1;
}
int main() {
  scanf("%d", &n);
  scanf("%s %s", &a, &b);
  do {
    string s = "";
    for (int i = 0; i < n; i++) s += c[0];
    for (int i = 0; i < n; i++) s += c[1];
    for (int i = 0; i < n; i++) s += c[2];
    if (ok(s)) {
      printf("YES\n");
      printf("%s", s.c_str());
      return 0;
    }
    s = "";
    for (int i = 0; i < n; i++) s += c[0];
    for (int i = 0; i < 2 * n; i++)
      if (i & 1)
        s += c[1];
      else
        s += c[2];
    if (ok(s)) {
      printf("YES\n");
      printf("%s", s.c_str());
      return 0;
    }
    s = "";
    for (int i = 0; i < 2 * n; i++)
      if (i & 1)
        s += c[0];
      else
        s += c[1];
    for (int i = 0; i < n; i++) s += c[2];
    if (ok(s)) {
      printf("YES\n");
      printf("%s", s.c_str());
      return 0;
    }
  } while (next_permutation(a, a + 3));
  printf("NO");
  return 0;
}
