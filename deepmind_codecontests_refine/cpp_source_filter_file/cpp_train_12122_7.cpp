#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int id[101] = {0};
  for (int i = 0; i < m; i++) {
    int swt;
    cin >> swt;
    for (int j = 1; j <= n; j++)
      if (!id[j] && j <= swt) id[j] = swt;
  }
  for (int i = 1; i <= n; i++)
    cout << id[i], (i < n ? cout << ' ' : cout << endl);
  return 0;
}
