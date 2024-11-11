#include <bits/stdc++.h>
using namespace std;
unsigned long long n, p[1000005], ans, l, h[1000005], db[1000005], f;
char s[1000005];
void hhash(unsigned long long x) {
  for (unsigned long long i = 1; i < l; i++) {
    if (i + x - 1 >= l - 1) return;
    unsigned long long sum = h[x - 1];
    if (h[i + x - 1] - h[i - 1] * db[x] == sum) {
      for (unsigned long long k = 0; k < x; k++) cout << s[k];
      f = 1;
      return;
    }
  }
}
void aaa() {
  for (unsigned long long i = 1; i < l; i++) {
    unsigned long long j = p[i - 1];
    while (j > 0 && s[j] != s[i]) j = p[j - 1];
    if (s[j] == s[i]) j++;
    p[i] = j;
  }
  unsigned long long j = p[l - 1];
  while (j > 0) {
    hhash(j);
    if (f == 1)
      return;
    else
      j = p[j - 1];
  }
}
signed main() {
  cin >> s;
  l = strlen(s);
  db[0] = 1;
  for (unsigned long long i = 1; i <= l; i++) db[i] = db[i - 1] * 27;
  h[0] = s[0] - 'a' + 1;
  for (unsigned long long i = 1; i < l; i++)
    h[i] = h[i - 1] * 27 + s[i] - 'a' + 1;
  aaa();
  if (f == 0) cout << "Just a legend\n";
  return 0;
}
