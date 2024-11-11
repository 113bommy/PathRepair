#include <bits/stdc++.h>
using namespace std;
ifstream in("in.txt");
int main(int argc, char** argv) {
  int n, m, k;
  cin >> n >> m >> k;
  int B[n][n][m], C[n][m][3];
  memset(B, 0, sizeof(B));
  for (int i = 0; i < n; i++) {
    string wtf;
    cin >> wtf;
    for (int j = 0; j < m; j++) {
      cin >> C[i][j][0] >> C[i][j][1] >> C[i][j][2];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int c = 0; c < m; c++) {
        B[i][j][c] = C[i][c][1] - C[j][c][0];
        B[j][i][c] = C[j][c][1] - C[i][c][0];
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int temp = k, wtf = 0;
      vector<pair<int, int> > v;
      for (int c = 0; c < m; c++) {
        if (C[j][c][2] != 0)
          v.push_back(make_pair(B[i][j][c], min(k, C[j][c][2])));
      }
      sort(v.begin(), v.end(), greater<pair<int, int> >());
      int pP = 0;
      while (temp > 0 && pP < v.size() && v[pP].first > 0) {
        int t = min(temp, v[pP].second);
        wtf += t * v[pP].first;
        pP++;
        temp -= t;
      }
      ans = max(ans, wtf);
      temp = k, wtf = 0;
      v.assign(0, pair<int, int>());
      for (int c = 0; c < m; c++) {
        if (C[i][c][2] != 0)
          v.push_back(make_pair(B[j][i][c], min(k, C[i][c][2])));
      }
      sort(v.begin(), v.end(), greater<pair<int, int> >());
      pP = 0;
      while (temp > 0 && pP < v.size() && v[pP].first > 0) {
        int t = min(temp, v[pP].second);
        wtf += t * v[pP].first;
        pP++;
        temp -= t;
      }
      ans = max(ans, wtf);
    }
  }
  cout << ans;
  return 0;
}
