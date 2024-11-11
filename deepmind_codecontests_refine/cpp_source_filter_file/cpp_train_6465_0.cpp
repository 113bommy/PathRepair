#include <bits/stdc++.h>
using namespace std;
long long n, sm;
long long mx;
long long ar[105];
long long x[105];
vector<long long> ans;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  ar[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> ar[i];
    x[i - 1] = ar[i] - ar[i - 1];
  }
  for (int i = 1; i <= n; i++) {
    bool ok = true;
    for (int j = 1; j <= n; j++) {
      if (x[j - 1] != x[(j - 1) % i]) ok = false;
    }
    if (ok) ans.push_back(i);
  }
  cout << ans.size() << "\n";
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << (i == (ans.size() - 1) ? "\n" : " ");
  }
}
