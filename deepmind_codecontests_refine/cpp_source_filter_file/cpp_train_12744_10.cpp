#include <bits/stdc++.h>
using namespace std;
template <typename X>
inline X abs(const X& a) {
  return (a < 0 ? -a : a);
}
template <typename X>
inline X sqr(const X& a) {
  return (a * a);
}
void solveD() {
  int** se = new int*[5001];
  for (int i = 0; i < 5001; ++i) se[i] = new int[5001];
  int** itg = new int*[5001];
  for (int i = 0; i < 5001; ++i) itg[i] = new int[5001];
  int n, m;
  cin >> n;
  cin >> m;
  for (int i = 0; i < int(m); i++)
    for (int j = 0; j < int(m); j++) {
      se[i][j] = 0;
      itg[i][j] = 0;
    }
  char ar[5010];
  for (int i = 0; i < int(n); i++) {
    scanf("%s", &ar);
    int s = 0, len = 0;
    while (s < m) {
      if (ar[s] == '1')
        len++;
      else {
        if (len > 0) se[s - len][s - 1]++;
        len = 0;
      }
      s++;
    }
    if (len > 0) se[s - len][s - 1]++;
  }
  itg[0][m - 1] = se[0][m - 1];
  for (int j = int(m - 1) - 1; j >= 0; j--)
    itg[0][j] = itg[0][j + 1] + se[0][j];
  for (int i = 0; i < int(m); i++)
    if (i != 0) itg[i][m - 1] = itg[i - 1][m - 1] + se[i][m - 1];
  int bst = 0;
  for (int i = 0; i < int(m); i++)
    for (int j = int(m) - 1; j >= 0; j--) {
      if (i != 0 && j != m - 1) {
        itg[i][j] =
            se[i][j] + itg[i - 1][j] + itg[i][j + 1] - itg[i - 1][j + 1];
      }
    }
  for (int i = 0; i < int(m); i++)
    for (int j = int(m) - 1; j >= 0; j--) {
      if (j - i - 1 < 0) continue;
      bst = max(bst, itg[i][j] * (j - i + 1));
    }
  delete[] se;
  delete[] itg;
  cout << bst << endl;
}
int main() { solveD(); }
