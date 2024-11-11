#include <bits/stdc++.h>
using namespace std;
const int inf = ~0U >> 1;
const long long INF = ~0LLU >> 1;
int rd() { return RAND_MAX == 32767 ? ((rand() << 15) ^ rand()) : rand(); }
const int maxn = 1000010;
int d[3][3];
char s[maxn], t[maxn];
int h(char x) {
  if (x == 'G')
    return 0;
  else if (x == 'B')
    return 1;
  else
    return 2;
}
void Add(int &x) {
  d[h(t[x])][h(t[x + 1])]++;
  x++;
}
void Del(int &x) {
  d[h(t[x])][h(t[x + 1])]--;
  x++;
}
int main() {
  cin >> s >> t;
  int n = strlen(s), m = strlen(t);
  memset(d, 0, sizeof(d));
  int l = 0, r = 0;
  while (r + 1 < m && s[0] != t[r]) Add(r);
  long long res = r - l + 1;
  for (int i = 0; i + 1 < n; i++) {
    if (s[i] == t[r] && r + 1 < m) Add(r);
    while (s[i + 1] != t[r] && r + 1 < m) Add(r);
    if (s[i] == t[l] && l + 1 == m) break;
    if (s[i] == t[l]) Del(l);
    res += r - l + 1;
    if (s[i] != s[i + 1]) res -= d[h(s[i + 1])][h(s[i])];
  }
  cout << res << endl;
  return 0;
}
