#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  vector<pair<char, int>> V;
  for (int i = 0; i < s.length(); i++) V.push_back(make_pair(-s[i], i));
  sort((V).begin(), (V).end());
  for (int i = 0, k = 0; i < V.size(); i++) {
    char ch = -V[i].first;
    int p = V[i].second;
    if (p > k) {
      cout << ch;
      k = p;
    }
  }
  return (0);
}
