#include <bits/stdc++.h>
using namespace std;
int n_comp = 0, n_free = 0, total = 0, Max = 0;
bool visited[600][600];
char board[600][600];
int comp[600][600], n, k, contribution[260000], size_comp[260000];
void create_comp(int i, int j) {
  if (visited[i][j])
    return;
  else if (board[i][j] == 'X') {
    comp[i][j] = -1;
    return;
  } else {
    queue<pair<int, int> > m_q;
    m_q.push(pair<int, int>(i, j));
    visited[i][j] = true;
    int m_size = 0;
    while (!m_q.empty()) {
      pair<int, int> m_p = m_q.front();
      m_q.pop();
      m_size++;
      i = m_p.first;
      j = m_p.second;
      comp[i][j] = n_comp;
      if (i > 0 && !visited[i - 1][j] && board[i - 1][j] == '.') {
        m_q.push(pair<int, int>(i - 1, j));
        visited[i - 1][j] = true;
      }
      if (i < n - 1 && !visited[i + 1][j] && board[i + 1][j] == '.') {
        m_q.push(pair<int, int>(i + 1, j));
        visited[i + 1][j] = true;
      }
      if (j > 0 && !visited[i][j - 1] && board[i][j - 1] == '.') {
        m_q.push(pair<int, int>(i, j - 1));
        visited[i][j - 1] = true;
      }
      if (j < n - 1 && !visited[i][j + 1] && board[i][j + 1] == '.') {
        m_q.push(pair<int, int>(i, j + 1));
        visited[i][j + 1] = true;
      }
    }
    size_comp[n_comp] = m_size;
    n_comp++;
  }
}
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n + 2; i++)
    board[i][0] = board[i][n + 1] = board[0][i] = board[n + 1][i] = 'X';
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) scanf(" %c", &board[i][j]);
  n += 2;
  k += 2;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) create_comp(i, j);
  if (k == n)
    printf("%d\n", (k - 2) * (k - 2));
  else {
    for (int i = 0; i < k; i++)
      for (int j = 0; j < k; j++)
        if (comp[i][j] != -1) {
          if (contribution[comp[i][j]] == 0) total += size_comp[comp[i][j]];
          contribution[comp[i][j]]++;
          if (i > 0 && i < k - 1 && j > 0 && j < k - 1) n_free++;
        }
    if (comp[k - 1][k - 1] != -1) {
      if (contribution[comp[k - 1][k - 1]] == 1)
        total -= size_comp[comp[k - 1][k - 1]];
      contribution[comp[k - 1][k - 1]]--;
    }
    Max = total + (k - 2) * (k - 2) - n_free;
    for (int i = 0; i <= n - k; i++) {
      if (i % 2 == 0) {
        for (int j = 0; j < n - k; j++) {
          if (comp[i][j] != -1) {
            if (contribution[comp[i][j]] == 0) total += size_comp[comp[i][j]];
            contribution[comp[i][j]]++;
          }
          if (comp[i + k - 1][j] != -1) {
            if (contribution[comp[i + k - 1][j]] == 0)
              total += size_comp[comp[i + k - 1][j]];
            contribution[comp[i + k - 1][j]]++;
          }
          if (comp[i][j + k - 1] != -1) {
            if (contribution[comp[i][j + k - 1]] == 0)
              total += size_comp[comp[i][j + k - 1]];
            contribution[comp[i][j + k - 1]]++;
          }
          if (comp[i + k - 1][j + k - 1] != -1) {
            if (contribution[comp[i + k - 1][j + k - 1]] == 0)
              total += size_comp[comp[i + k - 1][j + k - 1]];
            contribution[comp[i + k - 1][j + k - 1]]++;
          }
          for (int l = 0; l < k; l++)
            if (comp[i + l][j] != -1) {
              if (contribution[comp[i + l][j]] == 1)
                total -= size_comp[comp[i + l][j]];
              contribution[comp[i + l][j]]--;
            }
          for (int l = 0; l < k; l++) {
            if (comp[i + l][j + k] != -1) {
              if (contribution[comp[i + l][j + k]] == 0)
                total += size_comp[comp[i + l][j + k]];
              contribution[comp[i + l][j + k]]++;
            }
          }
          if (comp[i][j + 1] != -1) {
            if (contribution[comp[i][j + 1]] == 1)
              total -= size_comp[comp[i][j + 1]];
            contribution[comp[i][j + 1]]--;
          }
          if (comp[i + k - 1][j + 1] != -1) {
            if (contribution[comp[i + k - 1][j + 1]] == 1)
              total -= size_comp[comp[i + k - 1][j + 1]];
            contribution[comp[i + k - 1][j + 1]]--;
          }
          if (comp[i][j + k] != -1) {
            if (contribution[comp[i][j + k]] == 1)
              total -= size_comp[comp[i][j + k]];
            contribution[comp[i][j + k]]--;
          }
          if (comp[i + k - 1][j + k] != -1) {
            if (contribution[comp[i + k - 1][j + k]] == 1)
              total -= size_comp[comp[i + k - 1][j + k]];
            contribution[comp[i + k - 1][j + k]]--;
          }
          for (int l = 1; l < k - 1; l++) {
            if (board[i + l][j + 1] == '.') n_free--;
            if (board[i + l][j + k - 1] == '.') n_free++;
          }
          Max = max(Max, total + (k - 2) * (k - 2) - n_free);
        }
        if (comp[i][n - k] != -1) {
          if (contribution[comp[i][n - k]] == 0)
            total += size_comp[comp[i][n - k]];
          contribution[comp[i][n - k]]++;
        }
        if (comp[i][n - 1] != -1) {
          if (contribution[comp[i][n - 1]] == 0)
            total += size_comp[comp[i][n - 1]];
          contribution[comp[i][n - 1]]++;
        }
        if (comp[i + k - 1][n - k] != -1) {
          if (contribution[comp[i + k - 1][n - k]] == 0)
            total += size_comp[comp[i + k - 1][n - k]];
          contribution[comp[i + k - 1][n - k]]++;
        }
        if (comp[i + k - 1][n - 1] != -1) {
          if (contribution[comp[i + k - 1][n - 1]] == 0)
            total += size_comp[comp[i + k - 1][n - 1]];
          contribution[comp[i + k - 1][n - 1]]++;
        }
        for (int l = 0; l < k; l++)
          if (comp[i][n - k + l] != -1) {
            if (contribution[comp[i][n - k + l]] == 1)
              total -= size_comp[comp[i][n - k + l]];
            contribution[comp[i][n - k + l]]--;
          }
        for (int l = 0; l < k; l++) {
          if (comp[i + k][n - k + l] != -1) {
            if (contribution[comp[i + k][n - k + l]] == 0)
              total += size_comp[comp[i + k][n - k + l]];
            contribution[comp[i + k][n - k + l]]++;
          }
        }
        if (comp[i + 1][n - k] != -1) {
          if (contribution[comp[i + 1][n - k]] == 1)
            total -= size_comp[comp[i + 1][n - k]];
          contribution[comp[i + 1][n - k]]--;
        }
        if (comp[i + 1][n - 1] != -1) {
          if (contribution[comp[i + 1][n - 1]] == 1)
            total -= size_comp[comp[i + 1][n - 1]];
          contribution[comp[i + 1][n - 1]]--;
        }
        if (comp[i + k][n - k] != -1) {
          if (contribution[comp[i + k][n - k]] == 1)
            total -= size_comp[comp[i + k][n - k]];
          contribution[comp[i + k][n - k]]--;
        }
        if (comp[i + k][n - 1] != -1) {
          if (contribution[comp[i + k][n - 1]] == 1)
            total -= size_comp[comp[i + k][n - 1]];
          contribution[comp[i + k][n - 1]]--;
        }
        for (int l = 1; l < k - 1; l++) {
          if (board[i + 1][n - k + l] == '.') n_free--;
          if (board[i + k - 1][n - k + l] == '.') n_free++;
        }
        if (i != n - k) Max = max(Max, total + (k - 2) * (k - 2) - n_free);
      } else {
        for (int j = n - k; j > 0; j--) {
          if (comp[i][j] != -1) {
            if (contribution[comp[i][j]] == 0) total += size_comp[comp[i][j]];
            contribution[comp[i][j]]++;
          }
          if (comp[i + k - 1][j] != -1) {
            if (contribution[comp[i + k - 1][j]] == 0)
              total += size_comp[comp[i + k - 1][j]];
            contribution[comp[i + k - 1][j]]++;
          }
          if (comp[i][j + k - 1] != -1) {
            if (contribution[comp[i][j + k - 1]] == 0)
              total += size_comp[comp[i][j + k - 1]];
            contribution[comp[i][j + k - 1]]++;
          }
          if (comp[i + k - 1][j + k - 1] != -1) {
            if (contribution[comp[i + k - 1][j + k - 1]] == 0)
              total += size_comp[comp[i + k - 1][j + k - 1]];
            contribution[comp[i + k - 1][j + k - 1]]++;
          }
          for (int l = 0; l < k; l++) {
            if (comp[i + l][j + k - 1] != -1) {
              if (contribution[comp[i + l][j + k - 1]] == 1)
                total -= size_comp[comp[i + l][j + k - 1]];
              contribution[comp[i + l][j + k - 1]]--;
            }
          }
          for (int l = 0; l < k; l++)
            if (comp[i + l][j - 1] != -1) {
              if (contribution[comp[i + l][j - 1]] == 0)
                total += size_comp[comp[i + l][j - 1]];
              contribution[comp[i + l][j - 1]]++;
            }
          if (comp[i][j - 1] != -1) {
            if (contribution[comp[i][j - 1]] == 1)
              total -= size_comp[comp[i][j - 1]];
            contribution[comp[i][j - 1]]--;
          }
          if (comp[i + k - 1][j - 1] != -1) {
            if (contribution[comp[i + k - 1][j - 1]] == 1)
              total -= size_comp[comp[i + k - 1][j - 1]];
            contribution[comp[i + k - 1][j - 1]]--;
          }
          if (comp[i][j + k - 1 - 1] != -1) {
            if (contribution[comp[i][j + k - 1 - 1]] == 1)
              total -= size_comp[comp[i][j + k - 1 - 1]];
            contribution[comp[i][j + k - 1 - 1]]--;
          }
          if (comp[i + k - 1][j + k - 1 - 1] != -1) {
            if (contribution[comp[i + k - 1][j + k - 1 - 1]] == 1)
              total -= size_comp[comp[i + k - 1][j + k - 1 - 1]];
            contribution[comp[i + k - 1][j + k - 1 - 1]]--;
          }
          for (int l = 1; l < k - 1; l++) {
            if (board[i + l][j] == '.') n_free++;
            if (board[i + l][j + k - 2] == '.') n_free--;
          }
          Max = max(Max, total + (k - 2) * (k - 2) - n_free);
        }
        if (comp[i][0] != -1) {
          if (contribution[comp[i][0]] == 0) total += size_comp[comp[i][0]];
          contribution[comp[i][0]]++;
        }
        if (comp[i][k - 1] != -1) {
          if (contribution[comp[i][k - 1]] == 0)
            total += size_comp[comp[i][k - 1]];
          contribution[comp[i][k - 1]]++;
        }
        if (comp[i + k - 1][0] != -1) {
          if (contribution[comp[i + k - 1][0]] == 0)
            total += size_comp[comp[i + k - 1][0]];
          contribution[comp[i + k - 1][0]]++;
        }
        if (comp[i + k - 1][k - 1] != -1) {
          if (contribution[comp[i + k - 1][k - 1]] == 0)
            total += size_comp[comp[i + k - 1][k - 1]];
          contribution[comp[i + k - 1][k - 1]]++;
        }
        for (int l = 0; l < k; l++)
          if (comp[i][l] != -1) {
            if (contribution[comp[i][l]] == 1) total -= size_comp[comp[i][l]];
            contribution[comp[i][l]]--;
          }
        for (int l = 0; l < k; l++) {
          if (comp[i + k][l] != -1) {
            if (contribution[comp[i + k][l]] == 0)
              total += size_comp[comp[i + k][l]];
            contribution[comp[i + k][l]]++;
          }
        }
        if (comp[i + 1][0] != -1) {
          if (contribution[comp[i + 1][0]] == 1)
            total -= size_comp[comp[i + 1][0]];
          contribution[comp[i + 1][0]]--;
        }
        if (comp[i + 1][k - 1] != -1) {
          if (contribution[comp[i + 1][k - 1]] == 1)
            total -= size_comp[comp[i + 1][k - 1]];
          contribution[comp[i + 1][k - 1]]--;
        }
        if (comp[i + k][0] != -1) {
          if (contribution[comp[i + k][0]] == 1)
            total -= size_comp[comp[i + k][0]];
          contribution[comp[i + k][0]]--;
        }
        if (comp[i + k][k - 1] != -1) {
          if (contribution[comp[i + k][k - 1]] == 1)
            total -= size_comp[comp[i + k][k - 1]];
          contribution[comp[i + k][k - 1]]--;
        }
        for (int l = 1; l < k - 1; l++) {
          if (board[i + 1][l] == '.') n_free--;
          if (board[i + k - 1][l] == '.') n_free++;
        }
        if (i != n - k) Max = max(Max, total + (k - 2) * (k - 2) - n_free);
      }
    }
    printf("%d\n", Max);
  }
}
