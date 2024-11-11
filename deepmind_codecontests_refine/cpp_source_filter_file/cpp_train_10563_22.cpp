#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  map<string, string> mp;
  while (m--) {
    string a, b;
    cin >> a >> b;
    mp[a] = (a.size() < b.size()) ? a : b;
  }
  while (n--) {
    string s;
    cin >> s;
    cout << mp[s] << " ";
  }
}
