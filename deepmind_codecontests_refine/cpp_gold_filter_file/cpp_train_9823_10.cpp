#include <bits/stdc++.h>
const double PI = 3.1415926535897932384626433;
const int KL = 1e6;
const long long MOD = 1e9 + 7;
using namespace std;
long long l, r, p[100];
vector<int> vec;
long long mem[35][70][70][2];
int vis[35][70][70][2], timer;
long long dp(int i, int fs, int fg, bool ok, int k) {
  if (i == k) {
    if (ok || fg == 0 || (fg > 0 && fs != 0 && fs < fg)) return 1;
    return 0;
  }
  if (vis[i][fs][fg][ok] == timer) return mem[i][fs][fg][ok];
  vis[i][fs][fg][ok] = timer;
  if (i == 0) {
    int ffg = 0;
    for (int j = k; j < vec.size(); j += k)
      if (vec[j] < 1) {
        ffg = j;
        break;
      }
    return mem[i][fs][fg][ok] = dp(i + 1, fs, ffg, ok, k);
  }
  if (ok) {
    return mem[i][fs][fg][ok] = 2 * dp(i + 1, fs, fg, ok, k);
  }
  long long path = 0;
  int ffs = 0;
  for (int j = i + k; j < vec.size(); j += k)
    if (vec[j] > 0) {
      ffs = j;
      break;
    }
  if (fs > 0 && ffs > 0)
    ffs = min(ffs, fs);
  else if (fs > 0 && ffs == 0)
    ffs = fs;
  path += dp(i + 1, ffs, fg, (vec[i] == 1), k);
  if (vec[i] == 1) {
    int ffg = 0;
    for (int j = i + k; j < vec.size(); j += k)
      if (vec[j] < 1) {
        ffg = j;
        break;
      }
    if (fg > 0 && ffg > 0)
      ffg = min(ffg, fg);
    else if (fg > 0 && ffg == 0)
      ffg = fg;
    path += dp(i + 1, fs, ffg, ok, k);
  }
  return mem[i][fs][fg][ok] = path;
}
long long solve(long long n) {
  if (n < 3) return 0;
  vec.clear();
  while (n != 0) {
    vec.push_back(n % 2);
    n /= 2;
  }
  reverse(vec.begin(), vec.end());
  long long ret = 0;
  for (int i = 1; i <= vec.size(); i++) p[i] = 0;
  for (int i = 2; i < vec.size(); i++) {
    long long sz = i;
    vector<int> dv;
    for (int j = 1; j < sz; j++) {
      if (sz % j == 0) dv.push_back(j);
    }
    for (auto v : dv) {
      p[i] += ((1 << (v - 1)) - p[v]);
    }
    ret += p[i];
  }
  for (int i = 1; i <= vec.size(); i++) p[i] = 0;
  for (int i = 2; i <= vec.size(); i++) {
    long long sz = i;
    vector<int> dv;
    for (int j = 1; j < sz; j++) {
      if (sz % j == 0) dv.push_back(j);
    }
    for (auto v : dv) {
      timer++;
      long long an = dp(0, 0, 0, 0, v);
      p[i] += (an - p[v]);
    }
  }
  ret += p[vec.size()];
  return ret;
}
int main() {
  scanf("%I64d %I64d", &l, &r);
  printf("%I64d\n", solve(r) - solve(l - 1));
  return 0;
}
