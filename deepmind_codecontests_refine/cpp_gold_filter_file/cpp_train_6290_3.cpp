#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100100;
const int INF = 1000 * 1000 * 1000;
string second;
vector<int> ans;
bool check(int x1, int x2) {
  if (x1 > x2 - x1) return false;
  if (x1 < x2 - x1) return true;
  for (int i = 0; i < x1; ++i) {
    if (second[i] > second[i + x1])
      return false;
    else if (second[i] < second[i + x1])
      return true;
  }
  return false;
}
int main() {
  cin >> second;
  for (int i = 0; i < second.length(); ++i) {
    if (second[i] != '0') ans.push_back(i);
  }
  ans.push_back(second.length());
  int cnt = 1;
  for (int i = 1; i < ans.size() - 1; ++i) {
    if (check(ans[i], ans[i + 1])) {
      cnt = i + 1;
    }
  }
  cout << (ans.size() - 1) - cnt + 1;
  return 0;
}
