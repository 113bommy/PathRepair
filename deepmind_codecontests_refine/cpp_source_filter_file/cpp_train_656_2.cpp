#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  int res = 0;
  scanf("%d", &N);
  int i;
  for (i = 0; i < N; i++) {
    int temp;
    scanf("%d", &temp);
    res += temp * temp;
  }
  printf("%d\n", res);
  return 0;
}
