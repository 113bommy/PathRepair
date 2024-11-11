#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int pos_n = 1;
  int pos_m = 1;
  int aux = n - 1;
  while (aux / 7) {
    aux = aux / 7;
    pos_n++;
  }
  aux = m - 1;
  while (aux / 7) {
    aux = aux / 7;
    pos_m++;
  }
  int comb = 0;
  if (pos_n + pos_m <= 7) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        vector<int> used(7, 0);
        int a = i;
        for (int k = 0; k < pos_n; k++) {
          used[a % 7] += 1;
          a = a / 7;
        }
        int b = j;
        for (int k = 0; k < pos_m; k++) {
          used[b % 7] += 1;
          b = b / 7;
        }
        if (*std::max_element(used.begin(), used.end()) <= 1) comb++;
      }
    }
  }
  cout << comb;
  cout << endl;
  return 0;
}
