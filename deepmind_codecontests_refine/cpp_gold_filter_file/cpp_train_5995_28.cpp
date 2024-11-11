#include <bits/stdc++.h>
using namespace std;
const int maxn = 1035;
#pragma GCC Optimize("Ofast")
int a[2][maxn];
int main() {
  int n, k, x;
  cin >> n >> k >> x;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    a[0][num]++;
  }
  int o = 1, O = 0;
  for (int i = 0; i < k; i++) {
    o = (i % 2), O = ((i + 1) % 2);
    bool par = 0;
    memset(a[O], 0, sizeof a[O]);
    for (int j = 0; j < 1024; j++) {
      int num = a[o][j], t_fix, t_ch;
      if (num % 2) {
        if (par == 0) {
          t_ch = (num / 2) + (num % 2);
          t_fix = (num / 2);
        } else {
          t_fix = (num / 2) + (num % 2);
          t_ch = (num / 2);
        }
        par = !par;
      } else {
        t_ch = t_fix = num / 2;
      }
      a[O][j] += t_fix;
      a[O][j ^ x] += t_ch;
    }
  }
  int Min, Max;
  for (int i = 0; i < 1024; i++) {
    if (a[O][i] > 0) {
      Min = i;
      break;
    }
  }
  for (int i = 1024 - 1; i >= 0; i--) {
    if (a[O][i] > 0) {
      Max = i;
      break;
    }
  }
  cout << Max << " " << Min;
}
