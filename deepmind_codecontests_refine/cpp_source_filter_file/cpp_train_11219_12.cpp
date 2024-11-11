#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  multimap<int, int> mp;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    mp.insert(make_pair(v[i], i));
  }
  if (n == 1) {
    cout << -1;
    return 0;
  }
  if (n == 2) {
    if (v[0] == v[1]) {
      cout << -1;
      return 0;
    } else {
      cout << 1 << endl;
      cout << 1;
      return 0;
    }
  }
  cout << n - 1 << endl;
  multimap<int, int>::iterator it;
  it = mp.begin();
  it++;
  for (it; it != mp.end(); it++) {
    cout << it->second << " ";
  }
  return 0;
}
