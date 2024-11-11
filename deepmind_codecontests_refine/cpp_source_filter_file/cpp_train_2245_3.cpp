#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, Start, End, cnt;
  scanf("%d%d", &n, &k);
  char X[n];
  for (int i = 0; i < n; i++) scanf(" %c", &X[i]);
  for (int i = 0; i < n; i++) {
    if (X[i] == 'G')
      Start = i;
    else if (X[i] == 'T')
      End = i;
  }
  if (abs(Start - End) % k != 0) {
    printf("NO");
    return 0;
  }
  if (End < Start) swap(End, Start);
  for (int i = Start; i <= End; i++) {
    if (X[i] == '.') {
      cnt++;
      if (cnt % k == 0) cnt = 0;
    } else if (X[i] == '#') {
      cnt++;
      if (cnt % k == 0) {
        printf("NO");
        return 0;
      }
    }
  }
  printf("YES");
}
