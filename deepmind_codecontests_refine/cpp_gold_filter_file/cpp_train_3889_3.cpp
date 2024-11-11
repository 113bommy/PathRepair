#include <bits/stdc++.h>
using namespace std;
long long now_max1 = 1000000000;
int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int> > Lev(N);
  for (int i = 0; i < N; ++i) {
    Lev[i].resize(M);
  }
  vector<long long> stroc(N, 0);
  vector<long long> stolb(M, 0);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> Lev[i][j];
      stroc[i] += Lev[i][j];
      stolb[j] += Lev[i][j];
    }
  }
  long long now_max1 = 1000000000;
  now_max1 *= now_max1;
  long long cur = 0;
  int tec = -1;
  for (int i = 0; i <= N; ++i) {
    for (int j = 0; j < N; ++j) {
      cur += stroc[j] * (4 * abs(j - i) + 2 * (i <= j) - 2 * (i > j)) *
             (4 * abs(i - j) + 2 * (i <= j) - 2 * (i > j));
    }
    if (cur < now_max1) {
      tec = i;
      now_max1 = cur;
    }
    cur = 0;
  }
  long long now_max2 = 1000000000;
  now_max2 *= now_max2;
  int tec2 = -1;
  for (int i = 0; i <= M; ++i) {
    for (int j = 0; j < M; ++j) {
      cur += stolb[j] * (4 * abs(j - i) + 2 * (i <= j) - 2 * (i > j)) *
             (4 * abs(i - j) + 2 * (i <= j) - 2 * (i > j));
    }
    if (cur < now_max2) {
      tec2 = i;
      now_max2 = cur;
    }
    cur = 0;
  }
  cout << now_max1 + now_max2;
  cout << endl;
  cout << tec << " " << tec2;
  return 0;
}
