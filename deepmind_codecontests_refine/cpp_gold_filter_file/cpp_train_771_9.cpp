#include <bits/stdc++.h>
long long a[200001];
int main() {
  int i, j, k;
  int n;
  int ans;
  long long diff;
  bool first;
  const long long LLMAX = (long long)((1llu << 63) - 1);
  while (scanf("%d", &n) == 1) {
    ans = 0;
    for (i = 0; i < n; i++) {
      scanf("%I64d", &a[i]);
    }
    first = false;
    diff = LLMAX;
    for (i = 0; i < n; i++) {
      if (first) {
        if (a[i] == -1) {
          if (diff != LLMAX) {
            if (a[i - 1] + diff > 0) {
              a[i] = a[i - 1] + diff;
              continue;
            }
          } else {
            for (j = i + 1; j < n && a[j] == -1; j++)
              ;
            if (j < n) {
              if ((a[j] - a[i - 1]) % (j - (i - 1)) == 0) {
                diff = (a[j] - a[i - 1]) / (j - (i - 1));
                while (++i < j) a[i] = a[i - 1] + diff;
                continue;
              } else {
                diff = 0;
                while (++i < j) a[i] = a[i - 1];
                i--;
                continue;
              }
            } else {
              i = n;
              continue;
            }
          }
        } else {
          if (diff == LLMAX) {
            diff = a[i] - a[i - 1];
            continue;
          } else if (diff == a[i] - a[i - 1]) {
            continue;
          }
        }
      }
      if (a[i] == -1) {
        ans++;
        for (j = i + 1; j < n && a[j] == -1; j++)
          ;
        for (k = j + 1; k < n && a[k] == -1; k++)
          ;
        if (j == n || k == n) {
          break;
        }
        if ((a[k] - a[j]) % (k - j) == 0 &&
            a[j] - (a[k] - a[j]) / (k - j) * (j - i) > 0) {
          i = k;
          first = true;
          diff = (a[k] - a[j]) / (k - j);
        } else {
          i = k - 1;
          first = false;
        }
        continue;
      }
      first = true;
      diff = LLMAX;
      ans++;
    }
    printf("%d\n", ans);
  }
}
