#include <bits/stdc++.h>
using namespace std;
int ans[5000];
int a[5000];
int N;
int main(void) {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%d", &a[i]);
  int used[5000];
  for (int i = 0; i < N; i++) {
    memset(used, 0, sizeof(used));
    ans[a[i]]++, used[a[i]]++;
    int mx = a[i];
    for (int j = i + 1; j < N; j++) {
      used[a[j]]++;
      if (used[a[j]] > used[mx] || (used[a[j]] == used[mx] && a[j] < mx))
        mx = a[j];
      ans[mx]++;
    }
  }
  for (int i = 1; i <= N; i++) printf("%d ", ans[i]);
  return 0;
}
