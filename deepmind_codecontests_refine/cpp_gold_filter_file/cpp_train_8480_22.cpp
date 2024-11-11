#include <bits/stdc++.h>
using namespace std;
int sol = 0;
int gems[100000];
int cuantas[30001][2020];
void computa(int len, int pos, int amount) {
  if (pos > 30000) {
    sol = max(sol, amount);
    return;
  }
  if (len > 1) computa(len - 1, pos + len - 1, amount + gems[pos]);
  computa(len, pos + len, amount + gems[pos]);
  computa(len + 1, pos + len + 1, amount + gems[pos]);
}
int main() {
  int n, d;
  cin >> n >> d;
  for (int i = 0; i < n; i++) {
    int pos;
    cin >> pos;
    gems[pos]++;
  }
  if (d >= 2000)
    computa(d, d, 0);
  else
    for (int i = 30000; i >= 0; i--)
      for (int j = 1; j < 2020; j++)
        cuantas[i][j] =
            gems[i] + max((j - 1 > 0 and i + j - 1 <= 30000)
                              ? cuantas[i + j - 1][j - 1]
                              : 0,
                          max(i + j <= 30000 ? cuantas[i + j][j] : 0,
                              (j + 1 < 2020 and i + j + 1 <= 30000)
                                  ? cuantas[i + j + 1][j + 1]
                                  : 0));
  cout << max(sol, cuantas[d][d]) << endl;
}
