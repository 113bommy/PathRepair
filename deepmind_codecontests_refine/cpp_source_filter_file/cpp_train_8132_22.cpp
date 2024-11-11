#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable : 4996)
const int mod = 1e9;
const int IT_MAX = 1 << 18;
const int MAXN = 1e5 + 5;
int n;
long long k, x;
int main() {
  cin >> n;
  while (n--) {
    scanf("%lld %lld", &k, &x);
    printf("%d\n", 9 * (k - 1) + x);
  }
}
