#include <bits/stdc++.h>
using namespace std;
int arr[20];
int mem[20][5];
int cat[20][5];
int mnz[20][5];
int mns[20][5];
int dp(int id, int c) {
  if (id == 20) return c == 0;
  if (cat[id][c]) return mem[id][c];
  for (int i = 0; i <= 6; ++i) {
    for (int j = 0; j + i <= 6; ++j) {
      int nz = i, ns = j, nf = 6 - nz - ns;
      int d = c * 10 + arr[id];
      int s = ns * 7 + nf * 4;
      if (s > d) continue;
      if (d - s > 4) continue;
      if (dp(id + 1, d - s)) {
        cat[id][c] = 1;
        mnz[id][c] = nz;
        mns[id][c] = ns;
        return mem[id][c] = true;
      }
    }
  }
  cat[id][c] = 1;
  return mem[id][c] = false;
}
int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    long long n;
    cin >> n;
    for (int i = 19; i >= 0; --i) {
      arr[i] = n % 10;
      n /= 10;
    }
    memset(cat, 0, sizeof(cat));
    int t = dp(0, 0);
    if (t == 0) {
      cout << -1 << endl;
    } else {
      int id = 0, c = 0;
      int arr2[] = {0, 0, 0, 0, 0, 0};
      while (id < 20) {
        int nz = mnz[id][c];
        int ns = mns[id][c];
        int nf = 6 - nz - ns;
        for (int i = 0; i < nz; ++i) arr2[i] = 10 * arr2[i] + 0;
        for (int i = nz; i < nz + nf; ++i) arr2[i] = 10 * arr2[i] + 4;
        for (int i = nz + nf; i < nz + nf + ns; ++i) arr2[i] = 10 * arr2[i] + 7;
        c = 10 * c + arr[id] - 4 * nf - 7 * ns;
        id++;
      }
      for (int i = 0; i < 6; ++i) cout << arr2[i] << " ";
      cout << endl;
    }
  }
}
