#include <bits/stdc++.h>
using namespace std;
int prefix[100000];
int suffix[100000];
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  string a, b, s1, s2;
  cin >> a >> b;
  int asize = a.size();
  int bsize = b.size();
  fill(prefix, prefix + bsize, 1e6);
  fill(suffix, suffix + bsize, 1e6);
  int pos = 0;
  for (int i = 0; i < asize; i++) {
    if (pos < bsize && a[i] == b[pos]) {
      prefix[pos++] = i + 1;
    }
  }
  pos = bsize - 1;
  for (int i = asize - 1; i >= 0; i--) {
    if (pos >= 0 && a[i] == b[pos]) {
      suffix[pos--] = (asize - 1) - i + 1;
    }
  }
  int ans_px = -1;
  int ans_sx = 1e6;
  int max_num = 0;
  for (int i = 1; i < bsize; i++) {
    if (prefix[i - 1] < asize && i > max_num) {
      ans_px = i;
      ans_sx = 1e6;
      max_num = i;
    }
  }
  for (int i = bsize - 1; i >= 0; i--) {
    if (suffix[i] < asize && bsize - i > max_num) {
      ans_px = -1;
      ans_sx = i;
      max_num = bsize - i;
    }
  }
  int px = 1, sx = 1;
  while (px < bsize && prefix[px - 1] < asize) {
    while (sx < bsize && prefix[px - 1] + suffix[sx] > asize) sx++;
    if (prefix[px - 1] + suffix[sx] <= asize && bsize - (sx - px) > max_num) {
      ans_px = px;
      ans_sx = sx;
      max_num = bsize - (sx - px);
    }
    px++;
    if (sx < px) sx = px;
  }
  if (ans_px < 0 && bsize <= ans_sx) {
    cout << "-" << endl;
    return 0;
  }
  for (int i = 0; i < ans_px; i++) cout << b[i];
  for (int i = ans_sx; i < bsize; i++) cout << b[i];
  cout << endl;
}
