#include <bits/stdc++.h>
const long long LIM = (long long)2000000000 * 1000000000;
using namespace std;
struct Friend {
  int x, k, m;
} frd[101];
int n, m, b;
long long res, money[1050000];
void Upbit(int &x, int i) { x |= (1 << i); }
bool compare(struct Friend x, struct Friend y) { return x.k < y.k; }
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m >> b;
  int mm, x;
  for (int i = (0), _b = (n); i < _b; i++) {
    cin >> frd[i].x >> frd[i].k >> mm;
    for (int j = (0), _b = (mm); j < _b; j++) {
      cin >> x;
      Upbit(frd[i].m, x - 1);
    }
  }
  mm = (1 << m);
  res = LIM;
  sort(frd, frd + n, compare);
  fill(money + 1, money + mm, LIM);
  for (int i = (0), _b = (n); i < _b; i++) {
    for (int j = (0), _b = (mm - 1); j < _b; j++) {
      x = j | frd[i].m;
      money[x] = min(money[x], money[j] + frd[i].x);
    }
    res = min(res, money[mm - 1] + b * frd[i].k);
  }
  if (res == LIM)
    cout << -1;
  else
    cout << res;
  return 0;
}
