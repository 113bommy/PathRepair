#include <bits/stdc++.h>
using namespace std;
string ans = "";
int f(int z, int x, int y) {
  return y / 2 * (1 - abs(z - x) + abs(abs(z - x) - 1));
}
int n;
int a[100][100];
string get(int k) {
  ans = "";
  for (int i = 1; i < n; i++) ans += '(';
  for (int i = 0; i < n; i++) {
    int x, y;
    if (k == 0)
      y = a[i][1], x = a[i][0];
    else
      y = a[i][0], x = a[i][1];
    string tans = "";
    int t = y / 2;
    bool z = t == 0;
    while (t != 0 || z) {
      z = 0;
      tans = char('0' + t % 10) + tans;
      t /= 10;
    }
    tans = '(' + tans + '*' + '(';
    string t1 = "(1-abs((t-", t2 = ")))+abs((abs((t-", t3 = "))-1))))";
    if (i != 0) t3 += ')';
    t3 += '+';
    ans += tans;
    ans += t1;
    t = i;
    tans = "";
    z = t == 0;
    while (t != 0 || z) {
      z = 0;
      tans = char('0' + t % 10) + tans;
      t /= 10;
    }
    ans += tans;
    ans += t2;
    ans += tans;
    ans += t3;
  }
  ans.resize(ans.size() - 1);
  return ans;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y, r;
    cin >> x >> y >> r;
    a[i][0] = x, a[i][1] = y;
  }
  cout << get(1) << endl;
  cout << get(0);
  return 0;
}
