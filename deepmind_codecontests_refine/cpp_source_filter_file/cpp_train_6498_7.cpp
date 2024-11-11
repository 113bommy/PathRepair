#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
const int N = 1005;
inline long long rd() {
  long long x = 0;
  char c = getchar();
  bool f = false;
  while (!isdigit(c)) {
    if (c == '-') f = true;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
  return f ? -x : x;
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long sqr(long long x) { return x * x; }
long long qpow(long long a, long long b, long long c) {
  long long ans = 1;
  a = a % c;
  while (b) {
    if (b % 2) ans = ans * a % c;
    b /= 2;
    a = a * a % c;
  }
  return ans;
}
char s[200005];
int vis[200005];
int pos[200005];
int main() {
  scanf("%s", s + 1);
  int len = strlen(s + 1);
  long long maxx = 0;
  int cnt = 0;
  for (int i = 1; i <= len - 4; i++) {
    if (s[i] == 'b' && s[i + 1] == 'e' && s[i + 2] == 'a' && s[i + 3] == 'r') {
      vis[i] = 1;
      pos[++cnt] = i;
    }
  }
  int tot = 0;
  for (int i = 1; i <= len - 4; i++) {
    if (vis[i]) {
      tot++;
      maxx += (long long)(pos[tot] - pos[tot - 1]) * (len - (i + 3) + 1);
    }
  }
  cout << (long long)maxx << endl;
  return 0;
}
