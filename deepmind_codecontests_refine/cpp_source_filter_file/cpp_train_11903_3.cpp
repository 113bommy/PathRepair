#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  string s;
  cin >> s;
  int start_ind = 0;
  int end_ind = 0;
  int one_count = 0;
  vector<pair<int, int>> ans;
  int zeroes_seq = 0;
  long long res = 0;
  if (n == 0) {
    for (int i = 0; i < (int)s.size(); ++i) {
      if (s[i] == '0')
        ++zeroes_seq;
      else {
        res += (zeroes_seq + 1) * (zeroes_seq) / 2;
        zeroes_seq = 0;
      }
    }
    res += (zeroes_seq + 1) * (zeroes_seq) / 2;
    cout << res << endl;
    return 0;
  }
  while (end_ind < (int)s.size() && start_ind < (int)s.size()) {
    if (s[end_ind] == '1') ++one_count;
    ++end_ind;
    if (one_count == n) {
      ans.push_back(make_pair(start_ind, end_ind));
      --one_count;
      ++start_ind;
    }
    while (s[start_ind] == '0') ++start_ind;
  }
  for (int i = 0; i < (int)ans.size(); ++i) {
    res += 1;
    long long left_zeroes = 0;
    long long right_zeroes = 0;
    if (ans[i].first != 0) {
      for (int j = ans[i].first - 1; j >= 0; --j) {
        if (s[j] == '0')
          ++left_zeroes;
        else
          break;
      }
    }
    if (ans[i].second != (int)s.size()) {
      for (int j = ans[i].second; j < (int)s.size(); ++j) {
        if (s[j] == '0')
          ++right_zeroes;
        else
          break;
      }
    }
    res += left_zeroes;
    res += right_zeroes;
    res += (left_zeroes * right_zeroes);
  }
  cout << res << endl;
  return 0;
}
