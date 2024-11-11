#include <bits/stdc++.h>
using namespace std;
inline void prep() {
  cin.tie(0);
  cin.sync_with_stdio(0);
}
const int mod = (int)1e9 + 7;
const int MX = (int)2e5 + 1;
int main() {
  prep();
  int n, x, y;
  cin >> n >> x >> y;
  vector<int> a(n);
  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  vector<int> io(n);
  iota(io.begin(), io.end(), 0);
  sort(io.begin(), io.end(), [&](int x, int y) { return a[x] < a[y]; });
  if (sum < (x + y)) return puts("No"), 0;
  vector<int> resX, resY;
  auto go = [&](int s1, int s2) {
    resX.clear(), resY.clear();
    int idx = n - 1;
    int cnt = 1;
    while (idx >= 0 && ((s1 + cnt - 1) / cnt) > a[io[idx]])
      resX.push_back(io[idx] + 1), idx--, cnt++;
    resX.push_back(io[idx] + 1);
    idx--;
    cnt = 1;
    while (idx >= 0 && ((s2 + cnt - 1) / cnt) > a[io[idx]])
      resY.push_back(io[idx] + 1), idx--, cnt++;
    resY.push_back(io[idx] + 1);
    return idx >= 0;
  };
  if (go(x, y)) {
    cout << "Yes" << endl;
    cout << resX.size() << " " << resY.size() << endl;
    for (auto xx : resX) cout << xx << " ";
    cout << endl;
    for (auto yy : resY) cout << yy << " ";
    cout << endl;
  } else if (go(y, x)) {
    cout << "Yes" << endl;
    cout << resY.size() << " " << resX.size() << endl;
    for (auto yy : resY) cout << yy << " ";
    cout << endl;
    for (auto xx : resX) cout << xx << " ";
    cout << endl;
  } else
    cout << "No" << endl;
  return 0;
}
