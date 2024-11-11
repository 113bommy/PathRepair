#include <bits/stdc++.h>
using namespace std;
string sn[60], sm[60];
int num[60][60];
map<string, int> mp;
int kn[110][60], km[110][60];
vector<pair<string, int> > ans;
int main() {
  for (int i = 0; i < (int)(60); i++) {
    for (int j = 0; j < (int)(60); j++) {
      num[i][j] = 0;
    }
  }
  for (int i = 0; i < (int)(110); i++) {
    for (int j = 0; j < (int)(60); j++) {
      kn[i][j] = km[i][j] = 0;
    }
  }
  int k, n, m, q;
  cin >> k >> n >> m >> q;
  for (int i = 0; i < (int)(n); i++) {
    cin >> sn[i];
    mp[sn[i]] = i;
  }
  for (int i = 0; i < (int)(m); i++) {
    cin >> sm[i];
    sm[i].resize(sm[i].size() - 1);
    bool b = 1;
    while (b) {
      string s;
      int N;
      char c;
      cin >> s >> N;
      scanf("%c", &c);
      b = (c == ',');
      num[i][mp[s]] = N;
    }
  }
  for (int i = 0; i < (int)(q); i++) {
    int N;
    string s;
    cin >> N >> s;
    N--;
    kn[N][mp[s]]++;
    for (int j = 0; j < (int)(m); j++) {
      bool can = 1;
      for (int l = 0; l < (int)(n); l++) {
        can &= kn[N][l] >= num[j][l];
      }
      if (can) {
        for (int l = 0; l < (int)(n); l++) {
          kn[N][l] -= num[j][l];
        }
        km[N][j]++;
      }
    }
  }
  for (int i = 0; i < (int)(k); i++) {
    ans.clear();
    for (int j = 0; j < (int)(n); j++) {
      if (kn[i][j]) {
        ans.push_back(make_pair(sn[j], kn[i][j]));
      }
    }
    for (int j = 0; j < (int)(m); j++) {
      if (km[i][j]) {
        ans.push_back(make_pair(sm[j], km[i][j]));
      }
    }
    sort(ans.begin(), ans.end());
    cout << i + 1 << endl;
    for (int j = 0; j < (int)(ans.size()); j++) {
      cout << ans[j].first << ' ' << ans[j].second << endl;
    }
  }
}
