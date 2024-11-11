#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, mini, maxi;
  scanf("%d%d%d%d", &n, &m, &mini, &maxi);
  vector<int> ar(m);
  map<int, int> cnt;
  for (int i = 0; i < m; i++) {
    scanf("%d", &ar[i]);
    cnt[ar[i]]++;
  }
  sort(ar.begin(), ar.end());
  if (cnt[mini] > 0 & cnt[maxi] > 0 & mini <= ar[0] & maxi >= cnt[m - 1]) {
    printf("Correct\n");
  } else if (n - m >= 2 & mini <= ar[0] & maxi >= cnt[m - 1]) {
    printf("Correct\n");
  } else if (n - m == 1) {
    if ((cnt[mini] > 0 & maxi >= ar[m - 1] & mini <= ar[0]) |
        (cnt[maxi] > 0 & maxi >= ar[m - 1] & mini <= ar[0])) {
      printf("Correct\n");
    } else {
      printf("Incorrect\n");
    }
  } else {
    printf("Incorrect\n");
  }
}
