#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<string> Poland, Enemy;
  set<string> all;
  for (int i = 0; i < n; i++) {
    string word;
    cin >> word;
    Poland.push_back(word);
    all.insert(word);
  }
  for (int i = 0; i < m; i++) {
    string word;
    cin >> word;
    Enemy.push_back(word);
    all.insert(word);
  }
  int common = Poland.size() + Enemy.size() - all.size();
  int P = Poland.size() - common;
  int E = Enemy.size() - common;
  if (P > E)
    cout << "YES" << endl;
  else if (P < E)
    cout << "NO" << endl;
  else if (common % 2)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
