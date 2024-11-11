#include <bits/stdc++.h>
using namespace std;
const int dr[] = {0, -1, 0, 1, -1, 1, 1, -1};
const int dc[] = {1, 0, -1, 0, 1, 1, -1, -1};
const double eps = 1e-9;
template <class T>
void print(T const &x) {
  ostringstream os;
  os << x;
  cout << os.str() << endl;
}
template <class T>
void print(vector<T> const &v) {
  ostringstream os;
  for (int i = 0; i < v.size(); ++i) {
    if (i) os << ' ';
    os << v[i];
  }
  cout << os.str() << endl;
}
template <class T>
void print(vector<vector<T> > const &v) {
  ostringstream os;
  for (int i = 0; i < v.size(); ++i) {
    for (int j = 0; j < v[i].size(); ++j) {
      if (j) os << ' ';
      os << v[i][j];
    }
    os << endl;
  }
  cout << os.str() << endl;
}
template <class T>
void print(valarray<T> const &v) {
  ostringstream os;
  for (int i = 0; i < v.size(); ++i) {
    if (i) os << ' ';
    os << v[i];
  }
  cout << os.str() << endl;
}
template <class T>
int sz(const T &c) {
  return (int)c.size();
}
template <class T>
void srt(T &c) {
  std::sort(c.begin(), c.end());
}
template <class T>
void checkmin(T &a, T b) {
  if (b < a) a = b;
}
template <class T>
void checkmax(T &a, T b) {
  if (b > a) a = b;
}
template <class T>
T sqr(T x) {
  return x * x;
}
template <class T, class U>
T cast(U x) {
  ostringstream os;
  os << x;
  T res;
  istringstream is(os.str());
  is >> res;
  return res;
}
template <class T>
vector<T> split(string s, string x = " ") {
  vector<T> res;
  for (int i = 0; i < s.size(); i++) {
    string a;
    while (i < (int)s.size() && x.find(s[i]) == string::npos) a += s[i++];
    if (!a.empty()) res.push_back(cast<T>(a));
  }
  return res;
}
template <class T>
bool inside(T r, T c, T R, T C) {
  return r >= 0 && r < R && c >= 0 && c < C;
}
vector<int> prefixFunction(string s) {
  int n = s.length();
  vector<int> p(n);
  for (int i = 1; i < n; i++) {
    int k = p[i - 1];
    while (k > 0 && s[k] != s[i]) {
      k = p[k - 1];
    }
    p[i] = k + (s[k] == s[i] ? 1 : 0);
  }
  return p;
}
int kmpMatcher(string a, string s) {
  int m = a.length();
  if (m == 0) {
    return 0;
  }
  int n = s.length();
  vector<int> p = prefixFunction(a);
  int k = 0;
  for (int i = 0; i < n; i++) {
    while (k > 0 && s[i] != a[k]) {
      k = p[k - 1];
    }
    if (s[i] == a[k]) {
      k++;
    }
    if (k == m) {
      return i - m + 1;
    }
  }
  return -1;
}
int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  string s, s1, s2;
  cin >> s >> s1 >> s2;
  int p2 = -1;
  int p1 = kmpMatcher(s1, s);
  if (p1 != -1) {
    p2 = kmpMatcher(s2, s.substr(p1 + sz(s1)));
  }
  reverse(s.begin(), s.end());
  int p4 = -1;
  int p3 = kmpMatcher(s1, s);
  if (p3 != -1) {
    p4 = kmpMatcher(s2, s.substr(p3 + sz(s1)));
  }
  if (p2 != -1 && p4 != -1) {
    cout << "both" << endl;
  } else if (p2 != -1) {
    cout << "forward" << endl;
  } else if (p3 != -1) {
    cout << "backward" << endl;
  } else {
    cout << "fantasy" << endl;
  }
  return 0;
}
