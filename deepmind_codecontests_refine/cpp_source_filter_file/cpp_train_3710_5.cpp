#include <bits/stdc++.h>
using namespace std;
int main() {
  int h1, a1, c1, i;
  int h2, a2;
  scanf("%d%d%d%d%d", &h1, &a1, &c1, &h2, &a2);
  vector<int> v;
  while (true) {
    if (h1 - a2 == 0 && h2 - a1 <= 0) {
      h1 -= a2;
      h2 -= a1;
      v.push_back(1);
      break;
    } else if (h1 - a2 > 0) {
      h2 = h2 - a1;
      h1 = h1 - a2;
      v.push_back(1);
      if (h2 <= 0 || h1 <= 0) {
        break;
      }
    } else {
      h1 += c1;
      h1 -= a2;
      v.push_back(0);
    }
  }
  int n = v.size();
  printf("%d\n", n);
  for (i = 0; i < n; i++) {
    if (v[i] == 0)
      printf("HEAL\n");
    else
      printf("STRIKE\n");
  }
}
