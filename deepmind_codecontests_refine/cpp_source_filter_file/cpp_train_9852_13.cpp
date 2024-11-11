#include <bits/stdc++.h>
using namespace std;
const int DIV = 1000000007;
int main(int argc, char* argv[]) {
  FILE* f = stdin;
  int n, m, c;
  fscanf(f, "%d %d %d", &n, &m, &c);
  int l = 0, r = n - 1;
  std::vector<int> k(n);
  for (int ii = 0; ii < m; ii++) {
    if (r < l) break;
    int a;
    fscanf(f, "%d", &a);
    int pos;
    if (a <= c / 2) {
      if (l > 0 && k[0] > a) {
        pos = 0;
      } else if (l == 0 || k[l - 1] <= a) {
        pos = l;
        l++;
      } else {
        int b1, b2;
        b1 = 0;
        b2 = l;
        while (b1 + 1 < b2) {
          int b = (b1 + b2) / 2;
          if (k[b] > a)
            b2 = b;
          else
            b1 = b;
        }
        pos = b2;
      }
    } else {
      if (r < n - 1 && k[n - 1] < a) {
        pos = n - 1;
      } else if (r == n - 1 || k[r] >= a) {
        pos = r;
        r--;
      } else {
        int b1, b2;
        b1 = r;
        b2 = n - 1;
        while (b1 + 1 < b2) {
          int b = (b1 + b2 + 1) / 2;
          if (k[b] < a)
            b1 = b;
          else
            b2 = b;
        }
        pos = b1;
      }
    }
    k[pos] = a;
    printf("%d\n", pos + 1);
    fflush(stdout);
  }
  return 0;
}
