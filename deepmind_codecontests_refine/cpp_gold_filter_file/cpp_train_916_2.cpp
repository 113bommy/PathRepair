#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n; cin >> n;
  map<ll, int> cnt;
  ll sum = 0, res = 0;
  cnt[0] = 1;
  while (n--) {
    int x; cin >> x;
    res += cnt[sum+=x]++;
  }
  cout << res << endl;
}
