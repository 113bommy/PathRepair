#include <bits/stdc++.h>
using namespace std;
int n;
struct A {
  int x, y, z;
  A(int _x, int _y, int _z) { x = _x, y = _y, z = _z; }
  bool check(int p) { return (p == x) || (p == y) || (p == z); }
};
int a[105];
set<pair<int, int> > s;
vector<A> v1, v2;
bool f1, f2;
int ans1, ans2;
bool dec2(vector<A> &v) {
  pair<int, int> p1, p2;
  p1 = *s.begin();
  s.erase(s.begin());
  p2 = *s.begin();
  s.erase(s.begin());
  p1.first++;
  if (p1.first > 0) p1.first = 0;
  p2.first++;
  if (p2.first > 0) p2.first = 0;
  s.insert(p1);
  s.insert(p2);
  v.push_back(A(p1.second, p2.second, 0));
  return true;
}
bool dec3(vector<A> &v) {
  pair<int, int> p1, p2, p3;
  p1 = *s.begin();
  s.erase(s.begin());
  p2 = *s.begin();
  s.erase(s.begin());
  p3 = *s.begin();
  s.erase(s.begin());
  p1.first++;
  if (p1.first > 0) p1.first = 0;
  p2.first++;
  if (p2.first > 0) p2.first = 0;
  p3.first++;
  if (p3.first > 0) p3.first = 0;
  s.insert(p1);
  s.insert(p2);
  s.insert(p3);
  v.push_back(A(p1.second, p2.second, p3.second));
  return true;
}
bool check() {
  int x = s.begin()->first;
  for (set<pair<int, int> >::iterator si = s.begin(); si != s.end(); si++)
    if (si->first != x) return false;
  return true;
}
void print(vector<A> &v, int ans) {
  cout << ans << "\n";
  cout << v.size() << "\n";
  for (int i = 0; i < v.size(); i++) {
    for (int j = 1; j <= n; j++)
      if (v[i].check(j))
        cout << "1";
      else
        cout << "0";
    cout << "\n";
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int x = a[1];
  bool same = true;
  for (int i = 2; i <= n; i++) same &= (a[i] == x);
  if (same) {
    cout << x << "\n";
    cout << 0 << "\n";
    return 0;
  }
  {
    s.clear();
    for (int i = 1; i <= n; i++) s.insert(make_pair(-a[i], i));
    while (s.begin()->first != 0) {
      dec2(v1);
      if (check()) break;
    }
    ans1 = -s.begin()->first;
  }
  f2 = false;
  if (s.size() >= 3) {
    f2 = true;
    s.clear();
    for (int i = 1; i <= n; i++) s.insert(make_pair(-a[i], i));
    dec3(v2);
    if (check() == false) {
      while (s.begin()->first != 0) {
        dec2(v2);
        if (check()) break;
      }
    }
    ans2 = -s.begin()->first;
  }
  if (f2) {
    if (ans1 > ans2)
      print(v1, ans1);
    else
      print(v2, ans2);
  } else {
    print(v1, ans1);
  }
  return 0;
}
