#include <bits/stdc++.h>
using namespace std;
vector<bool> used;
vector<bool> prime;
vector<int> ans;
int main(void) {
  int n;
  cin >> n;
  prime.resize(n + 1);
  used.resize(n + 2);
  for (int i = 0; i <= n; ++i) prime[i] = true;
  for (long long i = 2; i <= n; ++i) {
    if (prime[i]) {
      for (long long j = i * i; j <= n; j += i) {
        prime[j] = false;
      }
    }
  }
  for (int i = n; i >= 2; --i) {
    int cnt = 0;
    if (true) {
      for (int j = i; j <= n; j += i) {
        if (!used[j]) cnt++;
      }
      if (cnt == 1) continue;
      for (int j = i; j <= n; j += i) {
        if (!used[j]) {
          if ((cnt % 2 == 1) && (j == 2 * i)) {
            continue;
          }
          used[j] = true;
          ans.push_back(j);
        }
      }
    }
  }
  cout << ans.size() / 2 << endl;
  for (int i = 0; i < ((int)ans.size()); ++i) {
    cout << ans[i] << " ";
    if (i % 2) cout << "\n";
  }
}
