#include <bits/stdc++.h>
using namespace std;
const int LIMIT = 1e5;
int ans[LIMIT];
int n;
int main() {
  cin >> n;
  long long m[n], k[n];
  for (int i = 1; i <= n; i++) {
    cin >> m[i] >> k[i];
  }
  for (int i = 1; i <= n; i++) {
    int steps = 0;
    while (m[i] >= k[i]) {
      steps += (m[i] % k[i]);
      m[i] /= k[i];
      steps++;
    }
    steps += m[i];
    cout << steps << endl;
  }
  return 0;
}
