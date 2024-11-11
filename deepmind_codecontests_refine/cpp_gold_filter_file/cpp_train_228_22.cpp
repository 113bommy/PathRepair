#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int tmp;
    int alp[26];
    for (int i = 0; i < 26; i++) {
      alp[i] = 0;
    }
    char s[n + 1];
    for (int i = 1; i <= n; i++) {
      cin >> s[i];
    }
    vector<int> p;
    for (int i = 0; i < m; i++) {
      cin >> tmp;
      p.push_back(tmp);
    }
    sort(p.begin(), p.end());
    int t = m + 1;
    int u = 0;
    for (int i = 1; i <= n; i++) {
      alp[s[i] - 'a'] += t;
      while (u < m && p[u] == i) {
        t--;
        u++;
      }
    }
    for (int i = 0; i < 26; i++) {
      cout << alp[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
