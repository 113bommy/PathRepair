#include <bits/stdc++.h>
using namespace std;
stringstream ss;
string input;
vector<string> v[1000001];
void dfs(int d) {
  string s;
  getline(ss, s, ',');
  v[d].push_back(s);
  getline(ss, s, ',');
  int n = stoi(s);
  for (int i = 0; i < n; i++) dfs(d + 1);
}
int main() {
  cin >> input;
  ss << input;
  while (!ss.eof()) dfs(1);
  int d = 1;
  while (v[d].size()) d++;
  cout << d << endl;
  for (int i = 1; i <= d; i++) {
    for (int j = 0; j < v[i].size(); j++) cout << v[i][j] << " ";
    cout << endl;
  }
}
