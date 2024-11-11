#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int a[55];
  for (int i = 0; i < m; i++) cin >> a[i];
  sort(a, a + m);
  int diff = INT_MAX;
  for (int i = 0; i <= m - n + 1; i++) {
    int k = i + n - 1;
    int mini = INT_MAX;
    int maxi = INT_MIN;
    for (int j = i; j <= k; j++) {
      if (a[j] < mini)
        mini = a[j];
      else if (a[j] > maxi)
        maxi = a[j];
    }
    if ((maxi - mini) < diff) diff = maxi - mini;
  }
  cout << diff << endl;
  return 0;
}
