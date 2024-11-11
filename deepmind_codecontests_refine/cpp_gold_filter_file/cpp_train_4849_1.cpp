#include <bits/stdc++.h>
using namespace std;
vector<string> w[2113];
string w2[2113];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int multitest, n, m;
  cin >> multitest;
  for (int i_dly_multitesta = 0; i_dly_multitesta < multitest;
       i_dly_multitesta++) {
    vector<string> name;
    cin >> n;
    string imy_krch;
    for (int i = 0; i < n; i++) {
      cin >> imy_krch;
      name.push_back(imy_krch);
    }
    cin >> m;
    getline(cin, imy_krch);
    for (int i = 0; i < m; i++) {
      string dich, norm_imy;
      getline(cin, dich);
      int j = 0;
      while (dich[j] != ':') norm_imy.push_back(dich[j++]);
      while (j < dich.size()) w2[i].push_back(dich[j++]);
      if (norm_imy != "?")
        w[i].push_back(norm_imy);
      else {
        w[i] = name;
        string g;
        int x = 0;
        while (x < w2[i].size()) {
          while (x < w2[i].size() && ((w2[i][x] >= 'a' && w2[i][x] <= 'z') ||
                                      (w2[i][x] >= 'A' && w2[i][x] <= 'Z') ||
                                      (w2[i][x] >= '0' && w2[i][x] <= '9'))) {
            g.push_back(w2[i][x]);
            x++;
          }
          if (find(w[i].begin(), w[i].end(), g) != w[i].end())
            w[i].erase(find(w[i].begin(), w[i].end(), g));
          g.clear();
          x++;
        }
      }
    }
    for (int i = 0; i < m; i++) {
      if (w[i].size() == 1) {
        int j = i;
        while (j > 0 && w[j].size() == 1 &&
               find(w[j - 1].begin(), w[j - 1].end(), w[j][0]) !=
                   w[j - 1].end()) {
          w[j - 1].erase(find(w[j - 1].begin(), w[j - 1].end(), w[j][0]));
          j--;
        }
        if (i + 1 < m &&
            find(w[i + 1].begin(), w[i + 1].end(), w[i][0]) != w[i + 1].end())
          w[i + 1].erase(find(w[i + 1].begin(), w[i + 1].end(), w[i][0]));
      }
    }
    bool kl = true;
    for (int i = 0; i < m; i++) {
      if (w[i].size() == 0 && kl) {
        cout << "Impossible" << endl;
        kl = false;
      } else {
        string e = w[i][0];
        w[i].clear();
        w[i].push_back(e);
        if (i + 1 < m &&
            find(w[i + 1].begin(), w[i + 1].end(), w[i][0]) != w[i + 1].end())
          w[i + 1].erase(find(w[i + 1].begin(), w[i + 1].end(), w[i][0]));
      }
    }
    if (kl)
      for (int i = 0; i < m; i++) cout << w[i][0] << w2[i] << endl;
    for (int i = 0; i < m + n; i++) {
      w[i].clear();
      w2[i].clear();
    }
  }
}
