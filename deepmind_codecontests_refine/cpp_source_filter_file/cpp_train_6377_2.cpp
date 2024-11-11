#include <bits/stdc++.h>
using namespace std;
int convtab[256];
char s[100005];
int n;
int data[200001];
int prefsums[200001];
int sufsums[200001];
int sufmax[200001];
int bestlen() {
  int left = 0;
  int right = 0;
  int best = 0;
  int lowleft;
  while (left < n) {
    lowleft = prefsums[left];
    right = max(right, left);
    while (right <= n && sufmax[right + 1] >= prefsums[left]) right++;
    best = max(best, right - left);
    while (left < n && prefsums[left] >= lowleft) left++;
  }
  return best;
}
int count_goodies_of(int k) {
  int ctr = 0;
  for (int i = 0; i <= n - k; i++) {
    if (prefsums[i + k] >= prefsums[i]) ctr++;
  }
  return ctr;
}
int main() {
  scanf("%s", s);
  n = strlen(s);
  fill(convtab, convtab + 256, 2);
  convtab['a'] = convtab['A'] = convtab['e'] = convtab['E'] = convtab['i'] =
      convtab['I'] = convtab['o'] = convtab['O'] = convtab['u'] = convtab['U'] =
          -1;
  prefsums[0] = 0;
  for (int i = 0; i < n; i++) {
    data[i + 1] = convtab[s[i]];
    prefsums[i + 1] = prefsums[i] + data[i + 1];
  }
  sufmax[n + 1] = -1000000000;
  for (int i = n - 1; i >= -1; i--) {
    sufmax[i + 1] = max(prefsums[i + 1], sufmax[i + 2]);
  }
  int len = bestlen();
  if (len == 0)
    printf("No solution\n");
  else
    printf("%d %d\n", len, count_goodies_of(len));
  return 0;
}
