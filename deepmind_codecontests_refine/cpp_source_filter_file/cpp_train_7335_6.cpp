#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void mainHelper() {
  long long n;
  cin >> n;
  vector<ll> a, b;
  bool last = true;
  for (long long i = 0; i < n; i++) {
    ll x;
    cin >> x;
    if (x < 0)
      b.push_back(-1 * x), last = false;
    else
      a.push_back(x), last = true;
  }
  ll sumA = accumulate(a.begin(), a.end(), 0);
  ll sumB = accumulate(b.begin(), b.end(), 0);
  if (sumA > sumB)
    cout << "first\n";
  else if (sumB > sumA)
    cout << "second\n";
  else {
    bool winA = false, winB = false;
    for (long long i = 0; i < min((long long)a.size(), (long long)b.size());
         i++) {
      if (a[i] > b[i]) {
        winA = true;
        break;
      }
      if (b[i] > a[i]) {
        winB = true;
        break;
      }
    }
    if (winA)
      cout << "first\n";
    else if (winB)
      cout << "second\n";
    else if (last)
      cout << "first\n";
    else
      cout << "second\n";
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  mainHelper();
  return 0;
}
