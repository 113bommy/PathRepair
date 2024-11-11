#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
int N, K;
int main() {
  string line;
  scanf("%d %d\n", &N, &K);
  getline(cin, line);
  line = '.' + line;
  int i = 1;
  for (int op = (0); op < (K); ++op) {
    while (i < N) {
      if (line[i] == '4' && line[i + 1] == '7') break;
      ++i;
    }
    if (i >= N) break;
    if (i & 1)
      line[i] = line[i + 1] = '4';
    else
      line[i] = line[i + 1] = '7';
    if (i > 1 && line[i - 1] == '4' && (i % 2 == 0)) {
      if ((K - i - 1) % 2 == 1) line[i] = '4';
      line.erase(0, 1);
      printf("%s\n", line.c_str());
      return 0;
    }
    if (i > 2)
      i -= 2;
    else
      i -= 1;
  }
  line.erase(0, 1);
  printf("%s\n", line.c_str());
  return 0;
}
