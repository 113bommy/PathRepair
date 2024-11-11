#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int l = n * (n - 1);
  l /= 2;
  if (k >= l) {
    cout << "no solution\n";
    return 0;
  }
  pair<int, int> p;
  vector<pair<int, int> > v;
  int a = 0, b = 0;
  for (int i = 0; i < n; i++) {
    p = make_pair(b, a);
    v.push_back(p);
    a++;
  }
  for (int i = 0; i < n; i++) {
    cout << v[i].first << " " << v[i].second << endl;
  }
  return 0;
}
