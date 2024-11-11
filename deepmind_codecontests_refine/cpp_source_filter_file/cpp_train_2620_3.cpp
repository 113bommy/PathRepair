#include <bits/stdc++.h>
using namespace std;
inline long long mod(long long n, long long m) {
  long long ret = n % m;
  if (ret < 0) ret += m;
  return ret;
}
long long gcd(long long a, long long b) {
  return (b == 0LL ? a : gcd(b, a % b));
}
long long exp(long long a, long long b, long long m) {
  if (b == 0LL) return 1LL;
  if (b == 1LL) return mod(a, m);
  long long k = mod(exp(a, b / 2, m), m);
  if (b & 1LL) {
    return mod(a * mod(k * k, m), m);
  } else
    return mod(k * k, m);
}
const int N = 100100;
int mat[N][2][2];
void solve(vector<set<pair<int, int>>>& vs) {
  if ((int)vs[0].size() == 1) return;
  vector<int> big(4, -1e9);
  set<pair<int, int>>::iterator it[4];
  for (int j = 0; j < 4; j++) {
    it[j] = vs[j].begin();
  }
  int here = -1;
  int op = 0;
  for (; it[0] != vs[0].end();) {
    op++;
    for (int j = 0; j < 4; j++) {
      if (j >= 2) {
        big[j] = max(big[j], -mat[it[j]->second][0][j & 1]);
        it[j]++;
      } else {
        big[j] = max(big[j], mat[it[j]->second][1][j & 1]);
        it[j]++;
      }
    }
    if (it[0] == vs[0].end()) break;
    for (int j = 0; j < 4; j++) {
      if (j >= 2) {
        if (it[j]->first <= big[j]) {
          here = j;
          break;
        }
      } else {
        if (big[j] <= it[j]->first) {
          here = j;
          break;
        }
      }
    }
    if (here != -1) break;
  }
  if (here == -1) {
    cout << "NO"
         << "\n";
    exit(0);
  }
  vector<set<pair<int, int>>> novo(4, set<pair<int, int>>());
  set<pair<int, int>>::iterator it2 = vs[here].begin();
  vector<int> ids;
  while (it2 != it[here]) {
    int id = it2->second;
    it2++;
    for (int j = 0; j < 4; j++) {
      if (j < 2) {
        novo[j].insert(pair<int, int>(mat[id][j >> 1][j & 1], id));
        vs[j].erase(pair<int, int>(mat[id][j >> 1][j & 1], id));
      } else {
        novo[j].insert(pair<int, int>(-mat[id][j >> 1][j & 1], id));
        vs[j].erase(pair<int, int>(-mat[id][j >> 1][j & 1], id));
      }
    }
  }
  solve(novo);
  solve(vs);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        cin >> mat[i][j][k];
      }
    }
  }
  vector<set<pair<int, int>>> vs(4, set<pair<int, int>>());
  for (int j = 0; j < 4; j++) {
    for (int i = 1; i <= n; i++) {
      if (j < 2)
        vs[j].insert(pair<int, int>(mat[i][j >> 1][j & 1], i));
      else
        vs[j].insert(pair<int, int>(-mat[i][j >> 1][j & 1], i));
    }
  }
  solve(vs);
  cout << "YES"
       << "\n";
  return 0;
}
