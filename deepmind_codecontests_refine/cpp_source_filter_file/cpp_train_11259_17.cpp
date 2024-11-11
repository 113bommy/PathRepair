#include <bits/stdc++.h>
using namespace std;
int answer;
int main() {
  int n, t;
  int temp = INT32_MAX;
  cin >> n >> t;
  vector<vector<int>> s;
  vector<int> d;
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    int ts, td;
    vector<int> temp;
    cin >> ts >> td;
    temp.push_back(ts);
    d.push_back(td);
    s.push_back(temp);
  }
  for (int i = 0; i < n; i++) {
    int temp = s[i][0];
    while (temp < t) {
      temp += d[i];
      s[i].push_back(temp);
    }
  }
  for (int i = 0; i < s.size(); i++) ans.push_back(s[i].back());
  for (int a = 0; a < ans.size() - 1; a++) {
    if (temp > ans[a]) {
      temp = ans[a];
      answer = a + 1;
    } else
      continue;
  }
  cout << answer;
  return 0;
}
