#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int _inf = 0xc0c0c0c0;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const long long _INF = 0xc0c0c0c0c0c0c0c0;
const long long mod = (int)1e9 + 7;
const int N = 1e5 + 100;
int n;
int main() {
  scanf("%d", &n);
  int m = sqrt(n);
  if (m * m == n) {
    printf("%d", m * 2);
  } else if (m * m + 1 == n) {
    printf("%d", m * 2 + 1);
  } else
    printf("%d", m * 2 + 2);
  return 0;
}
