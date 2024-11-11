#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l, int r) { return l + rng() % (r - l + 1); }
const int N = (1 << 22) + 5;
int f1[N], f2[N], a[N], n;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    f1[a[i]] = f2[a[i]];
    f2[a[i]] = i;
  }
  int ma = (1 << 22) - 1;
  for (int i = 0; i <= 21; ++i) {
    for (int j = ma; j >= 0; j--)
      if (!((j >> i) & 1)) {
        if (f2[j] < f2[(j ^ (1 << i))]) {
          f1[j] = f2[j];
          f2[j] = f2[(j ^ (1 << i))];
          f1[j] = max(f1[j], f1[(j ^ (1 << i))]);
        } else
          f1[j] = max(f1[j], f2[(j ^ (1 << i))]);
      }
  }
  int kq = 0;
  for (int i = 1; i <= n - 2; ++i) {
    int res = 0;
    for (int j = 21; j >= 0; j--) {
      int tmp = res;
      if (!((a[i] >> j) & 1)) tmp += (1 << j);
      if (f1[tmp] > i) res = tmp;
    }
    kq = max(kq, (res | a[i]));
  }
  cout << kq;
}
