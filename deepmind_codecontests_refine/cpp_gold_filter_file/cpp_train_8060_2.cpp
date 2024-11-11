#include <bits/stdc++.h>
using namespace std;
int n, k;
int num[110];
int main() {
  string str;
  while (~scanf("%d%d", &n, &k)) {
    for (int i = 0; i < n; i++) {
      scanf("%d", &num[i]);
    }
    sort(num, num + n);
    printf("%d\n", num[n - k]);
  }
  return 0;
}
