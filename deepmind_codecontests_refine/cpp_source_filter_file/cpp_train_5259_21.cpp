#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 1000;
int a[maxN], n, s = 1, q, t;
map<int, int> mp;
int main() {
  cin >> n;
  for (int i = (1); i <= (n); i++) {
    cin >> a[i];
    mp[a[i]] = i;
  }
  for (int i = (1); i <= (n); i++) {
    if (mp[i] > t)
      q++;
    else {
      s = max(s, q);
      q = 0;
    }
    t = mp[i];
  }
  s = max(s, q);
  cout << n - s;
  return 0;
}
