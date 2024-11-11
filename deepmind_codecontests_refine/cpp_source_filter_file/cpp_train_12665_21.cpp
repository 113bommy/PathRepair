#include <bits/stdc++.h>
using namespace std;
const long double PI = acosl(-1);
int k, n;
char field[100][100];
int posib[100][100];
void simulate(int i, int j) {
  if (i + k <= n) {
    for (int p = 0; p < k; p++) {
      if (field[i + p][j] == '#') break;
      if (p == k - 1) {
        for (int s = 0; s < k; s++) {
          posib[i + s][j]++;
        }
      }
    }
  }
  if (j + k <= n) {
    for (int p = 0; p < k; p++) {
      if (field[i][j + p] == '#') break;
      if (p == k - 1) {
        for (int s = 0; s < k; s++) {
          posib[i][j + s]++;
        }
      }
    }
  }
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin.exceptions(cin.failbit);
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> field[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      simulate(i, j);
    }
  }
  int max = 0;
  int posi, posj;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (posib[i][j] > max) {
        max = posib[i][j];
        posi = i;
        posj = j;
      }
    }
  }
  cout << posi + 1 << " " << posj + 1 << endl;
}
