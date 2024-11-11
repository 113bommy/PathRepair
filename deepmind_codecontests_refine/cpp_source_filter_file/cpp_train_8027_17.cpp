#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n, k;
  cin >> n >> k;
  long long int sum = 0;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  if (sum % k != 0) {
    cout << "NO";
    return 0;
  } else {
    sum = sum / k;
    long long int rsum = 0;
    int cnt = 1;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      if (rsum + a[i] == sum) {
        ans.push_back(cnt);
        cnt = 1;
        rsum = 0;
      } else if (rsum + a[i] < sum) {
        rsum += a[i];
        cnt++;
      } else {
        cout << "NO";
        return 0;
      }
    }
    if (ans.size() == k) {
      cout << "YES" << endl;
      for (int i = 0; i < k; i++) cout << ans[i] << " ";
    } else {
      cout << "NO";
    }
  }
  return 0;
}
