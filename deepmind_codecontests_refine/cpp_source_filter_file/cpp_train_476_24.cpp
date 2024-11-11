#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int TESTS = 1;
  while (TESTS--) {
    long long n, v1, v2, t1, t2;
    cin >> n >> v1 >> v2 >> t1 >> t2;
    long long p = n * (v1) + n / 2 * t1;
    long long q = n * (v2) + n / 2 * t2;
    if (p > q)
      cout << "Second";
    else if (q > p)
      cout << "First";
    else
      cout << "Friendship";
  }
  return 0;
}
