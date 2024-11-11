#include <bits/stdc++.h>
using namespace std;
int main() {
  map<int, int> m;
  int n;
  cin >> n;
  int a[200001];
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    m[x]++;
  }
  int mi, mx = 300000;
  for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
    if (it->second < mx) {
      mx = it->second;
      mi = it->first;
    }
  }
  cout << mi;
  return 0;
}
