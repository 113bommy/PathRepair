#include <bits/stdc++.h>
using namespace std;
int n, lo[7][7], hi[7][7], a[7][7];
map<vector<int>, long long> mem[7];
long long dp(int ind, vector<int> &flow) {
  if (ind == n - 2) {
    if (lo[ind][ind + 1] <= flow[ind] && flow[ind] <= hi[ind][ind + 1])
      return ((flow[ind] > 0) ? a[ind][ind + 1] : 0) + flow[ind] * flow[ind];
    return -1;
  }
  if (mem[ind].count(flow)) return mem[ind][flow];
  if (ind == n - 3) {
    long long ret = -1;
    for (int f1 = lo[ind][ind + 1]; f1 <= hi[ind][ind + 1]; f1++) {
      if (f1 > flow[ind]) break;
      int f2 = flow[ind] - f1;
      if (lo[ind][ind + 2] <= f2 && f2 <= hi[ind][ind + 2]) {
        flow[ind + 1] += f1;
        flow[ind + 2] += f2;
        long long tmp = dp(ind + 1, flow);
        if (tmp != -1) {
          tmp += f1 * f1 + f2 * f2;
          if (f1 > 0) tmp += a[ind][ind + 1];
          if (f2 > 0) tmp += a[ind][ind + 2];
          ret = max(ret, tmp);
        }
        flow[ind + 1] -= f1;
        flow[ind + 2] -= f2;
      }
    }
    return mem[ind][flow] = ret;
  }
  if (ind == n - 4) {
    long long ret = -1;
    for (int f1 = lo[ind][ind + 1]; f1 <= hi[ind][ind + 1]; f1++) {
      if (f1 > flow[ind]) break;
      for (int f2 = lo[ind][ind + 2]; f2 <= hi[ind][ind + 2]; f2++) {
        if (f1 + f2 > flow[ind]) break;
        int f3 = flow[ind] - f1 - f2;
        if (lo[ind][ind + 3] <= f3 && f3 <= hi[ind][ind + 3]) {
          flow[ind + 1] += f1;
          flow[ind + 2] += f2;
          flow[ind + 3] += f3;
          long long tmp = dp(ind + 1, flow);
          if (tmp != -1) {
            tmp += f1 * f1 + f2 * f2 + f3 * f3;
            if (f1 > 0) tmp += a[ind][ind + 1];
            if (f2 > 0) tmp += a[ind][ind + 2];
            if (f3 > 0) tmp += a[ind][ind + 3];
            ret = max(ret, tmp);
          }
          flow[ind + 1] -= f1;
          flow[ind + 2] -= f2;
          flow[ind + 3] -= f3;
        }
      }
    }
    return mem[ind][flow] = ret;
  }
  if (ind == n - 5) {
    long long ret = -1;
    for (int f1 = lo[ind][ind + 1]; f1 <= hi[ind][ind + 1]; f1++) {
      if (f1 > flow[ind]) break;
      for (int f2 = lo[ind][ind + 2]; f2 <= hi[ind][ind + 2]; f2++) {
        if (f1 + f2 > flow[ind]) break;
        for (int f3 = lo[ind][ind + 3]; f3 <= hi[ind][ind + 3]; f3++) {
          if (f1 + f2 + f3 > flow[ind]) break;
          int f4 = flow[ind] - f1 - f2 - f3;
          if (lo[ind][ind + 4] <= f4 && f4 <= hi[ind][ind + 4]) {
            flow[ind + 1] += f1;
            flow[ind + 2] += f2;
            flow[ind + 3] += f3;
            flow[ind + 4] += f4;
            long long tmp = dp(ind + 1, flow);
            if (tmp != -1) {
              tmp += f1 * f1 + f2 * f2 + f3 * f3 + f4 * f4;
              if (f1 > 0) tmp += a[ind][ind + 1];
              if (f2 > 0) tmp += a[ind][ind + 2];
              if (f3 > 0) tmp += a[ind][ind + 3];
              if (f4 > 0) tmp += a[ind][ind + 4];
              ret = max(ret, tmp);
            }
            flow[ind + 1] -= f1;
            flow[ind + 2] -= f2;
            flow[ind + 3] -= f3;
            flow[ind + 4] -= f4;
          }
        }
      }
    }
    return mem[ind][flow] = ret;
  }
  long long ret = -1;
  for (int f1 = lo[ind][ind + 1]; f1 <= hi[ind][ind + 1]; f1++) {
    if (f1 > flow[ind]) break;
    for (int f2 = lo[ind][ind + 2]; f2 <= hi[ind][ind + 2]; f2++) {
      if (f1 + f2 > flow[ind]) break;
      for (int f3 = lo[ind][ind + 3]; f3 <= hi[ind][ind + 3]; f3++) {
        if (f1 + f2 + f3 > flow[ind]) break;
        for (int f4 = lo[ind][ind + 4]; f3 <= hi[ind][ind + 4]; f4++) {
          if (f1 + f2 + f3 + f4 > flow[ind]) break;
          int f5 = flow[ind] - f1 - f2 - f3 - f4;
          if (lo[ind][ind + 5] <= f5 && f5 <= hi[ind][ind + 5]) {
            flow[ind + 1] += f1;
            flow[ind + 2] += f2;
            flow[ind + 3] += f3;
            flow[ind + 4] += f4;
            flow[ind + 5] += f5;
            long long tmp = dp(ind + 1, flow);
            if (tmp != -1) {
              tmp += f1 * f1 + f2 * f2 + f3 * f3 + f4 * f4 + f5 * f5;
              if (f1 > 0) tmp += a[ind][ind + 1];
              if (f2 > 0) tmp += a[ind][ind + 2];
              if (f3 > 0) tmp += a[ind][ind + 3];
              if (f4 > 0) tmp += a[ind][ind + 4];
              if (f5 > 0) tmp += a[ind][ind + 5];
              ret = max(ret, tmp);
            }
            flow[ind + 1] -= f1;
            flow[ind + 2] -= f2;
            flow[ind + 3] -= f3;
            flow[ind + 4] -= f4;
            flow[ind + 5] -= f5;
          }
        }
      }
    }
  }
  return mem[ind][flow] = ret;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout << setprecision(32);
  cin >> n;
  int s, f, l, h, x;
  for (int i = 0; i < n * (n - 1) / 2; i++) {
    cin >> s >> f >> l >> h >> x;
    lo[s - 1][f - 1] = l;
    hi[s - 1][f - 1] = h;
    a[s - 1][f - 1] = x;
  }
  for (int fl = 1; fl <= 25; fl++) {
    vector<int> flow(n, 0);
    flow[0] = fl;
    long long tmp = dp(0, flow);
    if (tmp != -1) {
      cout << fl << " " << tmp;
      exit(0);
    }
  }
  cout << "-1 -1";
  return 0;
}
