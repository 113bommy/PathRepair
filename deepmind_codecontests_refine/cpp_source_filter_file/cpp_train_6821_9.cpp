#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  int *tab = new int[n];
  int *tab2 = new int[m];
  int *color = new int[k + 1];
  for (int i = 0; i < n; i++) tab[i] = 0;
  for (int i = 0; i < m; i++) tab2[i] = 0;
  color[0] = 0;
  int tmp1, tmp2;
  for (int i = 1; i < k; i++) {
    cin >> tmp1 >> tmp2 >> color[i];
    if (tmp1)
      tab[tmp2 - 1] == i;
    else
      tab2[tmp2 - 1] == i;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cout << color[max(tab[i], tab2[j])] << " ";
    cout << endl;
  }
  return 0;
}
