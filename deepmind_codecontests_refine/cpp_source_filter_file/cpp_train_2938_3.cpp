#include <bits/stdc++.h>
using namespace std;
void program();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  program();
}
const int MX = 100;
int n, m, a, b;
map<string, int> small, big;
vector<string> suffix;
string ans;
void program() {
  cin >> n;
  m = n / 2;
  ans.resize(n);
  if (n <= 3) {
    for (int i = int(1); i < int(n + 1); i++) {
      cout << "? " << i << " " << i << endl;
      cout.flush();
      cin >> ans[i];
    }
  } else {
    a = (n * (n - 1)) / 2;
    b = (n * (n + 1)) / 2;
    cout << "? 1 " << n - 1 << endl;
    cout.flush();
    for (int i = int(0); i < int(a); i++) {
      string s;
      cin >> s;
      sort(s.begin(), s.end());
      small[s]++;
    }
    cout << "? 1 " << n << endl;
    cout.flush();
    for (int i = int(0); i < int(b); i++) {
      string s;
      cin >> s;
      sort(s.begin(), s.end());
      big[s]++;
    }
    for (auto p : big) {
      if (small[p.first] != p.second) {
        suffix.push_back(p.first);
      }
    }
    sort(suffix.begin(), suffix.end(),
         [](string& a, string& b) { return a.size() < b.size(); });
    for (int i = int(0); i < int(suffix.size()); i++) {
      int c = -1;
      for (int j = int(0); j < int(i); j++)
        if (suffix[i - 1][j] != suffix[i][j]) {
          c = j;
          break;
        }
      if (c == -1) c = i;
      ans[n - i - 1] = suffix[i][c];
    }
  }
  cout << "! " << ans << endl;
}
