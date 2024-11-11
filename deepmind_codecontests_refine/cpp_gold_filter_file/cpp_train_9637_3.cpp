#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> vt;
  int a, b;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 4; j++) printf("%d", i);
    printf("\n");
    fflush(stdout);
    scanf("%d %d", &a, &b);
    if (a == 1) vt.push_back(i);
  }
  do {
    for (int i = 0; i < vt.size(); i++) printf("%d", vt[i]);
    printf("\n");
    fflush(stdout);
    scanf("%d %d", &a, &b);
    if (a == 4) return 0;
  } while (next_permutation(vt.begin(), vt.end()));
  return 0;
}
