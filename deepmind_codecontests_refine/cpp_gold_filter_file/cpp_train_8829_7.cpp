#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  rep(i, n) a[i] -= i + 1;
  sort(a.begin(), a.end());
  int c = n/2;
  ll ans = 0;
  rep(i,n) ans += abs(a[i] - a[c]);
  cout << ans << endl;
}
