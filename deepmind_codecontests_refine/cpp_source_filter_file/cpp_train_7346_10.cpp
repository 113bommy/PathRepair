#include <bits/stdc++.h>
using namespace std;
int main() {
  {
    long long int n, sum = 0, f = 0, cur = 1, cnt = 0, ans = 0;
    cin >> n;
    map<int, int> mp;
    while (n) {
      if (mp[n - cur] == 0 && cur != n / 2) {
        mp[cur]++;
        n -= cur;
        cur++;
      } else {
        mp[n]++;
        n = 0;
      }
    }
    vector<int> a;
    for (auto x : mp) {
      if (x.second > 0) {
        cnt++;
        a.push_back(x.first);
      }
    }
    cout << cnt << endl;
    for (int i = 0; i < a.size(); i++) {
      cout << a[i] << " ";
    }
    cout << endl;
  }
}
