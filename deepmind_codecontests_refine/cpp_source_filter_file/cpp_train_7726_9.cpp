#include <bits/stdc++.h>
using namespace std;
long long dx[] = {0, -1, 0, 1};
long long dy[] = {1, 0, -1, 0};
const long long mod = 1e9 + 7;
long long i, j;
long long add(long long a, long long b) {
  return ((a % mod) + (b % mod) + mod) % mod;
}
long long mul(long long a, long long b) {
  return ((a % mod) * (b % mod) + mod) % mod;
}
void pause(long long id) {
  cout << "Waiting " << id << endl;
  cin >> id;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    long long arr[m];
    long long i, j;
    unordered_map<long long, long long> mp;
    for (i = 0; i < m; i++) {
      cin >> arr[i];
      mp[arr[i]]++;
    }
    long long ans = 0;
    bool flag = true;
    for (i = 0; i < 64; i++) {
      long long temp;
      temp = (1ll << i);
      if ((n & temp) == temp) {
        if (mp[temp] > 0) {
          mp[temp]--;
          mp[temp * 2] += (mp[temp]) / 2;
        } else {
          long long t = 0;
          j = i;
          while (j < 35 && mp[(1ll << j)] == 0) {
            j++;
            t++;
          }
          if (j == 35) {
            flag = false;
          } else {
            mp[(1ll << j)]--;
            j--;
            while (j >= i) {
              mp[(1ll << j)]++;
              j--;
            }
          }
          ans += t;
        }
      } else {
        mp[temp * 2] += (mp[temp]) / 2;
      }
    }
    if (flag) {
      cout << ans << endl;
    } else {
      cout << -1 << endl;
    }
  }
  return 0;
}
