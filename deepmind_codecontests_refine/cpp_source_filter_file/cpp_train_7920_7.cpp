#include <bits/stdc++.h>
using namespace std;
int asked = 0;
int ask(int dis) {
  printf("%d\n", dis);
  fflush(stdout);
  int result;
  scanf("%d", &result);
  asked++;
  return result;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int round[30], r = 0;
  for (int i = 0; i < m; i++, r = (r + 1) % m) {
    int ans = ask(n);
    if (ans == 0) exit(0);
    round[r] = ans == -1 ? 1 : -1;
  }
  int max = n + 1;
  int min = 0;
  while (asked != 60) {
    int mid = (max + min) / 2;
    int result = ask(mid) * round[r];
    r = (r + 1) % m;
    if (result == 1)
      min = mid + 1;
    else if (result == -1)
      max = mid - 1;
    else if (result == 0)
      exit(0);
  }
}
