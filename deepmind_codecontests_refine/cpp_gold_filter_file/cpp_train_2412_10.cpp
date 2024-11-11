#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 3;
void test() {
  long long r;
  cin >> r;
  if (r % 2 == 0 || r - 3 <= 0)
    printf("NO");
  else
    printf("1 %lld", (r - 3) / 2);
}
int main() { test(); }
