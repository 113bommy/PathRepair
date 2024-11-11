#include <bits/stdc++.h>
using namespace std;
int n, k;
string second[1003];
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> second[i];
  k = 13;
  for (int i = 1; i < n; i++)
    for (int j = i + 1; j <= n; j++) {
      int diff = 0;
      for (int l = 0; l < 6; l++)
        if (second[i][l] != second[j][l]) diff++;
      k = min(k, diff);
    }
  cout << (k - 1) / 2 << endl;
  return 0;
}
