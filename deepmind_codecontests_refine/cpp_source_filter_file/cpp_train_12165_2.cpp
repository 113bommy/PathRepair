#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, K;
  cin >> N >> K;
  vector<pair<int, int>> AB(N);
  for (auto& ab : AB) cin >> ab.first >> ab.second;
  sort(AB.begin(), AB.end());
  for (auto ab : AB) {
    if (K <= ab.second) {
      cout << ab.first << endl;
      return 0;
    }
    K -= ab.second;
  }
}
