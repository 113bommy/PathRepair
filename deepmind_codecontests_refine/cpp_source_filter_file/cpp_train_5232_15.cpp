#include <bits/stdc++.h>
using namespace std;
void comp() {
  long long i, j, k, n, m;
  cin >> n;
  vector<long long> v1, v2;
  long long mini = 1e18, maxi = 0;
  for (i = 0; i < n; i++) {
    cin >> j;
    v1.push_back(j);
    v2.push_back(j);
    mini = min(mini, j);
    maxi = max(maxi, j);
  }
  sort(v2.begin(), v2.end());
  long long ans = 0, ans1 = 0, ind;
  for (i = 0; i < n; i++) {
    long long temp = v1[i];
    ans1 = 0;
    for (j = 0; j < v2.size(); j++) {
      if (v2[j] == temp) {
        ind = j;
        break;
      }
    }
    if (ind < n - 1) ind++;
    for (j = i + 1; j < n; j++) {
      if (v1[j] == v2[ind]) {
        ans1++;
        if (ind < n - 1) ind++;
      }
    }
    ans = max(ans, ans1);
  }
  cout << n - ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  long long i = 0, t;
  t = 1;
  cin >> t;
  while (t--) {
    comp();
  }
  return 0;
}
