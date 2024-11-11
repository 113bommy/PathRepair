#include <bits/stdc++.h>
using namespace std;
int check(string s) {
  string ans = "";
  set<char> st;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != '-') {
      st.insert(s[i]);
      ans += s[i];
    }
  }
  if (st.size() == 1) return 0;
  if (st.size() < 6) return 2;
  for (int i = 0; i < ans.size() - 1; i++) {
    if (ans[i] < ans[i + 1]) return 2;
  }
  return 1;
}
int main() {
  int n;
  cin >> n;
  int reg[n][3];
  memset(reg, 0, sizeof(reg));
  string name[n];
  for (int i = 0; i < n; i++) {
    int num;
    string s;
    cin >> num >> s;
    name[i] = s;
    for (int j = 0; j < num; j++) {
      string s2;
      cin >> s2;
      reg[i][check(s2)]++;
    }
  }
  vector<string> v2[3];
  for (int i = 0; i < 3; i++) {
    int maxx = 0;
    for (int j = 0; j < n; j++) {
      maxx = max(maxx, reg[j][i]);
    }
    for (int j = 0; j < n; j++) {
      if (reg[j][i] == maxx) {
        v2[i].push_back(name[j]);
      }
    }
  }
  string temp = "";
  for (int i = 0; i < v2[0].size(); i++) {
    if (i != v2[0].size() - 1)
      temp += v2[0][i] + ',';
    else
      temp += v2[0][i] + '.';
  }
  cout << "If you want to call a taxi, you should call: " + temp << endl;
  temp = "";
  for (int i = 0; i < v2[1].size(); i++) {
    if (i != v2[1].size() - 1)
      temp += v2[1][i] + ',';
    else
      temp += v2[1][i] + '.';
  }
  cout << "If you want to order a pizza, you should call: " + temp << endl;
  temp = "";
  for (int i = 0; i < v2[2].size(); i++) {
    if (i != v2[2].size() - 1)
      temp += v2[2][i] + ',';
    else
      temp += v2[2][i] + '.';
  }
  cout << "If you want to go to a cafe with a wonderful girl, you should "
          "call: " +
              temp;
}
