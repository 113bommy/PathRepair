#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
const int base = 1e9 + 7;
int kq[maxn][maxn] = {0};
int h, w;
int r[maxn], c[maxn];
long long s;
map<pair<int, int>, bool> mp;
long long tinh(int x, int n) {
  if (n == 0) return 1;
  if (n == 1) return x;
  long long t = tinh(x, n / 2) % base;
  t = t * t % base;
  if (n % 2 == 1) t = t * x % base;
  return t;
}
int main() {
  cin >> h >> w;
  bool kt = true;
  for (int i = 1; i <= h; i++) cin >> r[i];
  for (int i = 1; i <= w; i++) cin >> c[i];
  for (int i = 1; i <= h; i++) {
    for (int k = 1; k <= r[i]; k++) {
      kq[i][k] = 1;
      if (i == 1 && c[k] == 0) kt = false;
      if (r[i] == c[k] + 1) kt = false;
    }
  }
  for (int i = 1; i <= w; i++) {
    for (int k = 1; k <= c[i]; k++) {
      kq[k][i] = 1;
      if (i == 1 && r[k] == 0) kt = false;
      if (c[i] == r[k] + 1) kt = false;
    }
  }
  if (kt == false) {
    cout << 0 << endl;
    return 0;
  }
  s = 0;
  pair<int, int> new_ii;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      if (kq[i][j] == 0 && i == c[j] + 1) {
        new_ii = pair<int, int>(i, j);
        if (mp.find(new_ii) == mp.end()) mp[pair<int, int>(i, j)] = true;
      }
      s += (kq[i][j] == 0);
    }
  }
  for (int j = 1; j <= w; j++)
    for (int i = 1; i <= h; i++) {
      if (kq[i][j] == 0 && j == r[i] + 1) {
        new_ii = pair<int, int>(i, j);
        if (mp.find(new_ii) == mp.end()) mp[pair<int, int>(i, j)] = true;
      }
    }
  cout << (tinh(2, s) - (tinh(2, mp.size()) - 1) * tinh(2, s - mp.size()) +
           1LL * base * base) %
              base
       << endl;
  return 0;
}
