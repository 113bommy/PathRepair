#include <bits/stdc++.h>
using namespace std;
int n;
int A[100010];
bool m;
int main() {
  scanf("%d", &n);
  m = true;
  for (int i = 0; i < 100010; i++) A[i] = -1;
  for (int i = 0; i < n; i++) {
    int y, k;
    cin >> y >> k;
    if (A[k] == -1 && y == 0) {
      A[k] = y;
      continue;
    }
    if (A[k] == -1 && y != 0) {
      m = false;
      continue;
    }
    if (A[k] >= y) continue;
    if (A[k] + 1 == y)
      A[k] = y;
    else
      m = false;
  }
  if (m == true)
    cout << "YES";
  else
    cout << "NO" << endl;
  return 0;
}
