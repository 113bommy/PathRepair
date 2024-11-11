#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int i;
  vector<int> arr(2 * n - 1);
  int numNeg = 0;
  for (i = 0; i < 2 * n - 1; i++) {
    scanf("%d", &arr[i]);
    if (arr[i] < 0) {
      numNeg++;
      arr[i] *= -1;
    }
  }
  if (numNeg > n) numNeg -= n;
  if (numNeg & 1 == 0 || (n - numNeg) & 1 == 0)
    numNeg = 0;
  else
    numNeg = 1;
  sort((arr).begin(), (arr).end());
  int ans = 0;
  for (i = 0; i < numNeg; i++) ans += arr[i];
  ans *= -1;
  for (i = i; i < 2 * n - 1; i++) ans += arr[i];
  printf("%d\n", ans);
}
