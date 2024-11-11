#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, c, k;
  cin >> n >> c >> k;
  vector<int> t(n);
  for (int i = 0; i < n; i++) {
    cin >> t.at(i);
  }
  sort(t.begin(), t.end());
  int bus = 0;
  for (int i = 0; i < n;) {
    ++bus;
    int starti = i;
    while (i < n && t.at(i) - t.at(starti) <= k && i - starti < c) ++i;
  }
  cout << bus << endl;
}