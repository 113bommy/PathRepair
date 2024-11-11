#include <bits/stdc++.h>
using namespace std;
namespace shyutsuryoku {
const int STRSZ = 3e6 + 13;
char inbufer[STRSZ];
inline void cscan(string& i) {
  int c = getc(stdin), cnt = 0;
  while (c <= 32) c = getc(stdin);
  while (c > 32) *(inbufer + cnt) = c, c = getc(stdin), ++cnt;
  *(cnt + inbufer) = 0;
  i = inbufer;
}
inline void cprint(string& i) {
  char* second = new char[i.size() + 1];
  strcpy(second, i.c_str());
  while (*second) putchar(*second), second++;
}
inline void cprint(const char*& i) {
  int cnt = 0;
  while (*(i + cnt)) putc(*(i + cnt), stdout), cnt++;
}
inline void cscan(int& i) {
  i = 0;
  int c = getc(stdin), b = 0;
  while (c <= 32) c = getc(stdin);
  if (c == '-') b = 1, c = getc(stdin);
  while (c >= '0' && c <= '9') i *= 10, i += c - '0', c = getc(stdin);
  if (b) i = -i;
}
inline void cprint(int i) {
  if (i < 0) putc('-', stdout), i = -i;
  int sz = 0;
  char ans[12];
  while (i || !sz) ans[sz++] = i % 10 + '0', i /= 10;
  while (sz--) putc(ans[sz], stdout);
}
inline void cscan(long long& i) {
  i = 0;
  int c = getc(stdin), b = 1;
  while (c <= 32) c = getc(stdin);
  if (c == '-') b = -1, c = getc(stdin);
  while (c >= '0' && c <= '9') i *= 10, i += c - '0', c = getc(stdin);
  i *= b;
}
inline void cprint(long long i) {
  if (i < 0) putc('-', stdout), i = -i;
  int sz = 0;
  char ans[21];
  while (i || !sz) ans[sz++] = i % 10 + '0', i /= 10;
  while (sz--) putc(ans[sz], stdout);
}
inline void cscan(unsigned& i) {
  i = 0;
  int c = getc(stdin);
  while (c <= 32) c = getc(stdin);
  while (c >= '0' && c <= '9') i *= 10, i += c - '0', c = getc(stdin);
}
inline void cprint(unsigned i) {
  int sz = 0;
  char ans[12];
  while (i || !sz) ans[sz++] = i % 10 + '0', i /= 10;
  while (sz--) putc(ans[sz], stdout);
}
inline void cscan(unsigned long long& i) {
  i = 0;
  int c = getc(stdin);
  while (c <= 32) c = getc(stdin);
  while (c >= '0' && c <= '9') i *= 10, i += c - '0', c = getc(stdin);
}
inline void cprint(unsigned long long i) {
  int sz = 0;
  char ans[21];
  while (i || !sz) ans[sz++] = i % 10 + '0', i /= 10;
  while (sz--) putc(ans[sz], stdout);
}
inline void cscan(double& i) { scanf("%lf", &i); }
inline void cprint(double i) { printf("%lf", i); }
inline void cprint(char i) { putc(i, stdout); }
inline void cscan(char& i) {
  int b = getc(stdin);
  while (b <= 32) b = getc(stdin);
  i = b;
}
template <class T, class K>
inline void cscan(pair<T, K>& i) {
  cscan(i.first);
  cscan(i.second);
}
template <class T, class K>
inline void cprint(pair<T, K>& i) {
  cprint('(');
  cprint(i.first);
  cprint(' ');
  cprint(i.second);
  cprint(')');
}
template <class T>
inline void cscan(vector<T>& i) {
  for (auto& j : i) cscan(j);
}
template <class T>
inline void cprint(vector<T>& i) {
  for (auto& j : i) cprint(j), cprint(' ');
}
template <class T>
inline void cprint(vector<vector<T> >& i) {
  for (auto& j : i) cprint(j), cprint('\n');
}
template <class T>
ostream& operator,(ostream& os, T v) {
  cprint(v);
  return os;
}
template <class T>
istream& operator,(istream& is, T& v) {
  cscan(v);
  return is;
}
}  // namespace shyutsuryoku
using namespace shyutsuryoku;
void AnimeConservativeRevolution();
int main() {
  srand(time(0));
  AnimeConservativeRevolution();
  return 0;
}
const int mod = 998244353;
bool us[(int)2e5 + 13];
vector<int> g[(int)2e5 + 13];
long long ans = 1;
long long fac(int v) {
  if (v == 1) return 1;
  return (fac(v - 1) * v) % mod;
}
void AnimeConservativeRevolution() {
  int n;
  cin, n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin, u, v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    ans = (ans * fac((int)g[i].size())) % mod;
  }
  cout, ans* n;
}
