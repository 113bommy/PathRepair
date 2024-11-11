#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, x;
  int maxim = 0, maxi;
  int tmp;
  map<int, int> mp;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> x;
    tmp = mp[x]++;
    if (tmp > maxim) {
      maxim = tmp;
      maxi = x;
    }
  }
  cout << maxi << endl;
  return 0;
}
