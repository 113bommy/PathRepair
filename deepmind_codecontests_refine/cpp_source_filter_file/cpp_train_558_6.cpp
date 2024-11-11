#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  vector<int> M;
  int ara[101];
  int l10 = 0, l100 = 0, div10 = 0;
  for (int i = 0; i < (int)n; i++) {
    scanf("%d", &ara[i]);
    if (ara[i] == 0 || ara[i] == 100) M.push_back(ara[i]);
  }
  for (int i = 0; i < n; i++) {
    if (ara[i] < 10 && l10 == 0 && ara[i] != 0 && ara[i] != 100) {
      M.push_back(ara[i]);
      l10 = 1;
    } else if (ara[i] % 10 == 0 && div10 == 0 && ara[i] != 0 && ara[i] != 100) {
      div10 = 1;
      M.push_back(ara[i]);
    }
  }
  if (l10 == 0 && div10 == 0) {
    for (int i = 0; i < n; i++)
      if (ara[i % 10]) {
        M.push_back(ara[i]);
        break;
      }
  }
  cout << M.size() << endl;
  cout << M[0];
  for (int i = 1; i < M.size(); i++) cout << " " << M[i];
  cout << endl;
  return 0;
}
