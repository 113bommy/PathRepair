#include <bits/stdc++.h>
using namespace std;
void gogeta() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
char toggle(char ch) {
  if (ch == '0')
    return '1';
  else
    return '0';
}
int32_t main() {
  gogeta();
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    vector<long long> ans;
    bool tog = false;
    long long f = 0, l = n - 1;
    for (long long i = n - 1; i >= 0; i--) {
      if (tog) {
        if (b[i] == a[f]) {
          ans.push_back(1);
          ans.push_back(i + 1);
        } else {
          ans.push_back(1);
        }
        f++;
      } else {
        if (b[i] == toggle(a[l])) {
          ans.push_back(1);
          ans.push_back(i + 1);
        } else {
          ans.push_back(1);
        }
        l--;
      }
      tog = !tog;
    }
    cout << ans.size() << " ";
    for (auto x : ans) cout << x << " ";
    cout << endl;
  }
}
