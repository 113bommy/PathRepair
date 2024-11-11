#include <bits/stdc++.h>
using namespace std;
int cord[200000];
int nave[200000];
int main() {
  int m, i, a, b, c;
  char aux;
  cin >> m;
  for (i = 0; i < m; i++) {
    cin >> aux >> a >> aux >> b >> aux >> aux >> c;
    float aux = ((float)(a + b) / c) * 1000;
    nave[i] = aux;
    cord[(int)aux]++;
  }
  cout << cord[nave[0]];
  for (i = 1; i < m; i++) cout << ' ' << cord[nave[i]];
  cout << endl;
  return 0;
}
