#include <bits/stdc++.h>
using namespace std;
inline int MAX(int a, int b) { return (a > b) ? a : b; }
inline int MIN(int a, int b) { return (a < b) ? a : b; }
inline int ABS(int a) { return (a > 0) ? a : -a; }
int n, t;
long long tab[100100];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  long long int p1 = 27;
  long long int p2 = 7;
  long long int ans1 = 1, ans2 = 1;
  for (int i = 0; (1 << i) <= n; ++i) {
    if ((1 << i) & n) {
      ans1 = (ans1 * p1) % 1000000007;
      ans2 = (ans2 * p2) % 1000000007;
    }
    p1 = (p1 * p1) % 1000000007;
    p2 = (p2 * p2) % 1000000007;
  }
  cout << (ans1 - ans2 + 1000000007) % 1000000007 << endl;
  return 0;
}
