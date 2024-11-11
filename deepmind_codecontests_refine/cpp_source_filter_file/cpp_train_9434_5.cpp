#include <bits/stdc++.h>
const int max_n = 200000;
int n, m, k, st, sp;
int rank[max_n];
int assigned[max_n];
std::vector<int> dag[max_n];
std::vector<int> rev_dag[max_n];
int indeg[max_n];
int queue[max_n];
int level[max_n];
int min_required[max_n];
int max_allowed[max_n];
std::vector<std::pair<int, int> > levels_sorted;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin >> n >> m >> k;
  for (int i = 1; i <= k; ++i) {
    assigned[i] = 0;
  }
  for (int i = 0; i < n; ++i) {
    std::cin >> rank[i];
    indeg[i] = 0;
    level[i] = -1;
    min_required[i] = 0;
    max_allowed[i] = k;
    ++assigned[rank[i]];
  }
  for (int i = 0; i < m; ++i) {
    int u, v;
    std::cin >> u >> v;
    --u;
    --v;
    dag[v].push_back(u);
    rev_dag[u].push_back(v);
    ++indeg[u];
  }
  if (k > n) {
    std::cout << "-1" << std::endl;
  } else {
    st = sp = 0;
    for (int i = 0; i < n; ++i) {
      if (indeg[i] == 0) {
        queue[sp++] = i;
        level[i] = 1;
      }
    }
    while (st < sp) {
      int v = queue[st++];
      for (int i = 0; i < dag[v].size(); ++i) {
        level[dag[v][i]] = std::max(level[dag[v][i]], level[v] + 1);
        min_required[dag[v][i]] =
            std::max(min_required[dag[v][i]],
                     std::max(rank[v] + 1, min_required[v] + 1));
        if (--indeg[dag[v][i]] == 0) {
          queue[sp++] = dag[v][i];
        }
      }
    }
    if (sp != n || level[queue[n - 1]] > k) {
      std::cout << "-1" << std::endl;
    } else {
      bool rank_too_low = false;
      for (int i = 0; i < n; ++i) {
        if (rank[i] > 0 && rank[i] < level[i] || min_required[i] > k) {
          rank_too_low = true;
          break;
        }
      }
      if (rank_too_low) {
        std::cout << "-1" << std::endl;
      } else {
        for (int i = 0; i < n; ++i) {
          levels_sorted.push_back(
              std::make_pair(std::max(level[i], min_required[i]), i));
        }
        std::sort(levels_sorted.begin(), levels_sorted.end());
        int next_to_assign = k;
        while (next_to_assign > 0 && assigned[next_to_assign] > 0)
          --next_to_assign;
        for (int i = n - 1; i >= 0; --i) {
          int v = levels_sorted[i].second;
          int lvl = level[v];
          if (max_allowed[v] < min_required[v] || lvl > max_allowed[v]) break;
          if (rank[v] > 0 && rank[v] < min_required[v] ||
              rank[v] > max_allowed[v]) {
            std::cout << "-1";
            return 0;
          }
          if (rank[v] == 0) {
            for (int b = std::min(max_allowed[v], next_to_assign);
                 b >= std::max(lvl, min_required[v]); --b) {
              if (assigned[b] == 0) {
                rank[v] = b;
                break;
              }
            }
            if (rank[v] == 0) {
              rank[v] =
                  std::min(std::max(lvl, min_required[v]), max_allowed[v]);
            }
            ++assigned[rank[v]];
          }
          for (int j = 0; j < rev_dag[v].size(); ++j) {
            max_allowed[rev_dag[v][j]] =
                std::min(max_allowed[rev_dag[v][j]], rank[v] - 1);
            max_allowed[rev_dag[v][j]] =
                std::min(max_allowed[rev_dag[v][j]], k);
          }
          while (next_to_assign > 0 && assigned[next_to_assign] > 0)
            --next_to_assign;
        }
        if (next_to_assign > 0) {
          std::cout << "-1" << std::endl;
        } else {
          for (int i = 0; i < n; ++i) {
            std::cout << rank[i] << " ";
          }
          std::cout << std::endl;
        }
      }
    }
  }
  return 0;
}
