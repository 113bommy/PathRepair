#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    long long int ans = 0;
    vector<long long int> ind;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '1') ind.push_back(i + 1);
    }
    if (ind.size() == 0) {
      long long int u = (n / (k + 1));
      if (n % (k + 1) != 0) u += 1;
      cout << u << "\n";
      continue;
    }
    long long int start = -1;
    long long int end = -1;
    for (int i = 0; i < ind.size() - 1; i++) {
      start = ind[i] + k + 1;
      end = ind[i + 1] - k - 1;
      if (start <= end) {
        long long int u = end - start + 1;
        ans += (u / (k + 1));
        if (u % (k + 1) != 0) ans += 1;
      }
    }
    start = 1;
    end = ind[0] - k - 1;
    if (start <= end) {
      long long int u = end - start + 1;
      ans += (u / (k + 1));
      if (u % (k + 1) != 0) ans += 1;
    }
    start = ind[ind.size() - 1] + k + 1;
    end = n;
    if (start <= end) {
      long long int u = end - start + 1;
      ans += (u / (k + 1));
      if (u % (k + 1) != 0) ans += 1;
    }
    cout << ans << "\n";
  }
  return 0;
}
