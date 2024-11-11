#include <bits/stdc++.h>
using namespace std;
const int month[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
template <class T>
int cntb(T i) {
  int ret = 0;
  while (i) i = (i - 1) & i, ret++;
  return ret;
}
template <class T>
int cntlz(T i) {
  int ret = 0;
  while (!((i) & (1 << 0)) && i) i /= 2, ret++;
  return ret;
}
template <class T>
T gcd(T a, T b) {
  return (b == 0) ? a : gcd(b, a % b);
}
template <class T>
void frstring(string s, T& r) {
  r = 0;
  istringstream ci(s);
  ci >> r;
}
template <class T>
string tostring(T n) {
  ostringstream co;
  co << n;
  co.flush();
  return co.str();
}
template <class T>
T bigmod(T x, T n, T m) {
  T ret = 1;
  while (n > 0) {
    if (n % 2 == 1) ret = (ret * x) % m;
    x = (x * x) % m;
    n /= 2;
  }
  return ret;
}
vector<string> token(char* ch, const char* tk) {
  vector<string> r;
  char* p = strtok(ch, tk);
  while (p) {
    r.push_back(p);
    p = strtok(NULL, tk);
  }
  return r;
}
vector<string> token(string s, string tk) {
  char t[100005];
  strcpy(t, s.c_str());
  return token(t, tk.c_str());
}
int main() {
  int i, j, k;
  int a, b, c;
  vector<int> fs(100005, 0), sc(100005, 0);
  int n;
  cin >> n;
  for (i = (0); i < (n); i++) {
    cin >> a;
    if (fs[a] == 0) fs[a] = i + 1;
    sc[a] = i + 1;
  }
  long long cnt1 = 0, cnt2 = 0;
  int m;
  cin >> m;
  for (i = (0); i < (m); i++) {
    cin >> a;
    if (fs[a] == 0) fs[a] = n;
    cnt1 += (fs[a]);
    if (sc[a] == 0) sc[a] = n;
    cnt2 += (n - sc[a] + 1);
  }
  cout << cnt1 << " " << cnt2 << endl;
  return 0;
}
