#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const int N = 2e7 + 9, M = 1e7, OO = 0x3f3f3f3f;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, array[101], freq[101], i, diffrents[101], k = 0, x;
    scanf("%d %d", &n, &x);
    for (i = 0; i < n; ++i) {
      scanf("%d", &array[i]);
    }
    for (i = 0; i < 101; ++i) {
      freq[i] = 0;
    }
    for (i = 0; i < n; ++i) {
      freq[array[i]]++;
    }
    for (i = 1; i < 101; ++i) {
      if (freq[i] == 0) {
        diffrents[k] = i;
        k++;
      }
    }
    if (k == 0) {
      printf("%d\n", x + 100);
    } else {
      i = 0;
      while (x && i < k) {
        x--;
        freq[diffrents[i]]++;
        i++;
      }
      if (x == 0) {
        for (i = diffrents[i - 1]; i < 101; ++i) {
          if (freq[i] == 0) {
            printf("%d\n", i - 1);
            break;
          }
        }
      } else {
        printf("%d\n", 100 + x);
      }
    }
  }
  return 0;
}
