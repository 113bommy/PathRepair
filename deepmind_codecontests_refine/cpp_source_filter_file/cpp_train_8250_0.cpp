#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string arr, brr;
    cin >> arr >> brr;
    if (n == 1) {
      if (arr == brr)
        cout << 0 << endl;
      else
        cout << 1 << " " << 1 << endl;
    } else {
      vector<long long> ans;
      long long j = 0, x, y;
      for (long long i = 0; i < n; i++) {
        if (i % 2 == 0) {
          y = brr[n - 1 - i] - '0';
          x = arr[j] - '0';
          x = (x + i) % 2;
          if (x == y) ans.push_back(1);
          ans.push_back(n - i);
          j++;
        } else {
          y = brr[n - 1 - i] - '0';
          x = arr[j] - '0';
          x = (x + i) % 2;
          if (x == y) ans.push_back(1);
          ans.push_back(n - i);
        }
      }
      cout << ans.size() << " ";
      for (long long i = 0; i < ans.size(); i++) cout << ans[i] << " ";
      cout << endl;
    }
  }
}
