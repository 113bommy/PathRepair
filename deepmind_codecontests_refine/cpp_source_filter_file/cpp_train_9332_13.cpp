#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  vector<long long> v1(n);
  vector<long long> v2(m);
  for (long long i = 0; i < n; i++) {
    cin >> v1[i];
  }
  for (long long i = 0; i < m; i++) {
    cin >> v2[i];
  }
  vector<long long> x;
  for (long long i = 0; i < n; i++) {
    long long M = -1000000000000;
    for (long long j = 0; j < m; j++) {
      if (M < (v1[i] * v2[j])) {
        M = v1[i] * v2[j];
      }
    }
    x.push_back(M);
  }
  sort(x.begin(), x.end());
  cout << x[x.size() - 2];
  return 0;
}
