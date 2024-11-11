#include <bits/stdc++.h>
using namespace std;
class {
 public:
  string s;
  void solve() {
    cin >> s;
    int n = s.length();
    vector<int> f(n);
    string ask(n, 'a');
    for (int i = 0; i < n; i++) {
      ask[i] += i % 26;
    }
    cout << "? " << ask << endl;
    cin >> ask;
    for (int i = 0; i < n; i++) {
      f[i] += ask[i] - 'a';
    }
    for (int i = 0; i < n; i++) {
      int j = i / 26;
      ask[i] = j % 26 + 'a';
    }
    cout << "? " << ask << endl;
    cin >> ask;
    for (int i = 0; i < n; i++) f[i] += 26 * (ask[i] - 'a');
    for (int i = 0; i < n; i++) {
      int j = i / 26;
      j /= 26;
      ask[i] = j % 26 + 'a';
    }
    cout << "? " << ask << endl;
    cin >> ask;
    for (int i = 0; i < n; i++) f[i] += 26 * 26 * (ask[i] - 'a');
    for (int i = 0; i < n; i++) ask[i] = s[f[i]];
    cout << "! " << ask << endl;
  }
} NSPACE;
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  NSPACE.solve();
}
