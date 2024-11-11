#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n;
  cin >> n;
  set<long long int> a;
  for (long long int i = 1; i * (i + 1) <= n * n; ++i) {
    for (long long int j = i + 1; i * i + j * j <= n * n; ++j) {
      long long int k = sqrt(i * i + j * j);
      if (k * k == i * i + j * j) a.insert(i * i + j * j);
    }
  }
  cout << a.size();
  return 0;
}
