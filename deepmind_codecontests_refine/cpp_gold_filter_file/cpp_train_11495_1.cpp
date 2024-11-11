#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  map<int, int> mp;
  bool flag = true;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x == 25) {
      mp[x]++;
      continue;
    }
    int dif = x - 25;
    if (dif == 75) {
      if (mp[50] && mp[25]) {
        mp[50]--;
        mp[25]--;
        mp[100]++;
      } else if (mp[25] >= 3) {
        mp[25] -= 3;
        mp[100]++;
      } else
        flag = false;
    } else if (dif == 25) {
      if (mp[25]) {
        mp[25]--;
        mp[50]++;
      } else
        flag = false;
    }
  }
  if (flag == false)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
  return 0;
}
