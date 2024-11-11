#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, h, sum = 0;
  cin >> n >> m >> h;
  vector<int> s(m);
  for (int i = 0; i < (m); ++i) {
    cin >> s[i];
    sum += s[i];
  }
  if (sum < n) {
    cout << "-1.0" << endl;
    return 0;
  }
  if (n == 1) {
    cout << "0.0" << endl;
    return 0;
  }
  --sum;
  --n;
  h = s[h - 1];
  --h;
  if (sum - h < n) {
    cout << "1.0" << endl;
    return 0;
  }
  vector<double> d1, d2;
  if (h < n) swap(h, n);
  for (int i(sum - h + 1); i < (sum + 1); ++i) {
    d1.push_back(i);
  }
  for (int i(sum - h - n + 1); i < (sum - n + 1); ++i) {
    d2.push_back(i);
  }
  sort(d1.begin(), d1.end());
  sort(d2.begin(), d2.end());
  double res = 1;
  for (int i = 0; i < (d1.size()); ++i) {
    res *= (d2[i] / d1[i]);
  }
  cout << 1.0 - res << endl;
  return 0;
}
