#include <bits/stdc++.h>
using namespace std;
mt19937_64 rang(
    chrono::high_resolution_clock::now().time_since_epoch().count());
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long tc = 1, i, j, k;
  cin >> tc;
  while (tc--) {
    long long n;
    cin >> n;
    vector<long long> v(n);
    map<long long, long long> mp;
    for (long long i = 0; i < n; i++) {
      cin >> v[i];
      mp[v[i]]++;
    }
    bool flag = false;
    for (i = 2; i <= 2048; i = i * 2) {
      if (mp[2048]) {
        flag = true;
        break;
      }
      while (mp[i] >= 2) {
        if (mp[2048]) {
          flag = true;
          break;
        }
        mp[2 * i]++;
        mp[i] -= 2;
        if (mp[2048]) {
          flag = true;
          break;
        }
      }
      if (mp[2048]) {
        flag = true;
        break;
      }
    }
    if (flag)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
