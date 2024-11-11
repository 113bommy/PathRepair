#include <bits/stdc++.h>
using namespace std;
const long long N = 2e6 + 3e4;
long long first, so, n;
int main() {
  cin >> n;
  n--;
  for (long long i = (long long)0; i <= (long long)n; i++) {
    first = 1 << i;
    if (first >= n) break;
    so += ((n - first) / (first * 2) + 1) * first;
  }
  cout << so << " ";
}
