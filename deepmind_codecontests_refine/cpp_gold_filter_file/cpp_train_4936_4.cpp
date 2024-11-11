#include <bits/stdc++.h>
using namespace std;
int nums, mins, totes, lows = 1000005;
int nlist[300005], csum[1000005];
bool kit;
int minim(int i, int j) {
  if (i < j) return i;
  return j;
}
int cl(int i) {
  if (i > 1000000) return 1000000;
  return i;
}
int main() {
  scanf("%d%d", &nums, &mins);
  for (int i = 1; i <= nums; i++) {
    scanf("%d", &nlist[i]);
    csum[nlist[i]]++;
    if (nlist[i] < lows) lows = nlist[i];
  }
  for (int i = 1; i <= 1000000; i++) {
    csum[i] = csum[i - 1] + csum[i];
  }
  totes = minim(mins, lows);
  for (int i = mins; i <= lows; i++) {
    kit = true;
    for (int j = 0; j <= 1000000; j += i) {
      if (csum[cl((j + i - 1))] - csum[cl(j + mins)]) {
        kit = false;
        break;
      }
    }
    if (kit) totes = i;
  }
  printf("%d\n", totes);
  return 0;
}
