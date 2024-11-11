#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n;
    vector<string> v, in;
    vector<map<string, int>> st;
    vector<map<string, int>>::iterator it;
    v.resize(n);
    map<string, int> mp;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      mp[v[i]] = 1;
    }
    cin >> m;
    getchar();
    for (int i = 0; i < m; i++) {
      string s;
      getline(cin, s);
      in.push_back(s);
    }
    st.resize(m);
    it = st.begin();
    for (int i = 0; i < m; i++, it++) {
      if (in[i][0] != '?')
        continue;
      else {
        string s1, s2;
        s1 = s2 = "";
        if (i > 0) {
          int x = 0;
          for (int k = 0; k < in[i - 1].size(); k++) {
            if (in[i - 1][k] != ':') {
              x++;
            } else
              break;
          }
          s1 = in[i - 1].substr(0, x);
        }
        if (i < m - 1) {
          int x = 0;
          for (int k = 0; k < in[i + 1].size(); k++) {
            if (in[i + 1][k] != ':') {
              x++;
            } else
              break;
          }
          s2 = in[i + 1].substr(0, x);
        }
        string s3 = "";
        for (int j = 2; j < in[i].size(); j++) {
          if (isalpha(in[i][j]) || isdigit(in[i][j])) {
            s3 += in[i][j];
            if (j == in[i].size() - 1) {
              if (mp.find(s3) != mp.end()) {
                if (it->find(s3) == it->end()) {
                  it->insert({s3, 1});
                }
              }
            }
          } else {
            if (mp.find(s3) != mp.end()) {
              if (it->find(s3) == it->end()) {
                it->insert({s3, 1});
              }
            }
            s3 = "";
          }
        }
      }
    }
    bool ans = 0;
    int currcnt = -1;
    for (int cc = 1; cc <= 100; cc++) {
      it = st.begin();
      for (int i = 0; i < m; i++, it++) {
        if (in[i][0] != '?')
          continue;
        else {
          string s1, s2;
          s1 = s2 = "";
          if (i > 0) {
            int x = 0;
            for (int k = 0; k < in[i - 1].size(); k++) {
              if (in[i - 1][k] != ':') {
                x++;
              } else
                break;
            }
            s1 = in[i - 1].substr(0, x);
          }
          if (i < m - 1) {
            int x = 0;
            for (int k = 0; k < in[i + 1].size(); k++) {
              if (in[i + 1][k] != ':') {
                x++;
              } else
                break;
            }
            s2 = in[i + 1].substr(0, x);
          }
          int cnt = it->size();
          if (s1 != "" && s1 != "?") {
            if (it->find(s1) == it->end()) {
              it->insert({s1, 1});
              cnt++;
            }
          }
          if (s2 != "" && s2 != "?") {
            if (it->find(s2) == it->end()) {
              it->insert({s2, 1});
              cnt++;
            }
          }
          if (cnt == n - 1) {
            for (auto x : mp) {
              if (it->find(x.first) == it->end()) {
                in[i].erase(0, 1);
                in[i].insert(0, x.first);
                break;
              }
            }
          }
        }
      }
      int cnt2 = 0;
      for (int i = 0; i < m; i++) {
        if (in[i][0] != '?') cnt2++;
      }
      if (cnt2 == m) {
        ans = 1;
        break;
      }
      if (currcnt == cnt2) {
        break;
      }
      currcnt = cnt2;
    }
    if (!ans) {
      it = st.begin();
      for (int i = 0; i < m; i++) {
        if (in[i][0] != '?') continue;
        for (auto x : mp) {
          if (i > 0) {
            string s1;
            int x2 = 0;
            for (int k = 0; k < in[i - 1].size(); k++) {
              if (in[i - 1][k] != ':') {
                x2++;
              } else
                break;
            }
            s1 = in[i - 1].substr(0, x2);
            if (x.first == s1) continue;
          }
          if (i < m - 1) {
            string s1;
            int x2 = 0;
            for (int k = 0; k < in[i + 1].size(); k++) {
              if (in[i + 1][k] != ':') {
                x2++;
              } else
                break;
            }
            s1 = in[i + 1].substr(0, x2);
            if (x.first == s1) continue;
          }
          if (it->find(x.first) != it->end()) {
            continue;
          }
          in[i].erase(0, 1);
          in[i].insert(0, x.first);
          break;
        }
      }
      int cnt2 = 0;
      for (int i = 0; i < m; i++) {
        if (in[i][0] != '?')
          cnt2++;
        else
          break;
      }
      if (cnt2 == m) {
        ans = 1;
      }
      if (!ans)
        cout << "Impossible" << endl;
      else {
        for (int i = 0; i < in.size(); i++) {
          cout << in[i] << endl;
        }
      }
    } else {
      for (int i = 0; i < in.size(); i++) {
        cout << in[i] << endl;
      }
    }
  }
}
