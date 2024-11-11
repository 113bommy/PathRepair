#include <bits/stdc++.h>
const double eps = 1e-8;
const int oo = 0x3f3f3f3f;
using namespace std;
int n, m;
bool read() {
  if (scanf("%d%d%*d%*d", &n, &m) == EOF) return false;
  return true;
}
void process() {
  if (n <= m)
    printf("Second\n");
  else
    printf("First\n");
}
int main() {
  int t = -1;
  while (t-- && read()) {
    process();
  }
  return 0;
}
