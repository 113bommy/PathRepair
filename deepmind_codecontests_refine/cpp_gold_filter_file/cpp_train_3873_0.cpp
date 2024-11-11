#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int f = 0;
    int c[26];
    for (int i = 0; i < 26; i++) c[i] = 0;
    for (int i = 0; i < n; i++) {
      c[a[i] - 'a']++;
      c[b[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
      if (c[i] % 2 != 0) f = 1;
    if (f == 1) {
      cout << "NO" << endl;
      continue;
    }
    int co = 0;
    vector<int> t1[26], t2[26];
    for (int i = 0; i < n; i++) {
      if (a[i] != b[i]) {
        co++;
        t1[a[i] - 'a'].push_back(i);
        t2[b[i] - 'a'].push_back(i);
      }
    }
    cout << "YES" << endl;
    vector<pair<int, int>> ans;
    for (int i = 0; i < 26; i++) {
      while (t1[i].size() >= 2) {
        int k1 = t1[i][0], k2 = t1[i][1];
        char k3 = b[t1[i][0]];
        ans.push_back({t1[i][1], t1[i][0]});
        b[k1] = a[k2];
        a[k2] = k3;
        for (int j = 0; j < 26; j++) {
          t1[j].clear();
          t2[j].clear();
        }
        for (int j = 0; j < n; j++) {
          if (a[j] != b[j]) {
            co++;
            t1[a[j] - 'a'].push_back(j);
            t2[b[j] - 'a'].push_back(j);
          }
        }
      }
      while (t2[i].size() >= 2) {
        int k1 = t2[i][0], k2 = t2[i][1];
        char k3 = a[t2[i][0]];
        ans.push_back({t2[i][0], t2[i][1]});
        a[k1] = b[k2];
        b[k2] = k3;
        for (int j = 0; j < 26; j++) {
          t1[j].clear();
          t2[j].clear();
        }
        for (int j = 0; j < n; j++) {
          if (a[j] != b[j]) {
            co++;
            t1[a[j] - 'a'].push_back(j);
            t2[b[j] - 'a'].push_back(j);
          }
        }
      }
      if (t1[i].size() == 1) {
        ans.push_back({t1[i][0], t1[i][0]});
        char k2 = a[t1[i][0]];
        a[t1[i][0]] = b[t1[i][0]];
        b[t1[i][0]] = k2;
        ans.push_back({t2[i][0], t1[i][0]});
        b[t1[i][0]] = a[t2[i][0]];
        a[t2[i][0]] = k2;
        for (int j = 0; j < 26; j++) {
          t1[j].clear();
          t2[j].clear();
        }
        for (int j = 0; j < n; j++) {
          if (a[j] != b[j]) {
            co++;
            t1[a[j] - 'a'].push_back(j);
            t2[b[j] - 'a'].push_back(j);
          }
        }
      }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
      cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
  }
  return 0;
}
