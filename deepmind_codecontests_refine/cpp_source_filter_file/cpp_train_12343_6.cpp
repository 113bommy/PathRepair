#include <bits/stdc++.h>
using namespace std;
const int mx1 = 15;
const int mx2 = 105;
const int mx3 = 5005;
const int mx4 = 30005;
const int mx5 = 300005;
const int mx6 = 600005;
int _toggle(int N, int pos) { return N = N ^ (1 << pos); }
int _set(int N, int pos) { return N = N | (1 << pos); }
int _reset(int N, int pos) { return N = N & ~(1 << pos); }
bool _check(int N, int pos) { return (bool)(N & (1 << pos)); }
bool _upper(char a) { return a >= 'A' && a <= 'Z'; }
bool _lower(char a) { return a >= 'a' && a <= 'z'; }
bool _digit(char a) { return a >= '0' && a <= '9'; }
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};
long long a, b, c, d;
void check(long long x) {
  long long xx = 0;
  for (long long i = 1; i <= 100000; i++) {
    if (i * (i - 1) / 2 == x) {
      xx = i;
    }
  }
  if (xx == 0) {
    cout << "Impossible\n";
    return;
  }
  char ch;
  if (x == d) {
    ch = '1';
  } else {
    ch = '0';
  }
  for (int i = 0; i < xx; i++) {
    cout << ch;
  }
  return;
}
void solve() {
  cin >> a >> b >> c >> d;
  if (!a && !b && !c && !c) {
    cout << 0 << '\n';
    return;
  }
  if (!a && !b && !c && d) {
    check(d);
    return;
  }
  if (a && !b && !c && !d) {
    check(a);
    return;
  }
  if (!b && !c) {
    cout << "Impossible\n";
    return;
  }
  long long x = 0, y = 0;
  for (long long i = 1; i <= 100000; i++) {
    long long n = i * (i - 1) / 2;
    if (n == a) {
      x = i;
      break;
    }
  }
  for (long long i = 1; i <= 100000; i++) {
    long long n = i * (i - 1) / 2;
    if (n == d) {
      y = i;
      break;
    }
  }
  if (x == 0 || y == 0) {
    cout << "Impossible\n";
    return;
  }
  if (b + c != x * y) {
    cout << "Impossible\n";
    return;
  }
  long long rt;
  for (long long i = 1; i <= y; i++) {
    if (b <= x * i) {
      rt = i;
      break;
    }
  }
  string s;
  for (int i = 1; i <= y - rt; i++) {
    s.push_back('1');
  }
  for (int i = 1; i <= x; i++) {
    s.push_back('0');
  }
  int id;
  for (int i = 1; i <= rt; i++) {
    if (i == 1) {
      id = s.size();
    }
    s.push_back('1');
  }
  rt *= x;
  for (int i = id; i > 0; i--) {
    if (rt > b) {
      swap(s[i], s[i - 1]);
      rt--;
    }
  }
  cout << s << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc = 1;
  while (tc--) {
    solve();
  }
}
