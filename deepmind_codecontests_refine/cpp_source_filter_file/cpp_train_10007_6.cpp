#include <bits/stdc++.h>
using namespace std;
int dx[9] = {1, -1, 0, 0, 1, 1, -1, -1, 0};
int dy[9] = {0, 0, 1, -1, 1, -1, 1, -1, 0};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<string> v;
  string s;
  cin >> s;
  int i;
  for (i = 0; i < 6; i++) {
    string s1, s2;
    s1.push_back(i / 10 + 48);
    s1.push_back(i % 10 + 48);
    s2.push_back(i % 10 + 48);
    s2.push_back(i / 10 + 48);
    v.push_back(s1 + ':' + s2);
  }
  for (i = 10; i < 16; i++) {
    string s1, s2;
    s1.push_back(i / 10 + 48);
    s1.push_back(i % 10 + 48);
    s2.push_back(i % 10 + 48);
    s2.push_back(i / 10 + 48);
    v.push_back(s1 + ':' + s2);
  }
  for (i = 20; i < 23; i++) {
    string s1, s2;
    s1.push_back(i / 10 + 48);
    s1.push_back(i % 10 + 48);
    s2.push_back(i % 10 + 48);
    s2.push_back(i / 10 + 48);
    v.push_back(s1 + ':' + s2);
  }
  for (i = 0; i < v.size(); i++) {
    if (s.compare(v[i]) < 0) break;
  }
  if (i == v.size())
    cout << v[0];
  else
    cout << v[i];
  return 0;
}
