#include <bits/stdc++.h>
using namespace std;
long long nums[1001];
int main() {
  long long n;
  long long themax = -1, themin = 999999999;
  long long mini, maxi;
  long long diff = 0;
  long long i;
  long long normalnums;
  scanf("%I64d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%I64d", &nums[i]);
  }
  for (i = 1; i <= n; i++) {
    if (nums[i] > themax) {
      themax = nums[i];
      maxi = i;
    }
    if (nums[i] < themin) {
      themin = nums[i];
      mini = i;
    }
  }
  if (themin == themax) {
    printf("Exemplary pages.\n");
    return 0;
  }
  if ((themin + themax) % 2 != 0) {
    printf("Unrecoverable configuration.\n");
    return 0;
  }
  normalnums = (themin + themax) / 2;
  for (i = 1; i <= n; i++) {
    if (nums[i] != normalnums) diff++;
  }
  if (diff != 2) {
    printf("Unrecoverable configuration.\n");
    return 0;
  }
  printf("%I64d ml. from cup #%I64d to cup #%I64d.\n", themax - normalnums,
         maxi, mini);
  return 0;
}
