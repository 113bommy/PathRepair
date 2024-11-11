#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, a[101], b[101] = {0}, count = 0;
  cin >> n >> m;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    if (b[a[i]] == 0) {
      b[a[i]] = i;
      count++;
    }
  }
  if (count >= m) {
    count = 0;
    cout << "YES" << endl;
    for (i = 1; i <= 100 && count <= m; i++)
      if (b[i] > 0) {
        cout << b[i] << " ";
        count++;
      }
    cout << endl;
  } else
    cout << "NO";
}
