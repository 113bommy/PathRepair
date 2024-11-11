#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
long long s[maxn];
int a[maxn], bb[maxn];
int main() {
  int i, n, k, le, ri, mid;
  long long b;
  cin >> n >> k;
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    if (i == 0)
      s[i] = a[i];
    else
      s[i] = s[i - 1] + a[i];
  }
  for (int w = 0; w < k; w++) {
    cin >> b;
    int ss = 1000000000, q = 0;
    if (s[n - 1] <= b) {
      printf("1\n");
      continue;
    }
    for (i = 0; i < n; i++) {
      long long f;
      f = s[n - 1];
      if (i > 0) f = f - s[i - 1];
      if (f <= b) {
        le = 0;
        ri = i - 1;
        while (le <= ri) {
          mid = (le + ri) / 2;
          if (s[mid] + f <= b)
            le = mid + 1;
          else
            ri = mid - 1;
        }
        bb[i] = ri;
        if ((n - i) + le < ss) {
          ss = (n - i) + le;
          q = i;
        }
      } else {
        le = i;
        ri = n - 1;
        while (le <= ri) {
          mid = (le + ri) / 2;
          f = s[mid];
          if (i != 0) f = f - s[i - 1];
          if (f <= b)
            le = mid + 1;
          else
            ri = mid - 1;
        }
        if (le - i < ss) {
          ss = le - i;
          q = i;
        }
        bb[i] = ri;
      }
    }
    int sss = 1000000000;
    for (i = 0; i < ss; i++) {
      int p = (q + i) % n;
      int s = 0;
      int u = 0;
      while (s < n) {
        u++;
        p = (bb[p] + 1) % n;
        if (bb[p] >= p)
          s += bb[p] - p + 1;
        else
          s += (bb[p] + 1 + n - p);
      }
      sss = min(sss, u);
    }
    printf("%d\n", sss);
  }
}
