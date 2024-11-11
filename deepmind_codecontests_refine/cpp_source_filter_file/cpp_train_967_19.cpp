#include <bits/stdc++.h>
using namespace std;
int num(char s) {
  if (s >= '0' && s <= '9')
    return s - '0';
  else
    return s - 'A' + 10;
}
int main() {
  string input, h, m;
  vector<int> result;
  int i, hrs, mts, j;
  cin >> input;
  int max = -1;
  for (i = 0; i < input.size(); i++)
    if (input[i] == ':') {
      h = input.substr(0, i);
      m = input.substr(i + 1);
    } else if (num(input[i]) > max)
      max = num(input[i]);
  int k = 0;
  for (i = max + 1; i < 60; i++) {
    hrs = 0;
    mts = 0;
    for (j = 0; j < h.length(); j++) hrs = hrs * i + num(h[j]);
    for (j = 0; j < m.length(); j++) mts = mts * i + num(m[j]);
    if (hrs <= 24 && hrs >= 0 && mts <= 60 && mts >= 0) result.push_back(i);
  }
  hrs = 0;
  mts = 0;
  for (j = 0; j < h.length(); j++) hrs = hrs * 100 + num(h[j]);
  for (j = 0; j < m.length(); j++) mts = mts * 100 + num(m[j]);
  if (hrs < 24 && hrs >= 0 && mts < 60 && mts >= 0)
    cout << -1;
  else if (result.empty())
    cout << 0;
  else
    for (i = 0; i < result.size(); i++) cout << result[i] << " ";
  return 0;
}
