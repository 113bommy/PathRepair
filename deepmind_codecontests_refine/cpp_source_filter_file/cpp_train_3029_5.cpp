#include <bits/stdc++.h>
using namespace std;
template <class T>
bool uin(T& a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool uax(T& a, T b) {
  return a < b ? (a = b, true) : false;
}
const int inf = 2e9;
string a, b;
vector<int> l1, l2;
int get_cnt(const string& s) {
  for (int i = 0; i < (int)((int)(s).size()); ++i)
    if (s[i] != s[0]) return i;
  return (int)(s).size();
}
void op(int c1, int c2) {
  l1.push_back(c1);
  l2.push_back(c2);
  string ra = a.substr(0, c1), rb = b.substr(0, c2);
  a = rb + a.substr(c1);
  b = ra + b.substr(c2);
}
deque<int> getv(const string& s) {
  deque<int> ret;
  for (int i = 0; i < (int)(s).size();) {
    int pos = i;
    while (pos < (int)(s).size() && s[pos] == s[i]) pos++;
    ret.push_back(pos - i);
    i = pos;
  }
  return ret;
}
int solve() {
  int s1 = 0, s2 = 0;
  deque<int> v1 = getv(a), v2 = getv(b);
  bool flg = 1;
  int it = 0;
  while (1) {
    int c1 = v1.front(), c2 = v2.front();
    if ((int)(v1).size() == 1 && (int)(v2).size() == 1) break;
    if (flg && (int)(a).size() && (int)(b).size() && a[0] == b[0]) {
      l1.push_back(c1);
      l2.push_back(0);
      v1.pop_front();
      s2 += c1;
    } else {
      l1.push_back(s1 + c1);
      l2.push_back(s2 + c2);
      v1.pop_front();
      v2.pop_front();
      if (v1.empty()) v1.push_back(0);
      if (v2.empty()) v2.push_back(0);
      swap(s1, s2);
      s1 += c2;
      s2 += c1;
    }
    flg = 0;
  }
  return (int)(l1).size();
}
int get_l(const string& s, int num) {
  if (num == 0) return 0;
  int ret = 0;
  for (int i = 0; i < (int)(s).size();) {
    int pos = i;
    while (s[pos] == s[i]) pos++;
    i = pos;
    ret++;
    if (ret == num) return pos;
  }
}
void first_op(int c1, int c2) { op(get_l(a, c1), get_l(b, c2)); }
int sol(const string& s) {
  int ret = 0;
  for (int i = 0; i < (int)(s).size();) {
    int pos = i;
    while (pos < (int)(s).size() && s[pos] == s[i]) pos++;
    i = pos;
    ret++;
  }
  return ret;
}
int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> a >> b;
  bool inv = 0;
  int c1 = sol(a), c2 = sol(b);
  if (c1 < c2) {
    swap(a, b);
    swap(c1, c2);
    inv = 1;
  }
  if (a[0] == b[0]) {
    int len = 0;
    while (1) {
      if (len == 0) {
        len = 1;
        c1--;
      } else {
        len += 2;
        c1 -= 2;
        c2 += 2;
      }
      if (c1 <= c2 + 1) break;
    }
    int len2 = 0;
    if (c1 + 2 == c2) {
      len--;
      len2++;
    }
    first_op(len, len2);
  } else if (c1 < c2 + 2) {
    int sum = (c1 + c2 - 2) / 2;
    if (c1 % 2 != c2 % 2) {
      if ((c1 - c2) % 4 == 1)
        first_op(c1 - sum - 1, 1);
      else
        first_op(c1 - sum, 1);
    } else
      first_op(c1 - sum, 1);
  }
  solve();
  cout << (int)(l1).size() << '\n';
  for (int i = 0; i < (int)((int)(l1).size()); ++i) {
    if (inv) swap(l1[i], l2[i]);
    cout << l1[i] << ' ' << l2[i] << '\n';
  }
}
