#include <bits/stdc++.h>
using namespace std;
vector<int> numZ, numF;
int main() {
  int n, t;
  scanf("%d", &n);
  int cnt1 = 0, sum = 0, cnt2 = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &t);
    if (t >= 0) {
      numZ.push_back(t);
      sum += t;
    } else
      numF.push_back(t);
    if (t > 0 && t % 2)
      cnt1++;
    else if (t < 0 && t % 2)
      cnt2++;
  }
  sort(numZ.begin(), numZ.end());
  sort(numF.begin(), numF.end());
  int ans = 0;
  if (cnt1 % 2)
    printf("%d\n", sum);
  else {
    if (cnt1 == 0) {
      int sign = -1;
      for (int i = numF.size() - 1; i >= 0; i--) {
        if (numF[i] % 2) {
          sign = i;
          break;
        }
      }
      printf("%d\n", sum + numF[sign]);
    } else {
      int sign1 = -1, sign2 = -1;
      for (int i = 0; i < numZ.size(); i++) {
        if (numZ[i] % 2) {
          sign1 = i;
          break;
        }
      }
      if (cnt2 == 0) {
        printf("%d\n", sum - numZ[sign1]);
        return 0;
      }
      for (int i = numF.size() - 2; i >= 0; i--) {
        if (numF[i] % 2) {
          sign2 = i;
          break;
        }
      }
      printf("%d\n", sum - min(numZ[sign1], abs(numF[sign2])));
    }
  }
  return 0;
}
