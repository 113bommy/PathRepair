#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e5 + 7;
long long n, c, ans[5050], a[5050];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    vector<int> mx(n + 1);
    mx[a[i]]++;
    ans[a[i]]++;
    c = a[i];
    for (int j = i + 1; j <= n; j++) {
      mx[a[j]]++;
      if (mx[a[j]] > mx[c])
        c = a[j];
      else if (mx[a[j]] == mx[c])
        c = min(a[j], c);
      ans[c]++;
    }
  }
  for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
  return 0;
}
