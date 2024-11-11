#include <bits/stdc++.h>
using namespace std;
int l[200005];
int sefr[200005];
int yek[200005];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> l[i];
  }
  l[0] = l[n + 1] = 0;
  for (int i = 1; i <= n; ++i) {
    if (l[i] == 1)
      yek[i] = yek[i - 1] + 1;
    else
      yek[i] = yek[i - 1];
  }
  for (int i = n; i >= 1; --i) {
    if (l[i] == 0)
      sefr[i] = sefr[i + 1] + 1;
    else
      sefr[i] = sefr[i + 1];
  }
  int k, j;
  int viss = 0;
  int visy = 0;
  int ans = 0;
  k = 1;
  j = n;
  while (k < j) {
    while (l[k] == 0) ++k;
    while (l[j] == 1) --j;
    if (k >= j) break;
    if (sefr[k] - viss <= yek[j] - visy) {
      ans += sefr[k] - viss;
      k++;
      visy++;
    } else {
      ans += yek[j] - visy;
      j--;
      viss++;
    }
  }
  cout << ans << endl;
  ;
  return 0;
}
