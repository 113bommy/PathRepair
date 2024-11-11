#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, a, b;
  map<int, int> mp;
  cin >> n >> k;
  for (int i = 0; i <= k; i++) {
    cout << "?";
    for (int j = 0; j < k; j++) {
      cout << " " << (i + j) % (k + 1) + 1;
    }
    cout << endl;
    cin >> a >> b;
    mp[b]++;
  }
  cout << "! " << mp.rbegin()->second << endl;
  return 0;
}
