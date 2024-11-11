#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  vector<int> N;
  vector<long long> prefsum, suffsum;
  cin >> n;
  N.clear();
  suffsum.clear();
  suffsum.assign(n + 2, 0);
  prefsum.clear();
  N.assign(n + 1, 0);
  prefsum.assign(n + 1, 0);
  vector<int> T;
  T.assign(n + 1, 0);
  for (int i = 0; i < n; i++) {
    cin >> N[i + 1];
    prefsum[i + 1] = N[i + 1];
    prefsum[i + 1] += prefsum[i];
  }
  suffsum[n] = 0;
  for (int i = n - 1; i > 0; i--) {
    suffsum[i] = N[i];
    suffsum[i] += suffsum[i + 1];
  }
  if (prefsum[n] != 0 && prefsum[n] % 3) {
    cout << 0 << endl;
  } else {
    int nums = 0;
    long long ans = 0;
    for (int i = n; i > 0; i--) {
      if (suffsum[i] == (suffsum[n] / 3)) {
        T[i] = 1;
      }
      T[i] += T[i + 1];
    }
    for (int i = 1; i < n + 1; i++) {
      if (prefsum[i] == (prefsum[n] / 3)) {
        nums++;
        ans += T[i + 2];
      }
    }
    cout << ans << endl;
  }
  return 0;
}
