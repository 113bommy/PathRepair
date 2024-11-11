#include <bits/stdc++.h>
using namespace std;
const long long SIZE = 1e6, MOD = 1e9 + 7;
long long q;
vector<long long> vec;
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  ;
  long long n, k;
  cin >> n >> k;
  int l = 0, r = n - 1;
  int ans1 = 0;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    cout << "1 " << mid + 1 << " " << mid + 2 << endl;
    fflush(stdout);
    string q;
    cin >> q;
    if (q == "TAK") {
      r = mid;
    } else {
      l = mid;
    }
  }
  ans1 = r;
  l = -1, r = ans1;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    cout << "1 " << mid + 1 << " " << mid + 2 << endl;
    fflush(stdout);
    string q;
    cin >> q;
    if (q == "TAK") {
      r = mid;
    } else {
      l = mid;
    }
  }
  if (r != ans1) {
    cout << "2 " << ans1 + 1 << " " << r + 1 << endl;
    return 0;
  }
  l = ans1, r = n - 1;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    cout << "1 " << mid + 2 << " " << mid + 1 << endl;
    fflush(stdout);
    string q;
    cin >> q;
    if (q == "TAK") {
      l = mid;
    } else {
      r = mid;
    }
  }
  cout << "2 " << ans1 + 1 << " " << r + 1 << endl;
  return 0;
}
