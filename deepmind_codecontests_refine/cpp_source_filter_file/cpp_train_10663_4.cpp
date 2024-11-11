#include <bits/stdc++.h>
using namespace std;
int bit[1000001];
int main() {
  int n, tmp;
  int s = 1000000;
  int pairs = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &tmp);
    bit[tmp] = 1;
    if (bit[s - tmp + 1]) pairs++;
  }
  vector<int> fin;
  for (int i = 1; i <= (s - i + 1); i++) {
    if (bit[i] && bit[s - i + 1])
      ;
    else if (bit[i] && !bit[s - i + 1]) {
      fin.push_back(s - i + 1);
    } else if (!bit[i] && bit[s - i + 1]) {
      fin.push_back(i);
    } else {
      if (pairs > 0) {
        fin.push_back(i);
        fin.push_back(s - i - 1);
        pairs--;
      }
    }
  }
  printf("%d\n", fin.size());
  for (int i = 0; i < fin.size(); i++) {
    printf("%d ", fin[i]);
  }
  printf("\n");
  return 0;
}
