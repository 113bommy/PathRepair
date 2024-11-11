#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
map<string, string> child;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int m = 0;
  for (int i = 0; i < n; i++) {
    string from, to;
    cin >> from >> to;
    if (child.count(from) == 0)
      child[to] = from;
    else {
      child[to] = child[from];
      child.erase(from);
    }
  }
  cout << child.size() << "\n";
  for (map<string, string>::iterator it = child.begin(); it != child.end();
       it++)
    cout << it->second << ' ' << it->first << "\n";
}
