#include <bits/stdc++.h>
using namespace std;
long long n;
char now;
string s, t;
inline long long read() {
  long long x = 0;
  bool f = 0;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar()) f ^= (ch == '-');
  for (; isdigit(ch); ch = getchar()) x = (x << 3) + (x << 1) + (ch ^ 48);
  return f ? -x : x;
}
inline void solve(int len) {
  if (len == 1) {
    s = "";
    t = "a";
    now = 'a';
    return;
  }
  if (len == 2) {
    s = "b";
    t = "ab";
    now = 'b';
    return;
  }
  if (len & 1) {
    solve(len / 2);
    now++;
    s = s + now + now;
    t = t + now;
    return;
  } else {
    solve(len / 2 - 1);
    now++;
    s = now + s + now + now;
    t = t + now;
    return;
  }
}
int main() {
  n = read();
  solve(n);
  cout << t << s << " " << t;
  return 0;
}
