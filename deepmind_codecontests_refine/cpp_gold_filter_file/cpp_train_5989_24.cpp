#include <bits/stdc++.h>
using namespace std;
int main() {
  long long com[101][5] = {{0}};
  for (int i = 0; i <= 100; i++) com[i][0] = 1;
  for (int i = 1; i <= 100; i++) {
    for (int j = 1; j <= 4; j++) {
      com[i][j] = com[i - 1][j - 1] + com[i - 1][j];
    }
  }
  long long n;
  string cake[110];
  long long h = 0;
  int row[110] = {0};
  int col[110] = {0};
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> cake[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (cake[i][j] == 'C') {
        row[i]++;
        col[j]++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    h += com[row[i]][2];
    h += com[col[i]][2];
  }
  cout << h;
  return 0;
}
