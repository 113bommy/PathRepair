#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T sqr(T x) {
  return x * x;
}
template <class T>
inline T lcm(T a, T b) {
  if (a < 0) return lcm(-a, b);
  if (b < 0) return lcm(a, -b);
  return a * (b / __gcd(a, b));
}
template <class T>
T power(T N, T P) {
  return (P == 0) ? 1 : N * power(N, P - 1);
}
template <class T>
string itoa(T a) {
  if (!a) return "0";
  string ret;
  for (T i = a; i > 0; i = i / 10) ret.push_back((i % 10) + 48);
  reverse(ret.begin(), ret.end());
  return ret;
}
double log(double N, double B) { return (log10l(N)) / (log10l(B)); }
vector<string> token(string a, string b) {
  const char *q = a.c_str();
  while (count(b.begin(), b.end(), *q)) q++;
  vector<string> oot;
  while (*q) {
    const char *e = q;
    while (*e && !count(b.begin(), b.end(), *e)) e++;
    oot.push_back(string(q, e));
    q = e;
    while (count(b.begin(), b.end(), *q)) q++;
  }
  return oot;
}
string toBin(int n) {
  string s;
  for (int i = 32 - 1; i >= 0; i--) s += ((bool)(n & (1 << (i))) + '0');
  return s;
}
bool eq(long double a, long double b) { return fabs(a - b) < 1e-9; }
int cum[200000];
int sum(int b, int e) {
  int ans = cum[e];
  if (b) ans -= cum[b - 1];
  return ans;
}
stack<char> st;
stack<int> pos;
void clear() {
  while ((int)st.size()) {
    st.pop();
    pos.pop();
  }
}
int sav[200000];
int main() {
  string s;
  cin >> s;
  for (int i = 0; i < (int)(int)s.size(); i++) {
    if (i == 0)
      cum[i] = (s[i] == '[');
    else
      cum[i] = cum[i - 1] + (s[i] == '[');
  }
  for (int i = 0; i < (int)(int)s.size(); i++) {
    if (s[i] == '(' or s[i] == '[') {
      st.push(s[i]);
      pos.push(i);
    } else {
      if (!(int)st.size()) continue;
      int a, b;
      if (s[i] == ']') {
        if (st.top() != '[') {
          clear();
          continue;
        }
      } else if (s[i] == ')') {
        if (st.top() != ')') {
          clear();
          continue;
        }
      }
      a = pos.top();
      b = i;
      pos.pop();
      st.pop();
      sav[a]++;
      sav[b + 1]--;
    }
  }
  int c = 0, flag = 0, B, E, maxi = 0, st, en;
  for (int i = 0; i < (int)(int)s.size(); i++) {
    c += sav[i];
    if (c > 0 and flag == 0) {
      st = i;
      flag = 1;
      continue;
    }
    if (c > 0 and flag == 1) continue;
    if (c == 0 and flag == 1) {
      flag = 0;
      en = i - 1;
      int op = sum(st, en);
      if (op >= maxi) {
        maxi = op;
        B = st;
        E = en;
      }
    }
  }
  if (c) {
    en = (int)s.size() - 1;
    int op = sum(st, en);
    if (op >= maxi) {
      maxi = op;
      B = st;
      E = en;
    }
  }
  cout << maxi << endl;
  if (maxi) {
    for (int i = (int)B; i <= (int)E; i++) cout << s[i];
    puts("");
  }
}
