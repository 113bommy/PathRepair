#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n, k;
  cin >> n >> k;
  int a[100005];
  int x;
  set<pair<int, int> > s;
  for (int i = 0; i < k; i++) {
    cin >> x;
    s.insert({x, x});
    a[x] = 1;
    if (a[x - 1]) {
      s.insert({x, x - 1});
    }
    if (a[x + 1]) {
      s.insert({x, x + 1});
    }
  }
  cout << n * 3 - 2 - s.size();
  return 0;
}
