#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 1;
int str[MAX];
char ans[MAX];
int main(void) {
  int n, index = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &str[i]);
  }
  int l = 1, r = n, m = -1;
  while (l <= r) {
    if (str[l] == str[r] && str[l] > m) {
      for (int i = l + 1, j = r - 1;; i++, j--) {
        if (str[i] <= str[i - 1]) {
          while (str[r] > m) {
            ans[index] = 'R';
            m = str[r];
            index++;
            r--;
          }
          break;
        } else if (str[j] <= str[j + 1]) {
          while (str[l] > m) {
            ans[index] = 'L';
            m = str[l];
            index++;
            l++;
          }
          break;
        }
      }
    } else if (str[l] < str[r] && str[l] > m) {
      ans[index] = 'L';
      m = str[l];
      index++;
      l++;
    } else if (str[r] < str[l] && str[r] > m) {
      ans[index] = 'R';
      m = str[r];
      index++;
      r--;
    } else if (str[l] <= m && str[r] > m) {
      ans[index] = 'R';
      m = str[r];
      index++;
      r--;
    } else if (str[l] > m && str[r] <= m) {
      ans[index] = 'L';
      m = str[l];
      index++;
      l++;
    } else
      break;
  }
  if (str[l] == str[r] && str[l] > m) {
    ans[index] = 'L';
    index++;
  }
  printf("%d\n%s", index, ans);
  return 0;
}
