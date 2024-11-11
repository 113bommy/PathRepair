#include <bits/stdc++.h>
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c* x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug& operator<<(const c&) {
    return *this;
  }
};
const int nax = 15123;
const int INF = 1e9 + 5;
vector<pair<int, int>> edges[nax];
int kol[nax];
vector<int> path[3];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    edges[a].emplace_back(b, i);
    edges[b].emplace_back(a, i);
  }
  vector<int> me;
  srand(6969);
  me.push_back(1 + rand() % n);
  for (int rep = 0; rep < 2; ++rep) {
    vector<int> dist(n + 1, INF);
    int kol_size = 0;
    for (int x : me) {
      kol[kol_size++] = x;
      dist[x] = 0;
    }
    for (int i = 0; i < kol_size; ++i) {
      int a = kol[i];
      for (const pair<int, int>& edge : edges[a]) {
        int b = edge.first;
        if (dist[b] == INF) {
          dist[b] = dist[a] + 1;
          kol[kol_size++] = b;
        }
      }
    }
    int best = -1;
    for (int a = 1; a <= n; ++a) {
      if (best == -1 || dist[a] > dist[best]) {
        best = a;
      }
    }
    assert(best != -1);
    me.push_back(best);
  }
  cout << me[0] << " " << me[1] << " " << me[2] << endl;
  int enemy;
  cin >> enemy;
  auto is_done = [&]() {
    return me[0] == enemy || me[1] == enemy || me[2] == enemy;
  };
  vector<int> used(m + 1);
  for (int turn = 1; turn <= (n >= 100 ? n - 1 : n); ++turn) {
    cerr << "turn = " << turn << endl;
    if (is_done()) {
      return 0;
    }
    vector<int> dist(n + 1, INF);
    {
      int kol_size = 0;
      kol[kol_size++] = enemy;
      dist[enemy] = 0;
      for (int i = 0;
           i < kol_size &&
           (dist[me[0]] == INF || dist[me[1]] == INF || dist[me[2]] == INF);
           ++i) {
        int a = kol[i];
        for (const pair<int, int>& edge : edges[a]) {
          int b = edge.first;
          if (dist[b] == INF) {
            dist[b] = dist[a] + 1;
            kol[kol_size++] = b;
          }
        }
      }
    }
    vector<int> order{0, 1, 2};
    sort(order.begin(), order.end(),
         [&](int a, int b) { return dist[a] < dist[b]; });
    int tu_turn = -1;
    for (int which : order) {
      int& start = me[which];
      if (rand() % 10 == 0 && n >= 100) {
        start = edges[start][rand() % edges[start].size()].first;
        continue;
      }
      tu_turn++;
      for (int rep = 0; rep < 2; ++rep) {
        if (tu_turn != 0) {
          for (int& x : dist) {
            x = INF;
          }
          int kol_size = 0;
          kol[kol_size++] = enemy;
          dist[enemy] = 0;
          for (int i = 0; i < kol_size && dist[start] == INF; ++i) {
            int a = kol[i];
            for (const pair<int, int>& edge : edges[a]) {
              int b = edge.first;
              int id = edge.second;
              if ((rep == 1 || used[id] != turn) && dist[b] == INF) {
                dist[b] = dist[a] + 1;
                kol[kol_size++] = b;
              }
            }
          }
        }
        if (dist[start] != INF) {
          int tmp = start;
          int first_move = -1;
          while (tmp != enemy) {
            if (which == 2 && first_move != -1) {
              break;
            }
            bool done = false;
            debug();
            for (const pair<int, int>& e : edges[tmp]) {
              int b = e.first;
              int id = e.second;
              debug() << " ["
                      << "rep"
                         ": "
                      << (rep)
                      << "] "
                         " ["
                      << "b"
                         ": "
                      << (b)
                      << "] "
                         " ["
                      << "id"
                         ": "
                      << (id)
                      << "] "
                         " ["
                      << "used[id]"
                         ": "
                      << (used[id])
                      << "] "
                         " ["
                      << "dist[b]"
                         ": "
                      << (dist[b])
                      << "] "
                         " ["
                      << "dist[tmp]"
                         ": "
                      << (dist[tmp]) << "] ";
              if (rep == 0 && used[id] == turn) {
                continue;
              }
              if (dist[b] + 1 == dist[tmp]) {
                used[id] = turn;
                tmp = b;
                if (first_move == -1) {
                  first_move = b;
                } else {
                }
                done = true;
                break;
              }
            }
            assert(done);
          }
          assert(first_move != -1);
          start = first_move;
          break;
        }
        assert(rep != 1);
      }
    }
    cout << me[0] << " " << me[1] << " " << me[2] << endl;
    if (is_done()) {
      return 0;
    }
    cin >> enemy;
    if (is_done()) {
      return 0;
    }
  }
  assert(false);
}
