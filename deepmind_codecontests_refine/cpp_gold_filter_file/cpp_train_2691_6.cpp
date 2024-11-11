#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;

int main(){ 
  int n, a, b;
  cin >> n >> a >> b;
  vector<int> h(n);
  rep(i,n) cin >> h[i];

  auto ok = [&](ll m) {
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
      if (h[i] > b * m) {
        cnt += ((h[i] - b * m + (a-b-1))/(a-b));
      }
    }
    return cnt > m;
  };

  ll l = 0, r = 1e9;
  while (r - l > 1) {
    int m = (r + l) / 2;
    if (ok(m)) l = m;
    else r = m;
  }
  cout << r << endl;
  return 0;
} 