#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
const long long num = 1000000000;
int main() {
  long long q = 1;
  while (q--) {
    string s, t;
    cin >> s;
    cin >> t;
    long long n = s.size();
    long long m = t.size();
    map<char, vector<long long> > adj;
    for (char c = 'a'; c <= 'z'; c++) {
      adj[c] = vector<long long>();
    }
    for (int i = 0; i < n; i++) {
      adj[s[i]].push_back(i);
    }
    vector<vector<long long> > ind(m);
    for (int i = 0; i < m; i++) {
      ind[i] = adj[t[i]];
    }
    for (int i = 0; i < m - 1; i++) {
      while (ind[i + 1][0] <= ind[i][0]) {
        ind[i + 1].erase(ind[i + 1].begin());
      }
    }
    for (int i = m - 1; i > 0; i--) {
      long long n1 = ind[i - 1].size();
      long long n2 = ind[i].size();
      while (ind[i - 1][n1 - 1] >= ind[i][n2 - 1]) {
        ind[i - 1].erase(ind[i - 1].begin() + (n1 - 1));
        n1--;
      }
    }
    long long mx = ind[0][ind[0].size() - 1];
    mx = max(mx, m - ind[m - 1][0] - 1);
    for (int i = 0; i < m - 1; i++) {
      mx = max(mx, ind[i + 1][ind[i + 1].size() - 1] - ind[i][0] - 1);
    }
    cout << mx << endl;
  }
  return 0;
}
