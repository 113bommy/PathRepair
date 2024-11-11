#include <bits/stdc++.h>
using namespace std;
const long long p = 1000000007;
int main() {
  ios_base::sync_with_stdio(false);
  string s, t;
  int n;
  cin >> n;
  map<char, int> m;
  for (int i = 'a'; i <= 'z'; i++) m[i] = 0;
  cin >> t >> s;
  for (char c : s) m[c]++;
  for (char c : t) {
    m[c]--;
    if (m[c] < 0) {
      cout << -1 << endl;
      return 0;
    }
  }
  vector<int> v;
  for (int i = 0; i < s.size(); i++) {
    char c = s[i];
    int ind;
    for (int i = 0; i < s.size(); i++) {
      if (t[i] == c) {
        ind = i;
        break;
      }
    }
    if (ind != s.size() - 1) {
      v.push_back(s.size() - ind - 1);
    }
    v.push_back(1);
    v.push_back(s.size());
    string w1 = t.substr(0, ind);
    string w3 = t.substr(s.size() - i);
    string w2 = t.substr(ind + 1, s.size() - w1.size() - w3.size() - 1);
    reverse(w2.begin(), w2.end());
    t = w2 + w1 + w3 + c;
  }
  cout << v.size() << endl;
  for (int x : v) {
    cout << x << " ";
  }
}
