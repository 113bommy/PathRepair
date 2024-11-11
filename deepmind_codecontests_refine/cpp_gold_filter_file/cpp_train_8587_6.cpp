#include <bits/stdc++.h>
using namespace std;
void deba(int* a, int n) {
  cerr << "| ";
  for (int i = 0; i < (n); i++) cerr << a[i] << " ";
  cerr << "|" << endl;
}
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }
const int INF = 1 << 30;
int main() {
  printf("2000\n");
  for (int i = 0; i < (1000); i++) printf("%d %d %d %d\n", i + 1, 1, i + 1, 2);
  for (int i = (1000); i >= (1); i--) printf("%d %d %d %d\n", i, 1, i, 2);
  return 0;
}
