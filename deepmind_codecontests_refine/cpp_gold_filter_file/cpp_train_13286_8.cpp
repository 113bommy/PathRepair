#include <bits/stdc++.h>
using namespace std;
long long C[1010][1010];
void dabiao() {
  C[0][0] = 1;
  for (int i = 1; i < 1010; ++i) {
    C[i][0] = 1;
    for (int j = 1; j <= i; ++j) C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
  }
}
int main() {
  dabiao();
  int n, k;
  cin >> n >> k;
  if (k == 1)
    cout << 1 << endl;
  else if (k == 2)
    cout << C[n][2] + 1 << endl;
  else if (k == 3)
    cout << C[n][3] * 2 + C[n][2] + 1 << endl;
  else if (k == 4)
    cout << C[n][4] * 9 + C[n][3] * 2 + C[n][2] + 1 << endl;
}
