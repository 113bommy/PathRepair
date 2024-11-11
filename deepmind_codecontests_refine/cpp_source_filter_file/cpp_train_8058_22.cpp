#include <bits/stdc++.h>
using namespace std;
map<long long, long long> mp;
int main() {
  long long n, m, sz[100001], a[100001], x;
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    mp[a[i]]++;
  }
  long long lot = mp.size();
  sz[1] = lot;
  for (long long i = 2; i <= n; i++) {
    mp[a[i]]--;
    if (mp[a[i]] == 0) {
      sz[i] = lot - 1;
      lot--;
    } else {
      sz[i] = lot;
    }
  }
  while (m--) {
    cin >> x;
    cout << sz[x] << endl;
  }
  return 0;
}
