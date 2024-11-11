#include <bits/stdc++.h>
using namespace std;
void init() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}
int main() {
  string input;
  cin >> input;
  vector<int> points;
  for (int i = 0; i < (int)input.length(); ++i) {
    if (input[i] == '.') {
      points.push_back(i);
    }
  }
  if ((input.length() < 3) || (input[0] == '.') ||
      (input[input.length() - 1] == '.')) {
    cout << "NO";
    return 0;
  }
  for (int i = 0; i < (int)points.size() - 1; ++i) {
    if ((points[i + 1] - points[i] <= 2) || (points[i + 1] - points[i] > 12)) {
      cout << "NO";
      return 0;
    }
  }
  if ((points.size() == 0) || (points[0] >= 9) ||
      (input.length() - points[points.size() - 1] >= 5)) {
    cout << "NO";
    return 0;
  }
  cout << "YES" << endl;
  int c = 0;
  string ans = "";
  for (int i = 0; i < (int)points.size() - 1; ++i) {
    while (input[c] != '.') {
      ans += input[c];
      ++c;
    }
    ans += '.';
    ++c;
    ans += input[c];
    ++c;
    if (points[i + 1] - points[i] >= 11) {
      ans += input[c];
      ++c;
      if (points[i + 1] - points[i] == 12) {
        ans += input[c];
        ++c;
      }
    }
    cout << ans << endl;
    ans = "";
  }
  while (c < (int)input.length()) {
    ans += input[c];
    ++c;
  }
  cout << ans;
  return 0;
}
