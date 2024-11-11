#include <bits/stdc++.h>
using namespace std;
string s;
int k;
int check(int len) {
  int last = 0;
  int ans = 1;
  int curlen = 0;
  for (int i = 0; i < s.size(); i++) {
    curlen++;
    if (i - last + 1 > len) return 0;
    if (curlen > len) {
      curlen = i - last;
      ans++;
    }
    if (s[i] == ' ' || s[i] == '-') {
      last = i;
    }
  }
  return ans <= k;
}
int main() {
  ios::sync_with_stdio(0);
  cin >> k;
  string c;
  while (cin >> c) {
    if (s.size() > 0) s += ' ';
    s += c;
  }
  int l = 0, r = 1 << 20;
  while (l + 1 < r) {
    int mid = (l + r) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  cout << r;
}
