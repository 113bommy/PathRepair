#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
ostream& operator<<(ostream& out, const pair<T, U>& val) {
  return out << "(" << val.first << ", " << val.second << ")";
}
template <class T>
ostream& operator<<(ostream& out, const vector<T>& val) {
  out << "{";
  for (int i = 0; i < (((int)(val).size())); i++)
    out << (i ? ", " : "") << val[i];
  return out << "}";
}
struct Mycomp {
  bool operator()(int a, int b) { return a > b; }
};
int n, m, k;
int vac[600];
vector<int> vac_index;
int ans[600][600];
long long path_cost[600][600];
int calc_index(int x) {
  if (x == 1) {
    return 1;
  }
  int lp = 0;
  int up = k + 1;
  while (lp != up) {
    int mid = (lp + up) / 2 + 1;
    if (x >= vac_index[mid]) {
      lp = mid;
    } else if (x < vac_index[mid]) {
      up = mid - 1;
    } else {
      return mid;
    }
  }
  return lp;
}
int par[100100];
int myrank[100100];
void init(int n) {
  for (int i = 0; i < (n); i++) {
    par[i] = i;
    myrank[i] = 0;
  }
}
int find(int x) {
  if (par[x] == x) {
    return x;
  } else {
    return par[x] = find(par[x]);
  }
}
void unite(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) {
    return;
  }
  if (myrank[x] < myrank[y]) {
    par[x] = y;
  } else {
    par[y] = x;
    if (myrank[x] == myrank[y]) {
      myrank[x] += 1;
    }
  }
}
bool same(int x, int y) { return find(x) == find(y); }
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> m >> k;
  init(n + 10);
  for (int i = 1; i < (k + 1); i++) {
    cin >> vac[i];
  }
  vac_index = vector<int>(k + 3);
  vac_index[1] = 1;
  for (int i = 2; i < (k + 2); i++) {
    vac_index[i] = vac_index[i - 1] + vac[i - 1];
  }
  for (int i = 1; i < (k + 1); i++) {
    for (int j = 1; j < (k + 1); j++) {
      path_cost[i][j] = 1070000000LL;
    }
  }
  for (int i = 1; i < (k + 1); i++) {
    path_cost[i][i] = 0;
  }
  for (int i = 0; i < (m); i++) {
    int u, v, x;
    cin >> u >> v >> x;
    if (x == 0) {
      unite(u, v);
    }
    int in1 = calc_index(u);
    int in2 = calc_index(v);
    path_cost[in1][in2] = min((long long)x, path_cost[in1][in2]);
    path_cost[in2][in1] = min((long long)x, path_cost[in2][in1]);
  }
  bool NO_flag = false;
  for (int i = 1; i < (k + 1); i++) {
    for (int j = vac_index[i] + 1; j < (vac_index[i + 1]); j++) {
      if (!same(vac_index[i], j)) {
        NO_flag = true;
        break;
      }
    }
    if (NO_flag) {
      break;
    }
  }
  if (NO_flag) {
    cout << "No\n";
    return 0;
  }
  for (int i = 1; i < (k + 1); i++) {
    for (int j = 1; j < (k + 1); j++) {
      for (int l = 1; l < (k + 1); l++) {
        path_cost[j][l] =
            min(path_cost[j][l], path_cost[j][i] + path_cost[i][l]);
      }
    }
  }
  cout << "Yes\n";
  for (int i = 1; i < (k + 1); i++) {
    for (int j = 1; j < (k + 1); j++) {
      if (path_cost[i][j] == 1070000000LL) {
        cout << -1 << " ";
      } else {
        cout << path_cost[i][j] << " ";
      }
    }
    cout << endl;
  }
  return 0;
}
