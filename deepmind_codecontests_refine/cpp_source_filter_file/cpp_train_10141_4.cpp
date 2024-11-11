#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> segment, oneseg;
  string str;
  int res = 0, noneseg = 0;
  cin >> str;
  segment.push_back(1);
  for (int i = 1; i < str.size(); i++)
    if (str[i] == str[i] - 1)
      segment.back()++;
    else
      segment.push_back(1);
  if (segment.size() > 1 && segment.size() % 2 == 1) {
    segment[0] += segment.back();
    segment.pop_back();
  }
  if (segment[0] == 1) oneseg.push_back(1);
  for (int i = 1; i < segment.size(); i++)
    if (segment[i] == 1) {
      if (segment[i - 1] == 1)
        oneseg.back()++;
      else
        oneseg.push_back(1);
    }
  if (segment.back() == segment[0] && segment[0] == 1 && oneseg.size() > 1) {
    oneseg[0] += oneseg.back();
    oneseg.pop_back();
  }
  for (int i = 0; i < oneseg.size(); i++) {
    res += oneseg[i] / 2;
    noneseg += oneseg[i];
  }
  res += segment.size() - noneseg;
  cout << res << '\n';
  return 0;
}
