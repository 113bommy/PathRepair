#include <bits/stdc++.h>
using namespace std;
int n, a[3][15];
vector<int> sol;
int main() {
  char sir[15];
  scanf("%s", sir + 1);
  n = strlen(sir + 1);
  int val, p = 1, i, max_val = 1;
  for (i = 1; i <= n; ++i) {
    if (sir[i] == ':') {
      ++p;
      continue;
    }
    if (sir[i] >= '0' && sir[i] <= '9') val = sir[i] - '0';
    if (sir[i] >= 'A' && sir[i] <= 'Z') val = sir[i] - 'A' + 10;
    if (val > max_val) max_val = val;
    a[p][++a[p][0]] = val;
  }
  val = 0;
  int inf = 0, ora1 = -1, ora2 = -1;
  for (int b = max_val + 1;; ++b) {
    int ora = 0;
    int min = 0;
    val = 1;
    for (int i = a[1][0]; i >= 1; --i) {
      ora += a[1][i] * val;
      val *= b;
    }
    val = 1;
    for (int i = a[2][0]; i >= 1; --i) {
      min += a[2][i] * val;
      val *= b;
    }
    if (ora1 == ora || ora2 == min) {
      inf = 1;
      break;
    }
    if (ora >= 0 && ora <= 23 && min >= 0 && min <= 59) {
      sol.push_back(b);
    } else {
      if (ora > 23 || min > 59) break;
    }
    ora1 = ora;
    ora2 = min;
  }
  if (inf) {
    printf("-1\n");
    return 0;
  }
  if (sol.size() == 0)
    printf("0\n");
  else {
    for (i = 0; i < sol.size(); ++i) {
      printf("%d ", sol[i]);
    }
  }
  return 0;
}
