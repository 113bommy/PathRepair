#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  map<int, int> mp, leafs;
  int n, num;
  cin >> n;
  mp[1] = 0;
  leafs[1] = 0;
  for (int i = 2; i <= n; i++) {
    cin >> num;
    mp[num]++;
    if (leafs[num]) {
      mp[leafs[num]]--;
      leafs[num] = 0;
    }
    leafs[i] = num;
  }
  map<int, int>::iterator it;
  for (it = mp.begin(); it != mp.end(); it++) {
    if (it->second < 3) {
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";
  return 0;
}
