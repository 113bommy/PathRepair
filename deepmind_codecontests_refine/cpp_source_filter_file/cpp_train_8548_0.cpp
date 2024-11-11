#include <bits/stdc++.h>
using namespace std;
const int MAXn = 5e5 + 10, INF = 1e9 + 7;
long long bgs, lwt, n, k, ans, hp;
string s, t;
bool flag;
int main() {
  cin >> n >> k >> s >> t;
  if (s == t) {
    return cout << n, 0;
  }
  for (int i = 0; i < n; i++) {
    if (s[i] == 'a' && t[i] == 'a') {
      hp = (2 * hp);
      if (hp > INF) hp = INF;
      if (flag && i != 0) {
        hp += 2;
      }
    }
    if (s[i] == 'a' && t[i] == 'b') {
      hp = (2 * hp);
      if (hp > INF) hp = INF;
      if (flag && i != 0) {
        hp += 2;
      }
    }
    if (s[i] == 'b' && t[i] == 'a') {
      hp = (2 * hp);
      if (hp > INF) hp = INF;
    }
    if (s[i] == 'b' && t[i] == 'b') {
      hp = (2 * hp);
      if (hp > INF) hp = INF;
      if (flag && i != 0) {
        hp += 2;
      }
    }
    if (s[i] != t[i]) flag = true;
    if (flag)
      ans += min(k, hp + 2);
    else
      ans += min(k, hp + 1);
  }
  cout << max(ans, n);
}
