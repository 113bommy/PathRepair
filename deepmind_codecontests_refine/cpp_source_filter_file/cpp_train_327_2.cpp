#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  string s;
  int pSum1[200004];
  int pSum2[200004];
  int min1, min2, max1, max2;
  int fmin, fmax, lmin, lmax;
  int width, heigth, pwidth, pheigth;
  int i1, i2;
  long long ans;
  for (int i = 0; i < T; i++) {
    s.clear();
    cin >> s;
    pSum1[0] = 0;
    pSum2[0] = 0;
    min1 = 0;
    min2 = 0;
    max1 = 0;
    max2 = 0;
    i1 = 0, i2 = 0;
    for (int j = 0; j < s.length(); j++) {
      if (s[j] == 'W') {
        pSum1[i1 + 1] = pSum1[i1] + 1;
        if (pSum1[i1 + 1] > max1) max1 = pSum1[i1 + 1];
        i1++;
      }
      if (s[j] == 'S') {
        pSum1[i1 + 1] = pSum1[i1] - 1;
        if (pSum1[i1 + 1] < min1) min1 = pSum1[i1 + 1];
        i1++;
      }
      if (s[j] == 'A') {
        pSum2[i2 + 1] = pSum2[i2] - 1;
        if (pSum2[i2 + 1] < min2) min2 = pSum2[i2 + 1];
        i2++;
      }
      if (s[j] == 'D') {
        pSum2[i2 + 1] = pSum2[i2] + 1;
        if (pSum2[i2 + 1] > max2) max2 = pSum2[i2 + 1];
        i2++;
      }
    }
    width = max2 - min2 + 1;
    heigth = max1 - min1 + 1;
    pwidth = width;
    pheigth = heigth;
    fmin = -1;
    fmax = -1;
    for (int j = 0; j < i1 + 2; j++) {
      if (pSum1[j] == min1) {
        lmin = j;
        if (fmin == -1) fmin = j;
      }
      if (pSum1[j] == max1) {
        lmax = j;
        if (fmax == -1) fmax = j;
      }
    }
    if ((fmin < lmax || fmax < lmin) && heigth > 2) pheigth--;
    fmin = -1;
    fmax = -1;
    for (int j = 0; j < i2 + 2; j++) {
      if (pSum2[j] == min2) {
        lmin = j;
        if (fmin == -1) fmin = j;
      }
      if (pSum2[j] == max2) {
        lmax = j;
        if (fmax == -1) fmax = j;
      }
    }
    if ((fmin > lmax || fmax > lmin) && width > 2) pwidth--;
    ans = min((long long)heigth * pwidth, (long long)pheigth * width);
    cout << ans << '\n';
  }
}
