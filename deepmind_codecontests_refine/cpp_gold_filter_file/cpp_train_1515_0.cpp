#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, sum = 0, mn;
  map<int, int> mp;
  for (int i = 0; i < 5; i++) {
    cin >> t;
    sum += t;
    mp[t]++;
  }
  mn = sum;
  for (int i = 1; i <= 100; i++) {
    if (mp[i] == 2)
      mn = min(mn, sum - i * 2);
    else if (mp[i] > 2)
      mn = min(mn, sum - i * 3);
  }
  cout << mn << endl;
}
