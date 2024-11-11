#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 9;
bool arr[maxn];
int main() {
  int a, b, c, d, e, f, g, h;
  scanf("%d", &a);
  for (d = 1; d <= a; d++) {
    scanf("%d", &arr[d]);
  }
  for (d = 2, g = 0; d < a; d = e) {
    if (arr[d] != arr[d - 1] && arr[d] != arr[d + 1]) {
      for (e = d + 1; e < a; e++) {
        if (arr[e] == arr[e + 1]) {
          break;
        }
      }
      c = e - d;
      c++;
      c /= 2;
      g = max(g, c);
      c = e - d;
      if (c & 1) {
        for (f = d; f <= e; f++) {
          arr[f] = arr[d - 1];
        }
      } else {
        c /= 2;
        for (b = 0; b < c; b++) {
          arr[b + d] = arr[d - 1];
        }
        for (; b + d < e; b++) {
          arr[b + d] = arr[e];
        }
      }
    } else {
      e = d + 1;
    }
  }
  printf("%d\n", g);
  for (d = 1; d <= a; d++) printf("%d%c", arr[d], d == a ? '\n' : ' ');
  return 0;
}
