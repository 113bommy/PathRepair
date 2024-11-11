#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n;
char str[N];
int maxScore[N], minScore[N], curScore[N];
int cnt[5 * N];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", str);
    int l = strlen(str);
    minScore[i] = N;
    for (int j = 0; j < l; j++) {
      curScore[i] += (str[j] == '(') ? 1 : -1;
      minScore[i] = min(minScore[i], curScore[i]);
      maxScore[i] = max(maxScore[i], curScore[i]);
    }
    if (minScore[i] == curScore[i]) {
      cnt[minScore[i] + N]++;
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (minScore[i] >= 0) {
      ans += cnt[-curScore[i] + N];
    }
  }
  printf("%lld\n", ans);
  return 0;
}
