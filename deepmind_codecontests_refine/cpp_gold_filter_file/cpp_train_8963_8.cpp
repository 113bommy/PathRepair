#include <bits/stdc++.h>
using namespace std;
const int N = 3 * 1e5;
pair<char, int> arr[N];
int main() {
  int t;
  cin >> t;
  char c;
  int n;
  int l = 1;
  int r = 0;
  while (t--) {
    cin >> c >> n;
    if (c == 'L') {
      arr[n].first = 'L';
      arr[n].second = l;
      l++;
    } else if (c == 'R') {
      arr[n].first = 'R';
      arr[n].second = r;
      r++;
    } else {
      char tmpc = arr[n].first;
      int tmpi = arr[n].second;
      if (tmpc == 'R')
        cout << min(r - tmpi - 1, l + tmpi - 1) << endl;
      else
        cout << min(l - tmpi - 1, r + tmpi - 1) << endl;
    }
  }
  return 0;
}
