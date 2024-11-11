#include <bits/stdc++.h>
using namespace std;
int const MAX = 41;
int n;
int a[MAX];
int mat[5][5];
void kill(int mat[5][5]) {
  int s = 0;
  for (int i = 1; i <= n; i++) {
    s += mat[1][i];
  }
  printf("%d\n", s);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      printf("%d ", mat[i][j]);
    }
    printf("\n");
  }
  exit(0);
}
void brute() {
  vector<pair<int, int> > per;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      per.push_back(make_pair(i, j));
    }
  }
  do {
    for (int i = 1; i <= n * n; i++) {
      int x = per[i - 1].first;
      int y = per[i - 1].second;
      mat[x][y] = a[i];
    }
    set<int> t;
    for (int i = 1; i <= n; i++) {
      int s = 0;
      for (int j = 1; j <= n; j++) {
        s += mat[i][j];
      }
      t.insert(s);
    }
    for (int i = 1; i <= n; i++) {
      int s = 0;
      for (int j = 1; j <= n; j++) {
        s += mat[j][i];
      }
      t.insert(s);
    }
    int s = 0;
    for (int i = 1; i <= n; i++) {
      s += mat[i][i];
    }
    t.insert(s);
    s = 0;
    for (int i = 1; i <= n; i++) {
      s += mat[i][n - i + 1];
    }
    t.insert(s);
    if ((int)t.size() == 1) {
      kill(mat);
    }
  } while (next_permutation(per.begin(), per.end()));
  assert(false);
}
int qbit(int mask) { return __builtin_popcount(mask); }
bool bit(int m, int i) { return (1 & (m >> i)); }
int mata[5][5];
int matb[5][5];
void trysolve(vector<int> a, vector<int> b, int need) {
  vector<pair<int, int> > per;
  vector<vector<int> > statesa;
  map<vector<int>, vector<pair<int, int> > > pers;
  for (int i = 1; i <= 2; i++) {
    for (int j = 1; j <= 4; j++) {
      per.push_back(make_pair(i, j));
    }
  }
  do {
    for (int i = 0; i <= (int)per.size() - 1; i++) {
      int x = per[i].first;
      int y = per[i].second;
      mata[x][y] = a[i];
    }
    int s = 0;
    for (int i = 1; i <= 4; i++) {
      s += mata[1][i];
    }
    if (s != need) continue;
    vector<int> v;
    for (int i = 1; i <= 4; i++) {
      int s = mata[1][i] + mata[2][i];
      v.push_back(s);
    }
    v.push_back(mata[1][1] + mata[2][2]);
    v.push_back(mata[1][4] + mata[2][3]);
    pers[v] = per;
    statesa.push_back(v);
  } while (next_permutation(per.begin(), per.end()));
  sort(statesa.begin(), statesa.end());
  sort(per.begin(), per.end());
  do {
    for (int i = 0; i <= (int)per.size() - 1; i++) {
      int x = per[i].first;
      int y = per[i].second;
      matb[x][y] = b[i];
    }
    int s = 0;
    for (int i = 1; i <= 4; i++) {
      s += matb[1][i];
    }
    if (s != need) continue;
    vector<int> needv;
    for (int i = 1; i <= 4; i++) {
      int s = matb[1][i] + matb[2][i];
      needv.push_back(need - s);
    }
    needv.push_back(need - (matb[1][1] + matb[2][2]));
    needv.push_back(need - (matb[1][4] + matb[2][3]));
    auto it = lower_bound(statesa.begin(), statesa.end(), needv);
    if (it == statesa.end()) continue;
    if ((*it) != needv) continue;
    vector<pair<int, int> > pera = pers[needv];
    for (int i = 0; i <= (int)pera.size() - 1; i++) {
      int x = pera[i].first;
      int y = pera[i].second;
      mata[x][y] = a[i];
    }
    printf("%d\n", need);
    for (int i = 1; i <= 2; i++) {
      for (int j = 1; j <= 4; j++) {
        printf("%d ", mata[i][j]);
      }
      printf("\n");
    }
    for (int i = 1; i <= 2; i++) {
      for (int j = 1; j <= 4; j++) {
        printf("%d ", matb[i][j]);
      }
      printf("\n");
    }
    exit(0);
  } while (next_permutation(per.begin(), per.end()));
}
void solve() {
  if (n <= 3) {
    brute();
    return;
  }
  int s = 0;
  for (int i = 1; i <= n * n; i++) {
    s += a[i];
  }
  assert(s % 4 == 0);
  int need = s / 4;
  for (int mask = 0; mask < (1 << 16); mask++) {
    if (qbit(mask) != 8) continue;
    vector<int> va, vb;
    for (int i = 1; i <= n * n; i++) {
      if (bit(mask, i - 1)) {
        va.push_back(a[i]);
      } else {
        vb.push_back(a[i]);
      }
    }
    int s = 0;
    for (int x : va) {
      s += x;
    }
    if (s != need * 2) continue;
    trysolve(va, vb, need);
  }
  assert(false);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n * n; i++) {
    scanf("%d", &a[i]);
  }
  solve();
  return 0;
}
