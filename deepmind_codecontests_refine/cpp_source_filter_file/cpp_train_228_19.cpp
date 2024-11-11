#include <bits/stdc++.h>
using namespace std;
void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }
void nl() { cout << endl; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    string s;
    vector<vector<int>> a;
    a.resize(27);
    vector<int> v(m), ans(27);
    cin >> s;
    for (long long i = 0; i < 27; i++) ans[i] = 0;
    for (long long i = 0; i < n; i++) {
      a[s[i] - 'a'].push_back(i);
    }
    for (long long i = 0; i < m; i++) {
      cin >> v[i];
      v[i]--;
    }
    v.push_back(n - 1);
    for (long long i = 0; i < m + 1; i++) {
      for (long long j = 0; j < 26; j++) {
        if (a[j].size() == 0) continue;
        int x = upper_bound(a[j].begin(), a[j].end(), v[i]) - a[j].begin();
        ans[j] += x;
      }
    }
    for (long long i = 0; i < 27; i++) cout << ans[i] << " ";
    cout << endl;
  }
}
