#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  long long n, p;
  cin >> n >> p;
  for (long long i = 1; i < 1e6; i++) {
    long long curr = n - i * p;
    if (curr < i) continue;
    if (__builtin_popcountll(curr) <= i) {
      cout << i << "\n";
      return 0;
    }
  }
  cout << "-1\n";
}
