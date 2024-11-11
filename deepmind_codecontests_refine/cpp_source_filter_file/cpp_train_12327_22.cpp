#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  int inv = 0;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      if (a[i] > a[j]) inv++;
  if (inv == 1) {
    printf("0\n");
    return 0;
  }
  int ans = inv * 2;
  if (ans % 2 == 0) --ans;
  cout << ans << endl;
  return 0;
}
