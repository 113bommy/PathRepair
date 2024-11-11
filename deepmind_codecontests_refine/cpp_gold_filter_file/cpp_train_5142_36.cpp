#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:200000000")
using namespace std;
template <typename T>
inline T Abs(T x) {
  return (x >= 0) ? x : -x;
}
template <typename T>
inline T sqr(T x) {
  return x * x;
}
template <typename T>
inline string toStr(T x) {
  stringstream st;
  st << x;
  string s;
  st >> s;
  return s;
}
template <typename T>
inline int bit(T mask, int b) {
  return (b >= 0 && (mask & (T(1) << b)) != 0) ? 1 : 0;
}
inline int nextInt() {
  int x;
  if (scanf("%d", &x) != 1) throw;
  return x;
}
inline long long nextInt64() {
  long long x;
  if (scanf("%I64d", &x) != 1) throw;
  return x;
}
inline double nextDouble() {
  double x;
  if (scanf("%lf", &x) != 1) throw;
  return x;
}
const int INF = (int)1E9;
const long long INF64 = (long long)1E18;
const long double EPS = 1E-9;
const long double PI = 3.1415926535897932384626433832795;
const string Z[] = {">>", "<>"};
struct operation {
  string a, b;
  int type;
  operation(string a, int type, string b) : a(a), type(type), b(b) {}
  string process(string s, bool &end) {
    end = false;
    if (s.find(a) == string::npos) return s;
    int pos = (int)s.find(a);
    string pref = s.substr(0, pos);
    string suff = s.substr(pos + (int)a.size());
    end = (type == 1);
    return pref + b + suff;
  }
};
vector<operation> a;
string process(string s) {
  set<string> used;
  while (true) {
    if (used.count(s)) return "ZZZZZ";
    used.insert(s);
    bool changed = false;
    for (int i = 0; i < (int)(a.size()); i++) {
      bool end = false;
      string ss = a[i].process(s, end);
      if (ss != s) {
        if (end) return ss;
        changed = true;
        s = ss;
        break;
      }
    }
    if (!changed) break;
  }
  return s;
}
int main() {
  a.push_back(operation("9??", 0, "??0"));
  for (int i = 0; i < (int)(9); i++)
    a.push_back(operation(toStr(i) + "??", 1, toStr(i + 1)));
  a.push_back(operation("??", 1, "1"));
  for (int i = 0; i < (int)(10); i++)
    a.push_back(operation("?" + toStr(i), 0, toStr(i) + "?"));
  a.push_back(operation("?", 0, "??"));
  for (int i = 0; i < (int)(10); i++)
    a.push_back(operation(toStr(i), 0, toStr(i) + "?"));
  for (int i = 0; i < (int)(a.size()); i++)
    cout << a[i].a << Z[a[i].type] << a[i].b << endl;
  return 0;
}
