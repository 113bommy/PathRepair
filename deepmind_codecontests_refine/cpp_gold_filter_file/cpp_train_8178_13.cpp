#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
const int MOD = 1000000007;
int main() {
  ios::sync_with_stdio(false);
  map<int, int> my;
  map<int, int>::iterator it;
  int n;
  cin >> n;
  my[-1] = 0;
  for (int i = 0; i < (n); ++i) {
    int t;
    cin >> t;
    my[t] = INF;
    int key1 = -1, key2 = -1, key3 = -1;
    it = my.lower_bound(t - 1);
    if (it->first > t - 1) {
      if (it != my.begin()) {
        it--;
        key1 = it->first;
      }
    } else
      key1 = it->first;
    it = my.lower_bound(t - 90);
    if (it->first > t - 90) {
      if (it != my.begin()) {
        it--;
        key2 = it->first;
      }
    } else
      key2 = it->first;
    it = my.lower_bound(t - 1440);
    if (it->first > t - 1440) {
      if (it != my.begin()) {
        it--;
        key3 = it->first;
      }
    } else
      key3 = it->first;
    int value = min(my[key1] + 20, my[key2] + 50);
    value = min(value, my[key3] + 120);
    my[t] = value;
    cout << my[t] - my[key1] << '\n';
  }
  return 0;
}
