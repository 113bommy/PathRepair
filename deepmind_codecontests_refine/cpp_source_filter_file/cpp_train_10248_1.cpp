#include <bits/stdc++.h>
using namespace std;
bool b[101];
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int a[n + 1];
  int s[n + 1];
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  int ind = 0;
  for (int i = 0; i < m; i++) {
    int x;
    scanf("%d", &x);
    b[x] = true;
    s[ind++] = x;
  }
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    if (!b[i]) sum += a[i];
  }
  sort(s, s + ind);
  for (int i = ind - 1; i >= 0; i--) {
    if (sum < a[s[i]])
      sum += a[s[i]];
    else
      sum += sum;
  }
  cout << sum;
  return 0;
}
