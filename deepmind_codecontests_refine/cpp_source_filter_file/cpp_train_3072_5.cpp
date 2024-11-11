#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, i, x1, x2, a, b;
  bool flag = false;
  vector<pair<long long, long long> > lines;
  cin >> n >> x1 >> x2;
  for (i = 0; i < n; i++) {
    cin >> a >> b;
    lines.push_back(make_pair(a * x1 + b, a * x2 + b));
  }
  sort(lines.begin(), lines.end());
  for (i = 1; i < n; i++) {
    if (lines[i - 1].second > lines[i].first) flag = true;
  }
  cout << (flag ? "YES" : "NO") << endl;
  return 0;
}
