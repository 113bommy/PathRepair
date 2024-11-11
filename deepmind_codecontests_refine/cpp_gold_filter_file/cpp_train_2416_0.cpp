#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int k, i, b, j, ans = 0;
    cin >> k;
    map<string, vector<string> > sl;
    map<string, int> kolv;
    vector<string> ch(k);
    string a;
    for (i = 0; i < k; i++) {
      cin >> ch[i];
      kolv[ch[i]] += 1;
      string ne = ch[i].substr(0, 3);
      sl[ne].push_back(ch[i].substr(3, 1));
    }
    for (i = 0; i < k; i++) {
      a = ch[i];
      if (kolv[a] > 1) {
        string osn = a.substr(0, 3);
        for (j = 0; j < 10; j++)
          if (find(sl[osn].begin(), sl[osn].end(), to_string(j)) ==
              sl[osn].end()) {
            a[3] = j + '0';
            ans++;
            break;
          }
        kolv[ch[i]] -= 1;
        sl[osn].push_back(to_string(j));
        ch[i] = a;
      }
    }
    cout << ans << endl;
    for (auto c : ch) {
      cout << c << endl;
    }
  }
  return 0;
}
