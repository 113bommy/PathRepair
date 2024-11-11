#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N];
int col[N];
vector<pair<int, int> > S[N];
vector<int> C[N];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int n_s = 0;
  S[n_s++].push_back(make_pair(0, -1));
  for (int i = 1; i < n; i++) {
    int lo = 0, hi = n_s - 1, res = -1;
    while (lo <= hi) {
      int mid = (lo + hi) >> 1;
      if (a[S[mid].back().first] >= a[i])
        res = mid, hi = mid - 1;
      else
        lo = mid + 1;
    }
    if (res == -1) {
      S[n_s].push_back(make_pair(i, (int)(S[n_s - 1].size()) - 1));
      ++n_s;
    } else {
      S[res].push_back(
          make_pair(i, (res > 0 ? (int)(S[res - 1].size()) - 1 : -1)));
    }
  }
  for (int i = 0; i < n_s; i++) {
    C[i].resize((int)(S[i].size()) + 5, 0);
  }
  C[n_s - 1][0]++;
  C[n_s - 1][(int)(S[n_s - 1].size())]--;
  for (int i = n_s - 1; i >= 0; i--) {
    for (int j = 1; j < (int)(C[i].size()); j++) {
      C[i][j] += C[i][j - 1];
    }
    int cnt_pos = 0;
    for (int j = 0; j < (int)(C[i].size()); j++) {
      if (C[i][j] > 0) {
        ++cnt_pos;
      }
    }
    for (int j = 0; j < (int)(S[i].size()); j++) {
      if (C[i][j] > 0) {
        col[S[i][j].first] = (cnt_pos == 1 ? 3 : 2);
      } else {
        col[S[i][j].first] = 1;
      }
    }
    if (i > 0) {
      for (int j = 0; j < (int)(S[i].size()); j++) {
        if (C[i][j] == 0) continue;
        int now_val = a[S[i][j].first];
        int lo = 0, hi = S[i][j].second, res = -1;
        while (lo <= hi) {
          int mid = (lo + hi) >> 1;
          if (a[S[i - 1][mid].first] < now_val)
            res = mid, hi = mid - 1;
          else
            lo = mid + 1;
        }
        ++C[i - 1][res];
        --C[i - 1][S[i][j].second + 1];
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << col[i];
  }
  cout << '\n';
  return 0;
}
