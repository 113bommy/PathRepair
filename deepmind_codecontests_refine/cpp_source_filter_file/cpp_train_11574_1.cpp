#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<string> str(n);
  vector<vector<pair<char, int>>> v(1000001);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    str[i] = s;
    int k = 0;
    char last = '.';
    for (int j = s.length() - 1; j >= 0; j--) {
      if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' ||
          s[j] == 'u') {
        k++;
        if (last == '.') last = s[j];
      }
    }
    if (k >= 1) v[k].push_back({last, i});
  }
  int siz = v.size();
  vector<int> fir;
  vector<int> sec;
  for (int i = 1; i < v.size(); i++) {
    sort(v[i].begin(), v[i].end());
    int k = 0;
    int t_siz = v[i].size();
    while (k < t_siz) {
      if (k + 1 < t_siz && v[i][k].first == v[i][k + 1].first) {
        sec.push_back(v[i][k].second);
        sec.push_back(v[i][k + 1].second);
        k += 2;
      } else {
        fir.push_back(v[i][k].second);
        k++;
      }
    }
    if (fir.size() >= 1 && fir.size() % 2 == 1) fir.pop_back();
  }
  int i = 0;
  int j = 0;
  int ans = 0;
  if (fir.size() > sec.size())
    ans = sec.size() / 2;
  else {
    ans = fir.size() / 2 + (sec.size() - fir.size()) / 4;
  }
  cout << ans << '\n';
  while (i < fir.size() && j < sec.size()) {
    cout << str[fir[i]] << ' ' << str[sec[j]] << '\n';
    cout << str[fir[i + 1]] << ' ' << str[sec[j + 1]] << '\n';
    i += 2;
    j += 2;
  }
  while (j + 3 < sec.size()) {
    cout << str[sec[j]] << ' ' << str[sec[j + 1]] << '\n';
    cout << str[sec[j + 2]] << ' ' << str[sec[j + 3]] << '\n';
    j = j + 4;
  }
  return 0;
}
