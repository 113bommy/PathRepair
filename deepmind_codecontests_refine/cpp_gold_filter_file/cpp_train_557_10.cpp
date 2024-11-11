#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000001;
char sol[MAXN];
int main() {
  int n;
  scanf("%d", &n);
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    if (sum + x <= 500) {
      sol[i] = 'A';
      sum += x;
    } else {
      sol[i] = 'G';
      sum -= y;
    }
  }
  if (abs(sum) > 500) {
    printf("-1\n");
  } else {
    for (int i = 0; i < n; ++i) printf("%c", sol[i]);
    printf("\n");
  }
  return 0;
}
