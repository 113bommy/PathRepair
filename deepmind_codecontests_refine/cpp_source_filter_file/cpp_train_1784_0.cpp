#include <bits/stdc++.h>
using namespace std;
template <typename T>
using V = vector<T>;
template <typename T, typename U>
using P = pair<T, U>;
template <typename I>
void join(ostream &ost, I s, I t, string d = " ") {
  for (auto i = s; i != t; ++i) {
    if (i != s) ost << d;
    ost << *i;
  }
  ost << endl;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (auto &a : v) is >> a;
  return is;
}
template <typename T, typename U>
istream &operator>>(istream &is, pair<T, U> &p) {
  is >> p.first >> p.second;
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, vector<T> &v) {
  os << "{";
  for (auto i = (v).begin(); i != (v).end(); ++i) {
    if (i != v.begin()) os << ",";
    os << *i;
  }
  os << "}";
  return os;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, pair<T, U> &p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}
int n, m;
int func1(const vector<string> &table, string pattern) {
  int res = 0;
  for (int i = (0); i < (n); ++i) {
    if (i % 2 == 0) {
      int d1 = 0;
      for (int j = (0); j < (m); ++j)
        if (table[i][j] != pattern[j % 2]) ++d1;
      int d2 = 0;
      for (int j = (0); j < (m); ++j)
        if (table[i][j] != pattern[(j + 1) % 2]) ++d2;
      res += min(d1, d2);
    } else {
      int d1 = 0;
      for (int j = (0); j < (m); ++j)
        if (table[i][j] != pattern[2 + j % 2]) ++d1;
      int d2 = 0;
      for (int j = (0); j < (m); ++j)
        if (table[i][j] != pattern[2 + (j + 1) % 2]) ++d2;
      res += min(d1, d2);
    }
  }
  return res;
}
int func2(const vector<string> &table, string pattern) {
  int res = 0;
  for (int i = (0); i < (m); ++i) {
    if (i % 2 == 0) {
      int d1 = 0;
      for (int j = (0); j < (n); ++j)
        if (table[j][i] != pattern[j % 2]) ++d1;
      int d2 = 0;
      for (int j = (0); j < (n); ++j)
        if (table[j][i] != pattern[(j + 1) % 2]) ++d2;
      res += min(d1, d2);
    } else {
      int d1 = 0;
      for (int j = (0); j < (n); ++j)
        if (table[j][i] != pattern[2 + j % 2]) ++d1;
      int d2 = 0;
      for (int j = (0); j < (n); ++j)
        if (table[j][i] != pattern[2 + (j + 1) % 2]) ++d2;
      res += min(d1, d2);
    }
  }
  return res;
}
vector<string> restore1(const vector<string> &table, string pattern) {
  vector<string> res(n);
  for (int i = (0); i < (n); ++i) {
    if (i % 2 == 0) {
      int d1 = 0;
      for (int j = (0); j < (m); ++j)
        if (table[i][j] != pattern[j % 2]) ++d1;
      int d2 = 0;
      for (int j = (0); j < (m); ++j)
        if (table[i][j] != pattern[(j + 1) % 2]) ++d2;
      if (d1 < d2) {
        for (int j = (0); j < (m); ++j) res[i].push_back(pattern[j % 2]);
      } else {
        for (int j = (0); j < (m); ++j) res[i].push_back(pattern[(j + 1) % 2]);
      }
    } else {
      int d1 = 0;
      for (int j = (0); j < (m); ++j)
        if (table[i][j] != pattern[2 + j % 2]) ++d1;
      int d2 = 0;
      for (int j = (0); j < (m); ++j)
        if (table[i][j] != pattern[2 + (j + 1) % 2]) ++d2;
      if (d1 < d2) {
        for (int j = (0); j < (m); ++j) res[i].push_back(pattern[2 + j % 2]);
      } else {
        for (int j = (0); j < (m); ++j)
          res[i].push_back(pattern[2 + (j + 1) % 2]);
      }
    }
  }
  return res;
}
vector<string> restore2(const vector<string> &table, string pattern) {
  vector<string> res(n);
  for (int i = (0); i < (m); ++i) {
    if (i % 2 == 0) {
      int d1 = 0;
      for (int j = (0); j < (n); ++j)
        if (table[j][i] != pattern[j % 2]) ++d1;
      int d2 = 0;
      for (int j = (0); j < (n); ++j)
        if (table[j][i] != pattern[(j + 1) % 2]) ++d2;
      if (d1 < d2) {
        for (int j = (0); j < (n); ++j) res[j].push_back(pattern[j % 2]);
      } else {
        for (int j = (0); j < (n); ++j) res[j].push_back(pattern[(j + 1) % 2]);
      }
    } else {
      int d1 = 0;
      for (int j = (0); j < (n); ++j)
        if (table[j][i] != pattern[2 + j % 2]) ++d1;
      int d2 = 0;
      for (int j = (0); j < (n); ++j)
        if (table[j][i] != pattern[2 + (j + 1) % 2]) ++d2;
      if (d1 < d2) {
        for (int j = (0); j < (n); ++j) res[j].push_back(pattern[2 + j % 2]);
      } else {
        for (int j = (0); j < (n); ++j)
          res[j].push_back(pattern[2 + (j + 1) % 2]);
      }
    }
  }
  return res;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n >> m;
  vector<string> table(n);
  cin >> table;
  string p = "ACGT";
  int hor_min = 1e9;
  string hor_pat;
  do {
    int t = func1(table, p);
    if (t < hor_min) {
      hor_min = t;
      hor_pat = p;
    }
  } while (next_permutation((p).begin(), (p).end()));
  int ver_min = 1e9;
  string ver_pat;
  do {
    int t = func2(table, p);
    if (t < ver_min) {
      ver_min = t;
      ver_pat = p;
    }
  } while (next_permutation((p).begin(), (p).end()));
  if (hor_min <= ver_min) {
    auto ans = restore1(table, hor_pat);
    for (auto &line : ans) cout << line << endl;
  } else {
    auto ans = restore2(table, hor_pat);
    for (auto &line : ans) cout << line << endl;
  }
  return 0;
}
