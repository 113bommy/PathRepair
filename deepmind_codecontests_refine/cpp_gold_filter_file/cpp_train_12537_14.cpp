#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  int ans = 0;
  vector<pair<char, int> > data;
  for (int i = 0; i < n; i++) {
    if (s[i] != '.') {
      pair<char, int> x;
      x.first = s[i];
      x.second = i;
      data.push_back(x);
    }
  }
  if (data.size() == 0) {
    ans = n;
  } else {
    if (data[0].first == 'R') {
      ans += data[0].second;
    }
    for (int i = 1; i < data.size(); i++) {
      if (data[i - 1].first == 'R' && data[i].first == 'L') {
        if ((data[i].second - data[i - 1].second) % 2 == 0) {
          ans++;
        }
      }
      if (data[i - 1].first == 'L' && data[i].first == 'R') {
        ans += (data[i].second - data[i - 1].second) - 1;
      }
    }
    if (data.size() > 0 && data[data.size() - 1].first == 'L') {
      ans += n - data[data.size() - 1].second - 1;
    }
  }
  cout << ans << endl;
  return 0;
}
