#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, c;
  cin >> n >> c;
  vector<long long int> a(n + 1), freqC(n + 1, 0), freq(5e5 + 1, 0),
      mini(5e5 + 1, 0), minIndex(5e5 + 1, -1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] == c) {
      freqC[i]++;
    }
    freqC[i] += freqC[i - 1];
  }
  long long int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (freq[a[i]] == 0) {
      minIndex[a[i]] = i;
    }
    mini[a[i]] =
        min(mini[a[i]], freq[a[i]] - freqC[i] + freqC[minIndex[a[i]] - 1]);
    freq[a[i]]++;
    ans = max(ans,
              freq[a[i]] - freqC[i] + freqC[minIndex[a[i]] - 1] - mini[a[i]]);
    mini[a[i]] =
        min(mini[a[i]], freq[a[i]] - freqC[i] + freqC[minIndex[a[i]] - 1]);
  }
  ans += freqC[n];
  cout << ans;
  return 0;
}
