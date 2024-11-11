#include <bits/stdc++.h>
using namespace std;
map<int, int> sci;
int a[200666], b[200666];
int main(void) {
  int n, i;
  cin >> n;
  for (i = 1; i <= n; ++i) {
    int xx;
    cin >> xx;
    sci[xx]++;
  }
  int m;
  cin >> m;
  for (i = 1; i <= m; ++i) cin >> a[i];
  for (i = 1; i <= m; ++i) cin >> b[i];
  int max_result_sat = -1, max_result_almost = -1, indice = 0;
  for (i = 1; i <= m; ++i) {
    int Rsatisfied = 0;
    if (sci.find(a[i]) != sci.end()) Rsatisfied = sci[a[i]];
    int Almost = 0;
    if (sci.find(b[i]) != sci.end()) Almost = b[i];
    if ((Rsatisfied > max_result_sat) ||
        (max_result_sat == Rsatisfied && Almost > max_result_almost)) {
      indice = i;
      max_result_sat = Rsatisfied;
      max_result_almost = Almost;
    }
  }
  cout << indice << '\n';
  return 0;
}
