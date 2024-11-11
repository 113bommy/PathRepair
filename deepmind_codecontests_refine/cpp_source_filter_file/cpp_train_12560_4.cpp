#include <bits/stdc++.h>
using namespace std;
const double pi = 3.1415926535897932384626433832795;
const double eps = 1e-12;
const int INF = 1 << 30;
const long long LINF = 1ll << 60;
const int BUFFER_SZ = 1 << 20;
const int MOD = 1000 * 1000 * 1000 + 7;
char BUFFER[BUFFER_SZ];
int gi() {
  int x;
  scanf("%d", &x);
  return x;
}
long long gll() {
  long long x;
  scanf("%lld", &x);
  return x;
}
vector<int> gvi(int n) {
  vector<int> a;
  while (n-- > 0) a.push_back(gi());
  return a;
}
string gs() {
  scanf("%s", BUFFER);
  return string(BUFFER);
}
template <class T>
void print(vector<T> &x, string format) {
  format += "%c";
  for (int i = 0; i < x.size(); ++i)
    printf(format.c_str(), x[i], i + 1 == x.size() ? '\n' : ' ');
}
struct strun {
  vector<int> rightA;
  vector<int> SUMnotA;
  strun(string s) {
    int sum = 0;
    int a = 0;
    for (int i = 0; i < s.size(); ++i) {
      sum += s[i] != 'A' ? 1 : 0;
      SUMnotA.push_back(sum);
      if (s[i] != 'A')
        a = 0;
      else
        ++a;
      rightA.push_back(a);
    }
  }
  int getA(int l, int r) { return min(r - l + 1, rightA[r]); }
  int getNA(int l, int r) { return SUMnotA[r] - (l > 0 ? SUMnotA[l - 1] : 0); }
};
set<string> S;
void dfs(string s) {
  if (s.size() > 10) return;
  if (S.count(s)) return;
  S.insert(s);
  for (int i = 0; i < (int)s.size() - 3 + 1; ++i) {
    if (s[i] == 'A' && s[i + 1] == 'A' && s[i + 2] == 'A') {
      dfs(s.substr(0, i) + s.substr(i + 3));
    }
  }
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == 'A') dfs(s.substr(0, i) + "BC" + s.substr(i + 1));
    if (s[i] == 'B') dfs(s.substr(0, i) + "AC" + s.substr(i + 1));
    if (s[i] == 'C') dfs(s.substr(0, i) + "AB" + s.substr(i + 1));
  }
}
void solve() {
  string s = gs();
  string t = gs();
  strun S(s);
  strun T(t);
  int n = gi();
  for (int i = 0; i < n; ++i) {
    int a = gi() - 1;
    int b = gi() - 1;
    int c = gi() - 1;
    int d = gi() - 1;
    int a1 = S.getA(a, b);
    int a2 = T.getA(c, d);
    int b1 = S.getNA(a, b);
    int b2 = T.getNA(c, d);
    if (b1 % 2 != b2 % 2 || b1 > b2)
      printf("0");
    else if (b1 == b2) {
      if (a1 < a2 || a1 % 3 != a2 % 3)
        printf("0");
      else
        printf("1");
    } else {
      if (a1 < a2)
        printf("0");
      else if (a1 == a2 && b1 == 0 && b2 != 0)
        printf("1");
      else if (a1 % 3 != a2 % 3 && b1 + 2 > b2)
        printf("0");
      else
        printf("1");
    }
  }
  printf("\n");
}
int main() {
  solve();
  return 0;
}
