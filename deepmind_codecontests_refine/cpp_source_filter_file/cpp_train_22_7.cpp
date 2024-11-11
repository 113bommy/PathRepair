#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
template <typename T>
void DBG(const char* name, T&& H) {
  cerr << name << " = " << H << ')' << '\n';
}
template <typename T, typename... Args>
void DBG(const char* names, T&& H, Args&&... args) {
  const char* NEXT = strchr(names + 1, ',');
  cerr.write(names, NEXT - names) << " = " << H << " |";
  DBG(NEXT + 1, args...);
}
using ll = long long;
using ld = long double;
const ll mod = 1e9 + 7;
const ld PI = acos(-1.0);
const ll maxN = 1e5 + 1;
struct Hungarian {
  using T = int;
  int N;
  vector<vector<T>> cost;
  vector<int> Lmate, Rmate;
  T minCost = 0;
  Hungarian(int n = 1e2) {
    N = n;
    cost.resize(n, vector<T>(n));
    Lmate.resize(n, -1);
    Rmate.resize(n, -1);
  }
  void compute() {
    vector<T> a(N), b(N);
    for (int i = 0; i < N; i++) {
      a[i] = cost[i][0];
      for (int j = 1; j < N; j++) {
        a[i] = min(a[i], cost[i][j]);
      }
    }
    for (int i = 0; i < N; i++) {
      b[i] = cost[0][i] - a[i];
      for (int j = 1; j < N; j++) {
        b[i] = min(b[i], cost[j][i] - a[j]);
      }
    }
    int matched = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (Rmate[j] != -1) continue;
        if (abs(cost[i][j] - a[i] - b[j]) == 0) {
          Lmate[i] = j;
          Rmate[j] = i;
          matched++;
          break;
        }
      }
    }
    vector<T> dist(N);
    vector<int> dad(N), seen(N);
    while (matched < N) {
      int s = 0;
      while (Lmate[s] != -1) s++;
      fill(dad.begin(), dad.end(), -1);
      fill(seen.begin(), seen.end(), 0);
      for (int k = 0; k < N; k++) {
        dist[k] = cost[s][k] - a[s] - b[k];
      }
      int j = 0;
      while (true) {
        j = -1;
        for (int k = 0; k < N; k++) {
          if (seen[k]) continue;
          if ((j == -1) || (dist[k] < dist[j])) j = k;
        }
        seen[j] = 1;
        if (Rmate[j] == -1) break;
        int i = Rmate[j];
        for (int k = 0; k < N; k++) {
          if (seen[k]) continue;
          int newDist = dist[j] + cost[i][k] - a[i] - b[k];
          if (dist[k] > newDist) {
            dist[k] = newDist;
            dad[k] = j;
          }
        }
      }
      for (int k = 0; k < N; k++) {
        if ((k == j) || (!seen[k])) continue;
        int i = Rmate[k];
        a[i] -= dist[k] - dist[j];
        b[k] += dist[k] - dist[j];
      }
      a[s] += dist[j];
      while (dad[j] >= 0) {
        int d = dad[j];
        Rmate[j] = Rmate[d];
        Lmate[Rmate[j]] = j;
        j = d;
      }
      Rmate[j] = s;
      Lmate[s] = j;
      matched++;
    }
    for (int i = 0; i < N; i++) {
      minCost += cost[i][Lmate[i]];
    }
  }
};
void Solve() {
  int n, k;
  cin >> n >> k;
  Hungarian order(n);
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k - 1; j++) {
      order.cost[i][j] = -(a[i] + j * b[i]);
    }
    for (int j = k - 1; j < n - 1; j++) {
      order.cost[i][j] = -((k - 1) * b[i]);
    }
    order.cost[i][n - 1] = -(a[i] + (k - 1) * b[i]);
  }
  order.compute();
  cout << k + 2 * (n - k) << '\n';
  for (int i = 0; i < k - 1; i++) {
    cout << order.Rmate[i] + 1 << " ";
  }
  for (int i = k - 1; i < n - 1; i++) {
    cout << order.Rmate[i] + 1 << " " << -(order.Rmate[i] + 1) << " ";
  }
  cout << order.Rmate[n - 1] + 1 << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tt = 1;
  cin >> tt;
  while (tt--) {
    Solve();
  }
  return 0;
}
