#include <bits/stdc++.h>
#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:36777216")
using namespace std;
const long long int inf = 100000000000000000LL;
int calc(int t1, int t2, int k, int a, int b) {
  int q = t1 * a * (100 - k) + t2 * b * 100;
  int w = t1 * b * (100 - k) + t2 * a * 100;
  return max(q, w);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << fixed << setprecision(15);
  srand(16);
  int start = clock();
  long long int k, b, n, t;
  cin >> k >> b >> n >> t;
  long long int c = 1;
  long long int ans = 0;
  while (c <= t) {
    c *= k;
    c += b;
    ans++;
  }
  --ans;
  cout << max(0LL, n - ans);
  return 0;
}
