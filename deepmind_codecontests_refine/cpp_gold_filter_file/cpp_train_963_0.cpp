#include <bits/stdc++.h>
const double eps = 1e-7, PI = 3.1415926;
const int N = 2e5 + 10;
using namespace std;
int n, q, m, k, x, y, a[N], mx = -1, mn = 1e9, sum;
char c[N];
string s, s1, s2;
map<int, int> mp;
vector<int> vec;
int main() {
  cin >> q;
  while (q--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      mp[a[i]]++;
    }
    int mx1 = 0, mx2 = 0;
    x = 0;
    for (int i = 0; i <= 101; i++) {
      if (mp[i] >= 2 && x == 0)
        mx1 = i + 1, mx2 = i + 1;
      else if (mp[i] == 1 || (mp[i] >= 2 && x == 1))
        mx2 = i + 1, x = 1;
      else {
        break;
      }
    }
    cout << mx1 + mx2 << endl;
    mp.clear();
  }
  return 0;
}
