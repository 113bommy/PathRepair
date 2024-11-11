#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
long long n;
long long get(long long x, long long y, long long x2, long long y2) {
  if (x2 < x || y2 < y) return 0;
  cout << "? " << x << ' ' << y << ' ' << x2 << ' ' << y2 << endl;
  long long ans;
  cin >> ans;
  return ans;
}
long long bin_p_up(long long k) {
  long long l = 0, r = n + 1;
  while (r - l > 1) {
    long long m = (r + l) / 2;
    if (get(1, 1, n, m) > k)
      r = m;
    else
      l = m;
  }
  return r;
}
long long bin_p_right(long long k) {
  long long l = 0, r = n + 1;
  while (r - l > 1) {
    long long m = (r + l) / 2;
    if (get(1, 1, m, n) > k)
      r = m;
    else
      l = m;
  }
  return r;
}
long long bin_p_left(long long k) {
  long long l = 0, r = n + 1;
  while (r - l > 1) {
    long long m = (r + l) / 2;
    if (get(m, 1, n, n) > k)
      l = m;
    else
      r = m;
  }
  return l;
}
long long bin_p_down(long long k) {
  long long l = 0, r = n + 1;
  while (r - l > 1) {
    long long m = (r + l) / 2;
    if (get(1, m, n, n) > k)
      l = m;
    else
      r = m;
  }
  return l;
}
pair<long long, long long> search_left() {
  return {bin_p_left(0), bin_p_left(1)};
}
pair<long long, long long> search_right() {
  return {bin_p_right(0), bin_p_right(1)};
}
pair<long long, long long> search_up() { return {bin_p_up(0), bin_p_up(1)}; }
pair<long long, long long> search_down() {
  return {bin_p_down(0), bin_p_down(1)};
}
void task() {
  auto [ax, bx] = search_left();
  auto [ax2, bx2] = search_right();
  auto [ay, by] = search_down();
  auto [ay2, by2] = search_up();
  vector<vector<long long>> rec = {{ax, ay, ax2, ay2}, {bx, by, bx2, by2}};
  vector<vector<long long>> mask = {
      {0, 0, 0, 0}, {0, 0, 0, 1}, {0, 0, 1, 0}, {0, 0, 1, 1},
      {0, 1, 0, 0}, {0, 1, 0, 1}, {0, 1, 1, 0}, {0, 1, 1, 1},
      {1, 0, 0, 0}, {1, 0, 0, 1}, {1, 0, 1, 0}, {1, 0, 1, 1},
      {1, 1, 0, 0}, {1, 1, 0, 1}, {1, 1, 1, 0}, {1, 1, 1, 1}};
  for (auto m : mask) {
    vector<long long> r1 = {rec[m[0]][0], rec[m[1]][1], rec[m[2]][2],
                            rec[m[3]][3]};
    vector<long long> r2 = {rec[!m[0]][0], rec[!m[1]][1], rec[!m[2]][2],
                            rec[!m[3]][3]};
    if (get(r1[0], r1[1], r1[2], r1[3]) && get(r2[0], r2[1], r2[2], r2[3])) {
      cout << "! " << endl;
      cout << r1[0] << ' ' << r1[1] << ' ' << r1[2] << ' ' << r1[3] << endl;
      cout << r2[0] << ' ' << r2[1] << ' ' << r2[2] << ' ' << r2[3] << endl;
      exit(0);
    }
  }
}
int main() {
  cin >> n;
  task();
}
