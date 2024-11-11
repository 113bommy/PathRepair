#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[300007];
int main() {
  int a[10];
  scanf("%d%d%d%d%d", &a[1], &a[2], &a[3], &a[4], &a[5]);
  int k;
  scanf("%d", &k);
  for (auto i = (1); i <= (k); ++i) {
    string s;
    cin >> s;
    int pos = 0;
    if (s == "S") pos = 1;
    if (s == "M") pos = 2;
    if (s == "L") pos = 3;
    if (s == "XL") pos = 4;
    if (s == "XXL") pos = 5;
    for (auto j = (0); j <= (5); ++j) {
      if (pos + j <= 5 && a[pos + j]) {
        pos += j;
        break;
      }
      if (pos - j && a[pos - j]) {
        pos -= j;
        break;
      }
    }
    --a[pos];
    if (pos == 1) printf("S\n");
    if (pos == 2) printf("M\n");
    if (pos == 3) printf("L\n");
    if (pos == 4) printf("XL\n");
    if (pos == 5) printf("XXL\n");
  }
  return 0;
}
