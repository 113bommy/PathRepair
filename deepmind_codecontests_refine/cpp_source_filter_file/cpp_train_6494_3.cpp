#include <bits/stdc++.h>
using namespace std;
double EPS = 1e-9;
int INF = 2000000000;
long long INFF = 8000000000000000000LL;
double PI = acos(-1);
int dirx[8] = {-1, 0, 0, 1, -1, -1, 1, 1};
int diry[8] = {0, 1, -1, 0, -1, 1, -1, 1};
inline string IntToString(int a) {
  char x[100];
  sprintf(x, "%d", a);
  string s = x;
  return s;
}
inline int StringToInt(string a) {
  char x[100];
  int res;
  strcpy(x, a.c_str());
  sscanf(x, "%d", &res);
  return res;
}
inline string GetString(void) {
  char x[1000005];
  scanf("%s", x);
  string s = x;
  return s;
}
inline string uppercase(string s) {
  int n = (int)s.size();
  for (int(i) = (0); (i) < (n); ++(i))
    if (s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 'a' + 'A';
  return s;
}
inline string lowercase(string s) {
  int n = (int)s.size();
  for (int(i) = (0); (i) < (n); ++(i))
    if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
  return s;
}
inline void OPEN(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}
string s;
int a, b, h, q, n, m;
void no(void) {
  puts("NO");
  exit(0);
}
void yes(void) {
  puts("YeS");
  exit(0);
}
inline bool square(int n) {
  int k = (int)sqrt(n);
  return (k * k == n);
}
inline bool ok(string t) {
  int res = 0;
  for (int(i) = (0); (i) < (m); ++(i))
    if (t[i] == 'H')
      ++res;
    else
      res += m;
  if (res != n) return false;
  string tmp = "";
  for (int(i) = (0); (i) < (m); ++(i))
    if (t[i] == 'H')
      tmp += 'H';
    else
      tmp += t;
  return (tmp == s);
}
int main() {
  string cek = "";
  s = GetString();
  n = (int)s.size();
  for (int(i) = (0); (i) < (n); ++(i))
    if (s[i] == 'H')
      ++h;
    else
      ++q;
  if (!square(q)) no();
  b = (int)sqrt(q);
  if (h % (1 + b) != 0) no();
  a = h / (1 + b);
  m = a + b;
  for (int(i) = (0); (i) < (n); ++(i))
    if (s[i] == 'Q') {
      if (i % 2 == 1) no();
      int k = i / 2;
      for (int(j) = (k); (j) < (k + m); ++(j)) cek += s[j];
      if (ok(cek)) yes();
      no();
    }
  yes();
  return 0;
}
