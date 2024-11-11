#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t = 1;
  while (t--) {
    long long int n;
    cin >> n;
    vector<long long int> v(n);
    for (long long int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    int left = (n) / 2 - 1;
    int right = n - 1;
    long long int ans = 0;
    while (left >= 0) {
      if (v[right] >= 2 * v[left]) {
        ans++;
        right--;
      }
      left--;
    }
    cout << n - (2 * ans) + ans << endl;
  }
}
