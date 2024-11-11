#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  double ans;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    ans += arr[i];
  }
  ans = ans / n;
  cout << ans;
}
