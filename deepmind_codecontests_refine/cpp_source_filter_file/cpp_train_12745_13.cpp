#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  bool right1 = false, left1 = false;
  vector<int> right;
  vector<int> left;
  for (int t = 1; t <= c; t++) {
    if (b + t <= a) {
      right.push_back(b + t);
    }
    if (t == c && b + t < a) right1 = true;
  }
  sort(right.begin(), right.end());
  for (int u = 1; u <= c; u++) {
    if (b - u >= 1) left.push_back(b - u);
    if (u == c && b - u > 1) left1 = true;
  }
  sort(left.begin(), left.end());
  if (left1) cout << "<< ";
  for (int q1 = 0; q1 < left.size(); q1++) cout << left[q1] << " ";
  cout << "( " << b << " ) ";
  for (int q = 0; q < right.size(); q++) cout << right[q] << " ";
  if (right1) cout << ">>";
}
