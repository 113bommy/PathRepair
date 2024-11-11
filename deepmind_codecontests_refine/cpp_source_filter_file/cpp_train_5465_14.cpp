#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, s, q;
  scanf("%d%d%d", &t, &s, &q);
  int rem = t - s;
  int downloaded = s;
  int out = 1;
  int pos = 0;
  while (downloaded < t) {
    downloaded += q - 1;
    pos += q;
    if (downloaded >= t) break;
    if (pos > downloaded) {
      pos = 0;
      out++;
    }
  }
  printf("%d", out);
  return 0;
}
