#include <bits/stdc++.h>
using namespace std;
bool state[110];
string line[110];
vector<pair<char, int> > v[110];
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k && i - j >= 0; j++) {
      state[i] = state[i] || (state[i - j] ^ 1);
    }
  }
  bool alwayR = 0, alwayG = 0;
  int rem = 0;
  int cntR = 0, cntG = 0;
  for (int i = 0; i < n; i++) {
    cin >> line[i];
    for (int j = 0; j < m; j++) {
      if (line[i][j] != '-') {
        v[i].push_back(make_pair(line[i][j], j));
        if (line[i][j] == 'R')
          cntR++;
        else
          cntG++;
      }
    }
    if (v[i].size() == 1 ||
        (v[i].size() == 2 && v[i][0].first == v[i][1].first && m > 2)) {
      if (v[i][0].first == 'R')
        alwayR = 1;
      else
        alwayG = 1;
    }
    if (v[i].size() == 2) {
      if (v[i][0].first != v[i][1].first)
        if (v[i][1].second - v[i][0].second > 1) rem++;
    }
  }
  if (m == 1 || cntG == 0) {
    cout << "Second" << endl;
    return 0;
  }
  if (m == 2) {
    if (alwayR && alwayG) {
      cout << "Draw" << endl;
    } else if (alwayG) {
      cout << "First" << endl;
    } else {
      cout << "Second" << endl;
    }
    return 0;
  }
  if (alwayR && alwayG) {
    cout << "Draw" << endl;
  } else if (alwayG) {
    cout << "First" << endl;
  } else if (alwayR) {
    cout << "Second" << endl;
  } else {
    int sum[10];
    memset(sum, 0, sizeof(sum));
    for (int i = 0; i < n; i++) {
      if (v[i].size() == 2) {
        int d = v[i][1].second - v[i][0].second;
        for (int j = 0; j < 8; j++) {
          if ((1 << j) & d) sum[j]++;
        }
      }
    }
    for (int i = 0; i < 8; i++) {
      if (sum[i] % (k + 1) != 0) {
        printf("First\n");
        return 0;
      }
    }
    printf("Second\n");
    return 0;
  }
  return 0;
}
