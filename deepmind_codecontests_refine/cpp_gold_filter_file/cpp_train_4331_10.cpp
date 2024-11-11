#include <bits/stdc++.h>
using namespace std;
int n;
char now;
string s, t;
void solve(int len) {
  if (len == 1) {
    s = "";
    t = "a";
    now = 'a';
    return;
  }
  if (len == 2) {
    s = "c";
    t = "ac";
    now = 'c';
    return;
  }
  if (len % 2 == 0) {
    solve(len / 2 - 1);
    now++;
    s = now + s + now + now;
    t = t + now;
    return;
  }
  if (len % 2 == 1) {
    solve(len / 2);
    now++;
    s = s + now + now;
    t = t + now;
    return;
  }
}
int main() {
  scanf("%d", &n);
  solve(n);
  cout << t << s << " " << t;
  return 0;
}
