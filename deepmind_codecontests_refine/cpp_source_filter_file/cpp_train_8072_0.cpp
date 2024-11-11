#include <bits/stdc++.h>
using namespace std;
int t[100010];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &t[i]);
  }
  int ca = 0, cb = 0;
  int i, j;
  for (i = 1, j = n; i < j;) {
    if (ca <= cb)
      ca += t[i], i++;
    else
      cb += t[j], j--;
  }
  cout << i - 1 << " " << n - i + 1 << endl;
}
