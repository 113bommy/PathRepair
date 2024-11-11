#include <bits/stdc++.h>
using namespace std;
int num, mask[300], my, base = 0, wei[300][5], cnt[3000], aa[3000], bb[3000],
                        cc[3000], dd[3000], cntans = 0;
bool good[300], uu[10];
int main() {
  cin >> num;
  if (num > 6) {
    cout << "0" << endl;
    return 0;
  }
  memset(uu, false, sizeof(uu));
  for (int i = 0; i < num; i++) cin >> my, base |= 1 << my, uu[my] = true;
  mask[0] = 1;
  good[0] = uu[0];
  wei[0][cnt[0]++] = 0;
  for (int i = 1; i < 257; i++) {
    good[i] = true;
    cnt[i] = 0;
    mask[i] = 0;
    int x = i;
    while (x > 0) {
      mask[i] |= 1 << (x % 10);
      if (!uu[x % 10]) good[i] = false;
      wei[i][cnt[i]++] = x % 10;
      x /= 10;
    }
  }
  for (int a = 0; a < 257; a++) {
    if (good[a])
      for (int b = 0; b < 257; b++) {
        if (good[b])
          for (int c = 0; c < 257; c++) {
            int t = 0;
            t |= mask[a];
            t |= mask[b];
            t |= mask[c];
            if (good[c] && t == base)
              for (int d = 0; d < 257; d++) {
                if (!good[d]) continue;
                int q[20], nn = 0;
                for (int i = cnt[a] - 1; i > -1; i--) q[nn++] = wei[a][i];
                for (int i = cnt[b] - 1; i > -1; i--) q[nn++] = wei[b][i];
                for (int i = cnt[c] - 1; i > -1; i--) q[nn++] = wei[c][i];
                for (int i = cnt[d] - 1; i > -1; i--) q[nn++] = wei[d][i];
                bool ok = true;
                for (int i = 0; i < nn - i - 1; i++)
                  if (q[i] != q[nn - i - 1]) {
                    ok = false;
                    break;
                  }
                if (ok)
                  aa[cntans] = a, bb[cntans] = b, cc[cntans] = c,
                  dd[cntans++] = d;
              }
          }
      }
  }
  cout << cntans << endl;
  for (int i = 0; i < cntans; i++)
    cout << aa[i] << "." << bb[i] << "." << cc[i] << "." << dd[i] << endl;
  return 0;
}
