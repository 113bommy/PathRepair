#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, m;
  cin >> n >> m;
  long long int mat1[n][m], mat2[n][m];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> mat1[i][j];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> mat2[i][j];
  bool exist = true;
  for (int i = 0; i < n; i++) {
    long long int cnt1 = 0, cnt2 = 0;
    for (int j = 0; j < m; j++) {
      if (mat1[i][j] == 1) cnt1++;
      if (mat2[i][j] == 1) cnt2++;
    }
    if (cnt1 % 2 != cnt2 % 2) exist = false;
  }
  long long int cntA = 0, cntB = 0;
  for (int j = 0; j < m; j++) {
    long long int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
      if (mat1[i][j] == 1) cnt1++, cntA++;
      if (mat2[i][j] == 1) cnt2++, cntB++;
    }
    if (cnt1 % 2 != cnt2 % 2) exist = false;
  }
  if (cntA % 2 != cntB % 2) exist = false;
  cout << (exist ? "YES" : "NO") << endl;
  return 0;
}
