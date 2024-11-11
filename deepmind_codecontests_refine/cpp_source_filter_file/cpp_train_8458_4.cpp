#include <bits/stdc++.h>
using namespace std;
int t;
int a[100];
int main(int argc, char** argv) {
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    map<int, int> mp;
    while (!mp.empty()) mp.clear();
    for (int i = 1; i <= 2 * n; i++) {
      cin >> a[i];
    }
    for (int i = 1; i <= 2 * n; i++) {
      if (mp[a[i]]) continue;
      mp[a[i]]++;
      cout << a[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
