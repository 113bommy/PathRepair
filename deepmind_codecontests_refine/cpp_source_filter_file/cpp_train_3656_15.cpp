#include <bits/stdc++.h>
using namespace std;
int v[510][5010];
struct lenka {
  int len, mod, sum;
  char s[550];
  lenka() {
    len = -1;
    mod = sum = 0;
    memset(s, 0, sizeof s);
  }
};
int main() {
  int d, s;
  cin >> d >> s;
  queue<lenka> p;
  lenka now;
  p.push(now);
  while (!p.empty()) {
    now = p.front();
    p.pop();
    for (int i = 0; i <= 9; i++) {
      lenka nex = now;
      nex.len++;
      nex.s[nex.len] = i + '0';
      nex.mod = (nex.mod * 10 + i) % d;
      nex.sum += i;
      if (v[nex.mod][nex.sum] || nex.sum > s) continue;
      v[nex.mod][nex.sum] = 1;
      if (nex.mod == 0 && nex.sum == s) {
        puts(nex.s);
        return 0;
      }
      p.push(nex);
    }
  }
  puts("-1");
  return 0;
}
