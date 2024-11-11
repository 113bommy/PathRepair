#include <bits/stdc++.h>
using namespace std;
vector<int> X3, Y3;
map<int, int> m;
char X[111];
int main() {
  int n;
  scanf("%d", &n);
  while (n--) {
    for (int i = 1; i <= 12; i++) scanf(" %c", &X[i]);
    m.clear();
    int guess[] = {1, 2, 4, 3, 6, 12};
    for (int k = 0; k < 6; k++) {
      int cnt = 0, cnt2 = 0;
      int i = guess[k];
      int j = 12 / i;
      for (int l = 1; l <= 12; l++) {
        if (X[l] == 'X') {
          cnt++;
          for (int l2 = l; l2 <= 12; l2 += j)
            if (X[l2] == 'X')
              cnt2++;
            else
              cnt2 = 0;
        }
        if (cnt + cnt2 >= i && m[i] == 0) m[i] = j;
        cnt = cnt2 = 0;
      }
    }
    printf("%d ", m.size());
    for (int i = 0; i <= 12; i++)
      if (m[i] != 0) printf("%dx%d ", i, m[i]);
    printf("\n");
  }
}
