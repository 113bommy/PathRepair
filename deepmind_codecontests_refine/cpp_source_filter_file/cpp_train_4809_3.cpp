#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    set<long long> s;
    vector<long long> ans;
    long long flag = 0;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      s.insert(i + 1);
    }
    for (long long i = 0; i < n; i++) {
      if (s.find(a[i]) != s.end()) {
        ans.push_back(a[i]);
        s.erase(a[i]);
      } else {
        long long temp = *s.begin();
        if (temp > a[i]) {
          flag = 1;
          break;
        }
        ans.push_back(temp);
        s.erase(a[i]);
      }
    }
    if (flag)
      cout << "-1"
           << "\n";
    else {
      for (long long i = 0; i < n; i++) cout << ans[i] << " ";
      cout << "\n";
    }
  }
}
