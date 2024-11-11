#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int D[n];
  map<int, int> M;
  for (int i = 0; i < n; i++) {
    cin >> D[i];
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 31; j++) {
      int x = 1 << j;
      ans = ans + M[x - D[i]];
    }
    M[D[i]]++;
  }
  cout << ans;
  return 0;
}
