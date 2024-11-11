#include <bits/stdc++.h>
using namespace std;
long long n, a[100010], s;
vector<long long> ans;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s += a[i];
  }
  for (int i = 1; i <= n; i++) {
    if ((s - a[i]) % (n - 1) == 0 && (s - a[i]) / (n - 1) == a[i]) {
      ans.push_back(i);
    }
  }
  cout << ans.size() << "\n";
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
}
