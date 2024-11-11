#include <bits/stdc++.h>
using namespace std;
int n;
string s;
pair<int, int> getRes(const string &s, int &pnt) {
  char c = s[pnt++];
  if (c == '0') return pair<int, int>(0, 1);
  if (c == '1') return pair<int, int>(1, 1);
  if (c == '?') return pair<int, int>(2, 2);
  pair<int, int> p1 = getRes(s, pnt);
  c = s[pnt++];
  pair<int, int> p2 = getRes(s, pnt);
  pnt++;
  pair<int, int> res;
  if (c == '^') {
    if (p1 > p2) swap(p1, p2);
    if (p2.first < 2) return pair<int, int>(p1.first ^ p2.first, 1);
    if (p1.first < 2) return pair<int, int>(2, p2.second);
    if (p1.second == 3 || p2.second == 3) return pair<int, int>(2, 3);
    if (p1.second != p2.second) return pair<int, int>(2, 2);
    return pair<int, int>(2, 1);
  }
  if (c == '&') {
    if (p1 > p2) swap(p1, p2);
    if (p2.first < 2) return pair<int, int>(p1.first & p2.first, 1);
    if (p1.first == 0) return pair<int, int>(0, 1);
    if (p1.first == 1) return pair<int, int>(2, p2.second);
    return pair<int, int>(2, p1.second | p2.second | 1);
  }
  if (c == '|') {
    if (p1 > p2) swap(p1, p2);
    if (p2.first < 2) return pair<int, int>(p1.first | p2.first, 1);
    if (p1.first == 0) return pair<int, int>(2, p2.second);
    if (p1.first == 1) return pair<int, int>(1, 1);
    return pair<int, int>(2, p1.second | p2.second | 1);
  }
}
int main() {
  cin >> n >> s;
  int pnt = 0;
  pair<int, int> res = getRes(s, pnt);
  printf("%s\n", res.second & 2 ? "YES" : "NO");
  return 0;
}
