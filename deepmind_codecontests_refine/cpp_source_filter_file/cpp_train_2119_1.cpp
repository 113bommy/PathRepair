#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, n, d, x, y;
  vector<pair<int, int> > v;
  cin >> n >> d >> a >> b;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    v.push_back({x * a + y * b, i});
  }
  sort(v.begin(), v.end());
  int sum = 0, in = 0;
  for (int i = 0; i < n; i++) {
    if (sum + v[i].first > d) break;
    sum += v[i].first;
    in++;
  }
  cout << in << endl;
  for (int i = 0; i < in - 1; i++) cout << v[i].second + 1 << " ";
  if (in > 0) cout << v[in - 1].second + 1;
  return 0;
}
