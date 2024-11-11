#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
int main() {
  int n, d, a, b, c, e, f, h = 0;
  cin >> n >> d;
  cin >> a >> b;
  vector<pair<int, int> > v;
  for (int i = 0; i < n; i++) {
    cin >> c >> e;
    f = c * a + e * b;
    h = i + 1;
    v.push_back(make_pair(f, h));
  }
  sort((v).begin(), (v).end());
  long long ret = 0, g = 0, id = -1;
  for (int i = 0; i < n; i++) {
    ret += v[i].first;
    if (ret > d) {
      ret -= v[i].first;
      break;
    }
    id = i;
  }
  if (id == -1) {
    cout << 0 << endl;
    return 0;
  }
  id++;
  cout << id << endl;
  for (int i = 0; i < id; i++) {
    cout << v[i].second << " ";
  }
  cout << ret << endl;
  return 0;
}
