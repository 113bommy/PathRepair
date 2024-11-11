#include <bits/stdc++.h>
using namespace std;
bool sts[200010];
int l[200010];
int main() {
  memset((l), 0, sizeof(l));
  int n, i;
  scanf("%d", &n);
  for (i = (1); i < (n + 1); i++) {
    scanf("%d", &sts[i]);
    if (!sts[i]) l[i]++;
  }
  for (i = n; i >= 1; i--) l[i] += l[i + 1];
  unsigned long long int ans = 0;
  for (i = (1); i < (n + 1); i++)
    if (sts[i]) ans += l[i + 1];
  cout << ans << endl;
  return 0;
}
