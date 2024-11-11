#include <bits/stdc++.h>
using namespace std;
int a[100010];
int sum[100010];
map<int, int> mp;
int main() {
  int t;
  cin >> t;
  while (t--) {
    mp.clear();
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) a[i + 1] = s[i] - '0' - 1;
    int sum = 0;
    int res = 0;
    for (int i = 1; i <= n; i++) {
      sum += a[i];
      if (sum == 0) res++;
      res += mp[sum]++;
    }
    cout << res << endl;
  }
  return 0;
}
