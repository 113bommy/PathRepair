#include <bits/stdc++.h>
using namespace std;
const long long MAX = 2000;
string A[MAX];
string B[MAX];
set<long long> fila[27];
set<long long> col[27];
void doit() {
  for (long long k = 0; k < (long long)26; k++) {
    fila[k].clear();
    col[k].clear();
  }
  long long n, m;
  cin >> n >> m;
  bool fullEmpty = true;
  for (long long i = 0; i < (long long)n; i++) {
    cin >> A[i];
    B[i] = A[i];
    for (long long j = 0; j < (long long)m; j++) {
      if (A[i][j] != '.') {
        fullEmpty = false;
        break;
      }
    }
  }
  if (fullEmpty) {
    cout << "YES\n0\n";
    return;
  }
  long long maxLet = -1;
  vector<pair<long long, long long> > inicio(26, {-1, -1});
  vector<pair<long long, long long> > fin(26, {-1, -1});
  for (long long let = 0; let < (long long)26; let++) {
    for (long long i = 0; i < (long long)n; i++) {
      for (long long j = 0; j < (long long)m; j++) {
        if (A[i][j] - 'a' == let) {
          fila[let].insert(i);
          col[let].insert(j);
          maxLet = let;
        }
      }
    }
    if (fila[let].size() > 1 && col[let].size() > 1) {
      cout << "NO\n";
      return;
    }
    if (fila[let].size() > 0) {
      auto itf = fila[let].begin();
      auto itc = col[let].begin();
      inicio[let] = {*itf, *itc};
      itf = fila[let].end();
      itc = col[let].end();
      itf--;
      itc--;
      fin[let] = {*itf, *itc};
    }
  }
  for (long long i = 0; i < (long long)n; i++) {
    for (long long j = 0; j < (long long)m; j++) {
      B[i][j] = '.';
    }
  }
  for (long long let = 0; let < (long long)maxLet + 1; let++) {
    if (fila[let].size() == 0) {
      auto itf = fila[maxLet].begin();
      auto itc = col[maxLet].end();
      inicio[let] = {*itf, *itc};
      fin[let] = {*itf, *itc};
    }
  }
  for (long long let = 0; let < (long long)maxLet + 1; let++) {
    pair<long long, long long> cur = inicio[let];
    assert(cur.first != -1);
    char c = let + 'a';
    while (cur != fin[let]) {
      B[cur.first][cur.second] = c;
      if (inicio[let].first == fin[let].first) {
        cur.second++;
      } else {
        cur.first++;
      }
    }
    B[cur.first][cur.second] = c;
  }
  for (long long i = 0; i < (long long)n; i++) {
    for (long long j = 0; j < (long long)m; j++) {
      if (A[i][j] != B[i][j]) {
        cout << "NO\n";
        return;
      }
    }
  }
  cout << "YES\n";
  cout << maxLet + 1 << "\n";
  for (long long i = 0; i < (long long)maxLet + 1; i++) {
    cout << inicio[i].first + 1 << " " << inicio[i].second + 1 << " "
         << fin[i].first + 1 << " " << fin[i].second + 1 << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long T;
  cin >> T;
  for (long long t = 0; t < (long long)T; t++) {
    doit();
  }
  return 0;
}
