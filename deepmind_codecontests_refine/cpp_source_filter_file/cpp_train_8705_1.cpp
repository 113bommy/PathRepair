#include <bits/stdc++.h>
using namespace std;
int n, m, k, r, t, l, ri, mid, Mx, A[40];
long long c;
vector<int> R, K;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &A[i]);
    A[i] %= m;
  }
  k = n / 2;
  r = (n + 1) / 2;
  for (int i = 0; i < 1 << r; i++) {
    c = 0;
    t = i;
    for (int j = 0; j < r; j++) {
      if (t % 2 == 1) {
        c += A[j];
      }
      t /= 2;
    }
    R.push_back(c % m);
  }
  for (int i = 0; i < 1 << k; i++) {
    c = 0;
    t = i;
    for (int j = 0; j < k; j++) {
      if (t % 2 == 1) {
        c += A[r + j];
      }
      t /= 2;
    }
    K.push_back(c % m);
  }
  sort(K.begin(), K.end());
  sort(R.begin(), R.end());
  Mx = max(R[(int)R.size() - 1], K[(int)K.size() - 1]);
  for (int i = 0; i < (int)K.size(); i++) {
    l = 0;
    ri = (int)R.size();
    while (ri - l > 1) {
      mid = (l + ri) / 2;
      if (m - 1 - K[i] < mid) {
        ri = mid;
      } else {
        l = mid;
      }
    }
    if (l < (int)R.size() - 1) {
      Mx = max(Mx, (K[i] + R[l + 1]) % m);
    }
    Mx = max(Mx, (K[i] + R[l]) % m);
  }
  printf("%d", Mx);
  return (0);
}
