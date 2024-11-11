#include <bits/stdc++.h>
using namespace std;
struct Bint {
  string n;
  Bint(string s) { n = s; }
  Bint operator+(const Bint &a) {
    Bint x = n, y = a;
    if (x.n.size() < y.n.size()) swap(x, y);
    while (y.n.size() < x.n.size()) y.n = "0" + y.n;
    string res = "";
    bool flag = false;
    for (int i = x.n.size() - 1; i >= 0; i--) {
      int num = (x.n[i] - '0') + (y.n[i] - '0') + flag;
      flag = false;
      if (num < 10) {
        res = (char)('0' + num) + res;
      } else {
        flag = true;
        res = (char)('0' + (num - 10)) + res;
      }
    }
    if (flag) res = '1' + res;
    return res;
  }
  Bint operator*(const Bint &a) {
    Bint x = n, y = a, res("0");
    string zeroes = "";
    for (int i = y.n.size() - 1; i >= 0; i--) {
      Bint mul("0");
      for (int _ = 0; _ < y.n[i] - '0'; _++) mul += x;
      res += Bint(mul.n + zeroes);
      zeroes += "0";
    }
    return res;
  }
  Bint pow(Bint a, int b) {
    if (b == 0) return Bint("1");
    if (b % 2) return pow(a, b - 1) * a;
    Bint memo = pow(a, b / 2);
    return memo * memo;
  }
  Bint operator^(const int &a) { return pow(n, a); }
  void operator+=(const Bint &b) { *this = *this + b; }
  void operator*=(const Bint &b) { *this = *this * b; }
};
int sell[2010];
bool used[5010];
set<int> win[2010];
string beki[2010];
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, having = -1;
  pair<string, int> p[5010];
  fill(sell, sell + 2010, -1);
  beki[0] = "1";
  for (int i = 0; i < 2001; i++) {
    beki[i + 1] = (Bint(beki[i]) * Bint("2")).n;
  }
  cin >> n;
  Bint ans("0");
  for (int i = 0; i < n; i++) {
    cin >> p[i].first >> p[i].second;
    if (p[i].first == "sell")
      sell[p[i].second] = i;
    else
      win[p[i].second].insert(i);
  }
  for (int i = 2000; i >= 0; i--) {
    if (win[i].empty() || *win[i].begin() > sell[i]) continue;
    int l = *prev(win[i].upper_bound(sell[i])), r = sell[i];
    bool flag = true;
    for (int j = l; j <= r; j++) {
      if (used[j]) {
        flag = false;
        break;
      }
    }
    if (flag) {
      fill(used + l, used + r + 1, true);
      ans += Bint(beki[i]);
    }
  }
  cout << ans.n << endl;
  return 0;
}
