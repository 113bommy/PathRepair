#include <bits/stdc++.h>
using namespace std;
int n, i, k[100], l = 0, v, j, a[1000];
int s[100][100];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> v;
  for (i = 0; i < n; i++) {
    cin >> k[i];
    for (j = 0; j < k[i]; j++) {
      cin >> s[i][j];
    }
  }
  for (i = 0; i < n; i++)
    for (j = 0; j < k[i]; j++) {
      if (s[i][j] < v) {
        l++;
        a[i] = k[i];
        break;
      }
    }
  cout << l << endl;
  for (i = 0; i < l; i++) {
    cout << a[i] << " ";
  }
  return 0;
}
