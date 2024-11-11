#include <bits/stdc++.h>
using namespace std;
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }
const int INF = 1 << 29;
int main() {
  string line;
  getline(cin, line);
  int st = 0;
  for (int ch : line) {
    if (st <= ch) st += 256;
    int cnt = st - ch;
    for (int i = 0; i < (cnt); ++i) {
      printf("X.");
    }
    for (int i = 0; i < (256 - cnt); ++i) {
      printf("..");
    }
    st = ch;
    printf("\nX.");
    for (int i = 0; i < (255); ++i) printf("..");
    printf("\n");
    for (int i = 0; i < (256); ++i) printf("..");
    printf("\n");
  }
  return 0;
}
