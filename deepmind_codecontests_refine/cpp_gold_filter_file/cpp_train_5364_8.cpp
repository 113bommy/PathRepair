#include <bits/stdc++.h>
using namespace std;
int main(int argc, const char* argv[]) {
  int n, p;
  scanf("%d%d", &n, &p);
  bool arr[n];
  for (int i = 0; i < n; ++i) {
    char man[9];
    scanf("%s", man);
    arr[i] = strlen(man) == 8;
  }
  int buy = n - 1;
  long long apple = 1;
  long long sum = p / 2;
  while (buy > 0) {
    buy--;
    if (arr[buy]) {
      sum += apple * p + p / 2;
      apple += apple + 1;
    } else {
      sum += apple * p;
      apple *= 2;
    }
  }
  printf("%lld\n", sum);
  return 0;
}
