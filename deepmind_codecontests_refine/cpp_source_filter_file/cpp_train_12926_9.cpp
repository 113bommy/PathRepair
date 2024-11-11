#include <bits/stdc++.h>
using namespace std;
int n, k, A = 1, res;
string s;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k >> s;
  res = n * k;
  unordered_set<string> str;
  str.insert(s);
  queue<string> q;
  q.push(s);
  while (!q.empty() && A <= k) {
    string S = q.front();
    res -= S.size();
    A++;
    q.pop();
    for (int i = 0; i < S.size(); i++) {
      string ns = S.substr(0, i) + S.substr(i + 1);
      if (str.find(ns) == str.end()) {
        q.push(ns);
        str.insert(ns);
      }
    }
  }
  cout << (A < k ? -1 : res) << endl;
}
