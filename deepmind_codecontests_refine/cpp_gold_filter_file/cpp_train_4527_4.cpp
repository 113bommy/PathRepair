#include <bits/stdc++.h>
using namespace std;
const int dr[] = {0, -1, 0, 1, -1, 1, 1, -1};
const int dc[] = {1, 0, -1, 0, 1, 1, -1, -1};
const double eps = 1e-9;
template <class T>
int len(const T& c) {
  return (int)c.size();
}
template <class T>
void srt(T& c) {
  std::sort(c.begin(), c.end());
}
template <class T>
void cmin(T& a, T b) {
  if (b < a) a = b;
}
template <class T>
void cmax(T& a, T b) {
  if (b > a) a = b;
}
long long toint(string s) {
  long long r = 0;
  istringstream sin(s);
  sin >> r;
  return r;
}
vector<string> split(string s, string first = " ") {
  vector<string> res;
  for (int i(0), _n(len(s)); i < _n; ++i) {
    string a;
    while (i < (int)s.size() && first.find(s[i]) == string::npos) a += s[i++];
    if (!a.empty()) res.push_back((a));
  }
  return res;
}
vector<int> isplit(string s, string first = " ") {
  vector<int> res;
  for (int i(0), _n(len(s)); i < _n; ++i) {
    string a;
    while (i < (int)s.size() && first.find(s[i]) == string::npos) a += s[i++];
    if (!a.empty()) res.push_back((atol(a.c_str())));
  }
  return res;
}
string tostr(long long a) {
  if (a == 0) return "0";
  string ret;
  for (long long i = a; i > 0; i = i / 10) ret.push_back((i % 10) + 48);
  reverse(ret.begin(), ret.end());
  return ret;
}
long long Pow(int b, int p) {
  long long ret = 1;
  for (int i(0), _n(p); i < _n; ++i) {
    ret *= b;
  }
  return ret;
}
vector<vector<string> > v;
int n;
string s1, s2, s, s4;
vector<string> t;
int main() {
  cin >> n;
  int ans = 0;
  for (int i(0), _n(n); i < _n; ++i) {
    t.clear();
    cin >> s1 >> s2;
    if (i != n - 1) cin >> s4;
    s = "$";
    s += s1[0];
    s += s1[1];
    s += s2[0];
    s += s2[1];
    s = s.substr(1);
    t.push_back(s);
    s = "$";
    s += s1[1];
    s += s2[1];
    s += s1[0];
    s += s2[0];
    s = s.substr(1);
    t.push_back(s);
    s = "$";
    s += s2[0];
    s += s1[0];
    s += s2[1];
    s += s1[1];
    s = s.substr(1);
    t.push_back(s);
    s = "$";
    s += s2[1];
    s += s2[0];
    s += s1[1];
    s += s1[0];
    s = s.substr(1);
    t.push_back(s);
    srt(t);
    for (int j(0), _n(len(v)); j < _n; ++j) {
      for (int k(0), _n(len(t)); k < _n; ++k)
        if (t[k] == v[j][k]) goto l;
    }
    v.push_back(t);
    ans++;
  l:;
  }
  cout << ans;
}
