#include <bits/stdc++.h>
using namespace std;
int main() {
  ifstream in("input.txt");
  ofstream out("output.txt");
  int n, k, t[100], a;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &t[i]);
  if (t[1] > 15) {
    printf("%d\n", 15);
    return 0;
  }
  for (int i = 2; i <= 75; i++) {
    if (t[i] - t[i - 1] > 15) {
      printf("%d\n", t[i - 1] + 15);
      return 0;
    }
    if (t[i] >= 75) break;
  }
  printf("%d\n", 90);
  in.close();
  out.close();
  return 0;
}
