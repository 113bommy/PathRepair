#include <bits/stdc++.h>
using namespace std;
int arr[2000002], idx = 0;
int main() {
  set<pair<double, int> > s;
  int n, x, y;
  cin >> n >> x >> y;
  for (double i = 1; i <= x; i++) s.insert(make_pair(i / x, 1));
  for (double i = 1; i <= y; i++) s.insert(make_pair(i / y, 2));
  set<pair<double, int> >::iterator it = s.begin(), last = s.begin();
  it = s.begin();
  arr[idx++] = it->second;
  it++;
  while (it != s.end()) {
    if (it->first - last->first < 1e-16) {
      if (it->second != last->second) {
        arr[idx - 1] = 3;
        arr[idx++] = 3;
      }
    } else {
      arr[idx++] = it->second;
      last = it;
    }
    it++;
  }
  int k;
  string ans[] = {"", "Vanya", "Vova", "Both"};
  while (n--) {
    cin >> k;
    k--;
    cout << ans[arr[k % idx]] << endl;
  }
}
