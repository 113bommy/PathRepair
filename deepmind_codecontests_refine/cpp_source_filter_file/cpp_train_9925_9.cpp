#include <bits/stdc++.h>
#pragma comment(linker, "/stack:67108864")
using namespace std;
const long double EPS = 1e-9;
const long double PI = 3.1415926535897932384626433832795;
const long long INF = 1000 * 1000 * 1000;
int main() {
  ifstream ifile("input.txt");
  if (ifile) {
    freopen("input.txt", "rt", stdin);
  }
  if (ifile) {
    freopen("output.txt", "wt", stdout);
  }
  int n, m, x1, x2, y1, y2;
  while (cin >> n >> m >> x1 >> y1 >> x2 >> y2) {
    int a = abs(x1 - x2);
    int b = abs(y1 - y2);
    if (a > b) swap(a, b);
    if (a == 0) {
      if (b >= 5) {
        printf("Second\n");
      } else {
        printf("First\n");
      }
      continue;
    }
    if (a == 1) {
      if (b >= 5) {
        printf("Second\n");
      } else {
        printf("First\n");
      }
      continue;
    }
    if (a == 2) {
      if (b >= 4) {
        printf("Second\n");
      } else {
        printf("First\n");
      }
      continue;
    }
    if (a == 3) {
      if (b >= 3) {
        printf("Second\n");
      } else {
        printf("First\n");
      }
      continue;
    }
    printf("Second\n");
  }
  return 0;
}
