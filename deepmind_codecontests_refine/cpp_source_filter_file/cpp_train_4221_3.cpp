#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;
const int MAXM = 200000;
const int INF = 1000000010;
const long long int MOD = 1000000007;
const long long int P = 31;
const double EPS = 1e-6;
int A;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  scanf("%d", &A);
  int n = 0;
  while (A) {
    if (A % 10 == 1) n++;
    A /= 10;
  }
  printf("%d", n);
  return 0;
}
