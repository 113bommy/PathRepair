#include <bits/stdc++.h>
using namespace std;
int gcd(int x, int y) {
  if (!y) return x;
  return gcd(y, x % y);
}
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
bool sortbysecinrev(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second > b.second);
}
bool sortbysize(string &s1, string &s2) { return s1.size() < s2.size(); }
bool sortinrev(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.first > b.first);
}
bool sortcol(const vector<int> &v1, const vector<int> &v2) {
  return v1[0] < v2[0];
}
long long proceed() {
  long long l, r, m, i, mn = 1e15, a;
  cin >> l >> r >> m;
  for (i = l; i <= r; ++i) {
    if (i <= m) {
      long long x = m % i;
      if (x < mn) mn = x, a = i;
    }
    long long y = i - m % i;
    if (y < mn) mn = y, a = i;
  }
  (m + mn) % a == 0 ? cout << a << " " << l << " " << l + mn << "\n"
                    : cout << a << " " << l + mn << " " << l << "\n";
  return 0;
}
int main() {
  int t = 1, i = 0;
  cin >> t;
  while (t--) {
    proceed();
  }
  return 0;
}
