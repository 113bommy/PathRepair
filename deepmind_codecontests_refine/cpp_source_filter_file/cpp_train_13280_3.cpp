#include <bits/stdc++.h>
using namespace std;
const int mxN = 1e7;
int N, K;
long long v[10000005], v2[10000005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> K;
  for (int i = 1, x; i <= N; i++) {
    cin >> x;
    v[x]++;
    v2[x]++;
  }
  for (int i = 60; i >= 1; i--) {
    v[i] += v[i + 1];
    if (2 * i <= 10000000) {
      v[i] += v2[2 * i];
      v2[i] += 2 * v2[2 * i];
    }
    if (2 * i - 1 <= 10000000) {
      v2[i] += v2[2 * i - 1];
      v2[i - 1] += v2[2 * i - 1];
      v[i - 1] += v2[2 * i - 1];
    }
    if (v[i] >= K) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
