#include <bits/stdc++.h>
using namespace std;
template <class T>
void debug(T a, T b) {
  ;
}
template <class T>
void chmin(T& a, const T& b) {
  if (a > b) a = b;
}
template <class T>
void chmax(T& a, const T& b) {
  if (a < b) a = b;
}
namespace std {
template <class S, class T>
ostream& operator<<(ostream& out, const pair<S, T>& a) {
  out << '(' << a.first << ',' << a.second << ')';
  return out;
}
}  // namespace std
long long int readL() {
  long long int res;
  scanf("%I64d", &res);
  return res;
}
void printL(long long int res) { printf("%I64d", res); }
int C = 26;
int n;
char s[300005];
int nxt[30][300005];
int pos[30];
long long int res[30];
int main() {
  scanf("%s", s);
  n = strlen(s);
  for (int i = 0; i < (C); ++i) nxt[i][n] = n;
  for (int i = n - 1; i >= 0; --i) {
    for (int j = 0; j < (C); ++j) {
      nxt[j][i] = nxt[j][i + 1];
      if (s[i] - 'a' == j) nxt[j][i] = i;
      pos[j] = nxt[j][i];
    }
    pos[C] = n;
    sort(pos, pos + C + 1);
    for (int j = 0; j < (C); ++j) {
      res[j + 1] += pos[j + 1] - pos[j];
    }
  }
  int diver = 0;
  for (int j = 0; j < (C); ++j)
    if (res[j] > 0) diver = j;
  cout << diver + 1 << endl;
  for (int j = 0; j < (diver); ++j) cout << res[j + 1] << endl;
  return 0;
}
