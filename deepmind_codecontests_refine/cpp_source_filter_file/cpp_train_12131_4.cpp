#include <bits/stdc++.h>
using namespace std;
vector<int> p[26];
int main(int argc, char const *argv[]) {
  cout.sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    p[s[i] - 'a'].push_back(i);
  }
  for (int z = 0; z < n; z++) {
    string c;
    cin >> c;
    int f = 0;
    for (int j = 0; j < c.size(); j++) {
      int idx = c[j] - 'a';
      if (p[idx].size() == 0)
        f += c.size();
      else {
        vector<int>::iterator up =
            upper_bound(p[idx].begin(), p[idx].end(), j - 1);
        if (up == p[idx].begin())
          f += abs(p[idx][0] - j);
        else {
          int aux = up - p[idx].begin();
          f += min(abs(p[idx][aux] - j), abs(p[idx][aux - 1] - j));
        }
      }
    }
    cout << f << endl;
  }
  return 0;
}
