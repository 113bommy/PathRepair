#include <bits/stdc++.h>
using namespace std;
int n_ex;
vector<int> v;
int ex[35];
long long D[35][100001];
int go(int a, int b, int h, int w, int n) {
  D[0][h] = w;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 100000; j++) {
      int curr_height = min((long long)ex[i] * j, 100000LL);
      D[i][curr_height] = max(D[i][curr_height], D[i - 1][j]);
      D[i][j] = max((long long)D[i][j], (long long)ex[i] * D[i - 1][j]);
    }
  }
  for (int i = 0; i <= n; i++) {
    for (int j = a; j <= 100000; j++) {
      if (D[i][j] >= b) {
        return i;
      }
    }
  }
  return 1e9;
}
int main() {
  int a, b, h, w, n;
  scanf("%d %d %d %d %d", &a, &b, &h, &w, &n);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    v.push_back(x);
  }
  sort(v.begin(), v.end());
  n_ex = 0;
  for (int i = v.size() - 1; i >= 0; i--) {
    n_ex++;
    ex[n_ex] = v[i];
    if (n_ex >= 34) {
      break;
    }
  }
  int hw = go(a, b, h, w, n_ex);
  int wh = go(b, a, h, w, n_ex);
  if (hw == 1e9 && wh == 1e9) {
    printf("-1");
  } else {
    printf("%d", min(hw, wh));
  }
  return 0;
}
