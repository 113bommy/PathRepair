#include <bits/stdc++.h>
using namespace std;
long long dx[] = {-1, 1, 0, 0};
long long dy[] = {0, 0, -1, 1};
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long k = 0;
    cin >> k;
    long long i = 1;
    string s;
    while (s.length() < k) {
      k -= s.length();
      s += to_string(i++);
    }
    cout << s[k - 1] << "\n";
  }
}
