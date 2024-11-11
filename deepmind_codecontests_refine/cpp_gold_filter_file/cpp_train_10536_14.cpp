#include <bits/stdc++.h>
using namespace std;
int q;
char dirs[100000];
int l, r, u, d;
int main() {
  cin >> q;
  for (int i = 0; i < q + 1; ++i) {
    char c;
    int ind = 0;
    l = r = u = d = 0;
    while ((c = getchar()) != '\n') {
      dirs[ind] = c;
      ++ind;
    }
    for (int j = 0; j < ind; ++j) {
      if (dirs[j] == 'L')
        ++l;
      else if (dirs[j] == 'R')
        ++r;
      else if (dirs[j] == 'U')
        ++u;
      else
        ++d;
    }
    int min_lr = (l < r) ? l : r;
    int min_ud = (u < d) ? u : d;
    if (i != 0) {
      if (min_lr == 0 && min_ud != 0) {
        min_ud = 1;
      }
      if (min_ud == 0 && min_lr != 0) {
        min_lr = 1;
      }
      cout << (2 * min_lr + 2 * min_ud) << endl;
      for (int k = 0; k < min_lr; ++k) {
        cout << 'L';
      }
      for (int k = 0; k < min_ud; ++k) {
        cout << 'U';
      }
      for (int k = 0; k < min_lr; ++k) {
        cout << 'R';
      }
      for (int k = 0; k < min_ud; ++k) {
        cout << 'D';
      }
      cout << endl;
    }
  }
  return 0;
}
