#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  rep(i, n) cin >> A[i];

  rep(i, n) A[i] -= i + 1;
  sort(A.begin(), A.end());
  int c = n/2;
  ll ans = 0;
  rep(i,n) ans += abs(a[i] - a[c]);
  cout << ans << endl;
}
