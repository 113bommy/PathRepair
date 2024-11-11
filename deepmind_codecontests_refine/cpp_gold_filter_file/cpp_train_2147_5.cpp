#include <bits/stdc++.h>
using namespace std;
int n;
long long wid[4][100005];
long long intime[4][100005];
int front[4], rear[4], size[4];
int t[100005];
int t1, t2, t3;
int k1, k2, k3;
long long tmax;
void init() {
  cin >> k1 >> k2 >> k3 >> t1 >> t2 >> t3;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> t[i];
  return;
}
inline long long min(long long a, long long b) { return a < b ? a : b; }
void work() {
  int p, done;
  long long curt;
  curt = 1;
  p = 1;
  done = 0;
  rear[1] = rear[2] = rear[3] = -1;
  while (done < n) {
    while (size[3] > 0 and intime[3][front[3]] + t3 <= curt) {
      tmax =
          (curt - wid[3][front[3]]) > tmax ? (curt - wid[3][front[3]]) : tmax;
      ++front[3];
      --size[3];
      ++done;
    }
    while (size[2] > 0 and intime[2][front[2]] + t2 <= curt and size[3] < k3) {
      ++rear[3];
      ++size[3];
      wid[3][rear[3]] = wid[2][front[2]];
      intime[3][rear[3]] = curt;
      ++front[2];
      --size[2];
    }
    while (size[1] > 0 and intime[1][front[1]] + t1 <= curt and size[2] < k2) {
      ++rear[2];
      ++size[2];
      wid[2][rear[2]] = wid[1][front[1]];
      intime[2][rear[2]] = curt;
      --size[1];
      ++front[1];
    }
    while (t[p] <= curt and size[1] < k1 and p <= n) {
      ++rear[1];
      ++size[1];
      wid[1][rear[1]] = t[p++];
      intime[1][rear[1]] = curt;
    }
    curt = -1;
    if (size[3] > 0 and (curt > intime[3][front[3]] + t3 or curt == -1))
      curt = intime[3][front[3]] + t3;
    if (size[2] > 0 and size[3] < k3 and
        (curt > intime[2][front[2]] + t2 or curt == -1))
      curt = intime[2][front[2]] + t2;
    if (size[1] > 0 and size[2] < k2 and
        (curt > intime[1][front[1]] + t1 or curt == -1))
      curt = intime[1][front[1]] + t1;
    if (p <= n and size[1] < k1 and (curt > t[p] or curt == -1)) curt = t[p];
  }
  cout << tmax << "\n";
  return;
}
int main() {
  init();
  work();
  return 0;
}
