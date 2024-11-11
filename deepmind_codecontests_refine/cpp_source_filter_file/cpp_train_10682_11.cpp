#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, t;
  cin >> n >> k >> t;
  long long res = min(t, k);
  cout << min(res, n + k - 1);
}
