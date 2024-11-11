#include <bits/stdc++.h>
using namespace std;
int n, k;
struct pib {
  pib(int a, int b, int c) { h = a, lr = b, st = c; }
  int h, lr, st;
};
queue<pib> q;
string d[2];
bool inque[222222];
int cal(pib t) { return n * t.lr + t.h; }
int main() {
  cin >> n >> k >> d[0] >> d[1];
  q.push(pib(0, 0, 0));
  inque[0] = true;
  while (!q.empty()) {
    pib t = q.front();
    q.pop();
    if (t.h + k >= n) return puts("YES");
    if (d[t.lr][t.h + 1] != 'X' && !inque[cal(t) + 1]) {
      inque[cal(t) + 1] = true;
      q.push(pib(t.h + 1, t.lr, t.st + 1));
    }
    if (t.h && d[t.lr][t.h - 1] != 'X' && !inque[cal(t) - 1] &&
        t.st + 1 <= t.h - 1) {
      inque[cal(t) - 1] = true;
      q.push(pib(t.h - 1, t.lr, t.st + 1));
    }
    if (d[!t.lr][t.h + k] != 'X' && !inque[cal(pib(t.h, !t.lr, t.st)) + k]) {
      inque[cal(pib(t.h, !t.lr, t.st)) + k] = true;
      q.push(pib(t.h + k, !t.lr, t.st + 1));
    }
  }
  puts("NO");
}
