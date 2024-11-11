#include <bits/stdc++.h>
using namespace std;
long long ans1 = 0, ans2 = 0;
int n;
deque<char> q;
vector<string> arr[26];
long double ans = 3;
void play() {
  deque<char> q1;
  string s = "";
  q1 = q;
  while (!q1.empty()) {
    s += q1.front();
    q1.pop_front();
  }
  arr[int(s[0] - 'a')].push_back(s);
}
void getAns() {
  int used[26];
  for (int i = 0; i < 26; i++) {
    if (arr[i].size() < 1) continue;
    int k = 0, sm;
    for (int q = 0; q < n; q++) {
      sm = 0;
      for (int j = 0; j < 26; j++) used[j] = 0;
      for (int j = 0; j < arr[i].size(); j++) used[int(arr[i][j][q] - 'a')]++;
      for (int j = 0; j < 26; j++)
        if (used[j] == 1) sm++;
      k = max(k, sm);
    }
    ans1 += k;
    ans2 += arr[i].size();
  }
  ans = ((long double)(ans1)) / ans2;
}
int main() {
  string s;
  cin >> s;
  n = s.size();
  for (int i = 0; i < s.size(); i++) q.push_back(s[i]);
  for (int i = 0; i < s.size(); i++) {
    play();
    auto v = q.front();
    q.pop_front();
    q.push_back(v);
  }
  getAns();
  cout << fixed << setprecision(8) << ans;
  return 0;
}
