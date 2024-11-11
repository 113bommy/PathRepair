#include <bits/stdc++.h>
using namespace std;
int di[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dj[] = {1, -1, 0, 0, -1, 1, 1, -1};
vector<int> lucky;
int intersect(int l, int r, int s, int e) {
  return max(0, min(r, e) - max(l, s) + 1);
}
int main() {
  int s1, e1, s2, e2, k;
  scanf("%d%d%d%d%d", &s1, &e1, &s2, &e2, &k);
  for (int i = 1; i <= 9; i++) {
    for (int j = 0; j < (1 << i); j++) {
      int num = 0;
      for (int k = 0; k < i; k++) {
        num *= 10;
        num += (j & (1 << k)) ? 7 : 4;
      }
      lucky.push_back(num);
    }
  }
  lucky.push_back(0);
  lucky.push_back(1e9 + 1);
  sort((lucky).begin(), (lucky).end());
  double ans = 0;
  int r = k - 1;
  while (++r < (int)lucky.size() - 1) {
    int l = r - k + 1;
    int a = intersect(s1, e1, lucky[l - 1] + 1, lucky[l]);
    int b = intersect(s2, e2, lucky[r], lucky[r + 1] - 1);
    ans += (a / (e1 - s1 + 1.0)) * (b / (e2 - s2 + 1.0));
    a = intersect(s2, e2, lucky[l - 1] + 1, lucky[l]);
    b = intersect(s1, e1, lucky[r], lucky[r + 1] - 1);
    ans += (a / (e2 - s2 + 1.0)) * (b / (e1 - s1 + 1.0));
    if (l == r && lucky[r] >= s1 && lucky[r] <= e1 && lucky[r] >= s2 &&
        lucky[r] <= e2)
      ans -= (1 / (e1 - s1 + 1.0)) * (b / (e2 - s2 + 1.0));
  }
  printf("%.10f", ans);
}
