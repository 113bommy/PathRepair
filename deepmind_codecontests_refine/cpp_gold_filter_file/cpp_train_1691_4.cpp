#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 6;
const long long MOD = 1e9 + 7;
int a[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    int tv = n + 1;
    bool bl = true;
    for (int i = 0; i < (n); ++i) {
      cin >> a[i];
      if (i && a[i] > a[i - 1] + 1) {
        bl = false;
      }
    }
    for (int i = 0; i < (n); ++i) {
      int nw = a[i];
      i++;
      while (i < n && a[i] == a[i - 1] + 1) {
        i++;
      }
      i--;
      if (a[i] != tv - 1) {
        bl = false;
        break;
      }
      tv = nw;
    }
    if (bl)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}
