#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:134217728")
const long long MOD = 1000000007;
const int INF = 1000000000;
const int MAXN = 200005;
const double EPS = 1e-6;
const int HASH_POW = 7;
const double PI = acos(-1.0);
using namespace std;
void my_return(int code) { exit(code); }
int main() {
  mt19937 mt_rand(time(NULL));
  int x1, y1, x2, y2;
  scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
  if (x1 + y1 <= max(x2, y2))
    printf("Polycarp\n");
  else if (x1 <= x2 && y1 <= y2)
    printf("Polycarp\n");
  else
    printf("Vasiliy\n");
  my_return(0);
}
