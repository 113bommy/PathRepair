#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7;
long long int num[50000];
long long int arr[50000];
long long int findMex(long long int n) {
  for (long long int i = 0; i <= n; i++) num[i] = 0;
  for (long long int i = 0; i < n; i++) num[arr[i]] += 1;
  for (long long int i = 0; i <= n; i++) {
    if (num[i] == 0) {
      return i;
    }
  }
  return n;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    memset(num, 0, sizeof(num));
    for (long long int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    vector<long long int> ans;
    long long int count = 0;
    long long int x = n;
    for (long long int i = 0; i < 2 * n; i++) {
      long long int mex = findMex(n);
      if (mex == x) {
        ans.push_back(mex - 1);
        arr[x - 1] = mex;
        x -= 1;
        if (x < 0) break;
      } else {
        ans.push_back(mex);
        arr[mex] = mex;
      }
    }
    cout << ans.size() << "\n";
    for (auto it : ans) cout << it + 1 << " ";
    cout << "\n";
  }
  return 0;
}
