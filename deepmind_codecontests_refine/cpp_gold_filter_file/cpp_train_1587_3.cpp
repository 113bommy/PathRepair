#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
int n;
int maxdiv[N];
void ailatuoseni() {
  maxdiv[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (maxdiv[i]) continue;
    for (int j = i; j <= n; j += i) {
      if (maxdiv[j]) continue;
      maxdiv[j] = j / i;
    }
  }
}
int main() {
  scanf("%d", &n);
  ailatuoseni();
  sort(maxdiv + 1, maxdiv + n + 1);
  for (int i = 2; i <= n; i++) printf("%d ", maxdiv[i]);
  printf("\n");
  return 0;
}
