#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  string second;
  cin >> second;
  vector<int> ans;
  int tmp = 0;
  for (int i = 0; i < second.size(); i++) {
    if (second[i] == '1') tmp++;
    if (second[i] == '0') {
      ans.push_back(tmp);
      tmp = 0;
    }
  }
  ans.push_back(tmp);
  for (int &x : ans) cout << x;
}
