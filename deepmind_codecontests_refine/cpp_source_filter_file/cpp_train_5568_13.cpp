#include <bits/stdc++.h>
using namespace std;
const int MaxD = 1001;
int main() {
  int n, n_l, n_r, w[MaxD] = {0}, w_l[MaxD] = {0}, w_r[MaxD] = {0},
                   h[MaxD] = {0}, h_l[MaxD] = {0}, h_r[MaxD] = {0},
                   p[MaxD] = {0}, p_b[MaxD] = {0}, p_r[MaxD] = {0}, maximum = 0,
                   minimum = 0, r, sk_b, w_b, W_last, W_red, m;
  unsigned long long ats = 1e18;
  unsigned long long ats_1;
  bool ar;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> w[i] >> h[i];
    if (max(w[i], h[i]) > maximum) maximum = max(w[i], h[i]);
    p[i] = min(w[i], h[i]);
  }
  for (int i = 1; i <= n; i++) {
    minimum = max(p[i], minimum);
  }
  r = n / 2;
  if (n == 1)
    ats = w[1] * h[1];
  else {
    for (int i = minimum; i <= maximum; i++) {
      sk_b = 0;
      for (int j = 1; j <= n; j++) {
        p_b[j] = 0;
      }
      for (int j = 1; j <= n; j++) {
        if (h[j] > i) {
          sk_b = sk_b + 1;
          p_b[sk_b] = j;
        }
      }
      if (sk_b <= r) {
        w_b = 0;
        for (int j = 1; j <= sk_b; j++) {
          w_b = w_b + h[p_b[j]];
        }
        for (int j = 1; j <= n; j++) {
          w_l[j] = 0;
          h_l[j] = 0;
        }
        m = 0;
        n_l = 0;
        for (int j = 1; j <= n; j++) {
          if ((p_b[1 + m] == j) && (m != sk_b))
            m = m + 1;
          else {
            n_l = n_l + 1;
            w_l[n_l] = w[j];
            h_l[n_l] = h[j];
          }
        }
        W_last = 0;
        for (int j = 1; j <= n_l; j++) {
          W_last = w_l[j] + W_last;
        }
        if (sk_b == r) {
          ats_1 = (W_last + w_b) * i;
          ats = min(ats, ats_1);
        }
        n_r = 0;
        for (int j = 1; j <= n; j++) {
          w_r[j] = 0;
          h_r[j] = 0;
        }
        for (int j = 1; j <= n_l; j++) {
          if ((w_l[j] <= i) && (w_l[j] > h_l[j])) {
            n_r = n_r + 1;
            w_r[n_r] = h_l[j];
            h_r[n_r] = w_l[j];
            w_l[j] = 0;
            h_l[j] = 0;
          }
        }
        W_last = 0;
        for (int j = 1; j <= n_l; j++) {
          W_last = w_l[j] + W_last;
        }
        for (int k = 1; k <= n_r - 1; k++) {
          for (int j = 1; j <= n_r - 1; j++) {
            if ((w_r[j] - h_r[j]) < (w_r[j + 1] - h_r[j + 1])) {
              m = w_r[j];
              w_r[j] = w_r[j + 1];
              w_r[j + 1] = m;
              m = h_r[j];
              h_r[j] = h_r[j + 1];
              h_r[j + 1] = m;
            }
          }
        }
        W_red = 0;
        for (int j = 1; j <= n_r; j++) {
          if (j <= (r - sk_b))
            W_red = W_red + w_r[j];
          else
            W_red = W_red + h_r[j];
        }
        ats_1 = (W_last + W_red + w_b) * i;
        ats = min(ats, ats_1);
      }
    }
  }
  cout << ats;
  return 0;
}
