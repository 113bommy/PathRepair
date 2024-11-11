#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int p = n;
  map<int, int> mp;
  set<int> st;
  set<int>::iterator it;
  vector<int> v;
  while (n--) {
    int j;
    cin >> j;
    for (int k = 0; k < j; k++) {
      int x;
      cin >> x;
      mp[x]++;
    }
  }
  int s = 1;
  while (s != 100) {
    if (mp[s] == p) cout << s << ' ';
    s++;
  }
}
