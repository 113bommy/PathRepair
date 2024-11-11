#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
using namespace std;
int a[maxn];
int vis[maxn];
int step[maxn * 2];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    int temp = a[i];
    int step1 = 0, step2 = 0, step3 = 0;
    while (temp < maxn) {
      step1++;
      vis[temp]++;
      temp = temp << 1;
      step[temp] += step1;
    }
    while (a[i] >= 1) {
      if (a[i] & 1 && a[i] != 1) {
        int temp1 = a[i];
        int temp2 = a[i] = a[i] >> 1;
        step2++;
        step3 = step2;
        vis[temp2]++;
        step[temp2] += step3;
        while (temp2 < maxn) {
          step3++;
          temp2 = temp2 << 1;
          vis[temp2]++;
          step[temp2] += step3;
        }
      } else {
        step2++;
        a[i] = a[i] >> 1;
        vis[a[i]]++;
        step[a[i]] += step2;
      }
    }
  }
  int ans = 1e9;
  for (int i = 1; i < maxn; i++) {
    if (vis[i] == n) {
      ans = min(step[i], ans);
    }
  }
  printf("%d\n", ans);
  return 0;
}
