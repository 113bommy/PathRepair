#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 7;
int N, er[maxn], we[maxn];
long long int ans = 0;
int main() {
  scanf("%d", &N);
  int i, j;
  for (i = 1, j = 1; i <= N; i++) {
    scanf("%d", &er[i]);
    while (j > 2 && we[j - 2] >= we[j - 1] && er[i] >= we[j - 1]) {
      ans += min(we[j - 2], er[i]);
      j--;
    }
    we[j++] = er[i];
  }
  sort(we + 1, we + j);
  for (i = 1; i < j - 2; i++) ans += we[i];
  cout << ans << endl;
  return 0;
}
