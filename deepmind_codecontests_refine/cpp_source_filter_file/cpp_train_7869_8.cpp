#include <bits/stdc++.h>
using namespace std;
int arr[555][555];
int n, m;
string in;
void swap_lines(int i, int j) {
  for (int u = 0; u < m; u++) {
    swap(arr[i][u], arr[j][u]);
  }
}
int lcm[5][5];
int col_leader[555];
int query[555];
int main() {
  cin.sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> in;
    for (int j = 0; j < m; j++) {
      arr[i][j] = in[j] - 'a';
    }
  }
  int cur_col = 0;
  int non_empty_row = 0;
  for (int i = 0; i < m; i++) {
    col_leader[i] = -1;
  }
  for (int i = 0; i < n; i++) {
    int first = -1;
    while (cur_col < m) {
      first = -1;
      for (int j = i; j < n; j++) {
        if (arr[j][cur_col] != 0) {
          first = j;
          break;
        }
      }
      if (first == -1) {
        cur_col++;
      } else {
        break;
      }
    }
    if (cur_col == m) {
      break;
    }
    non_empty_row++;
    if (first != i) {
      swap(first, i);
    }
    for (int j = i + 1; j < n; j++) {
      for (int t = m - 1; t >= cur_col; t--) {
        arr[j][t] =
            (arr[j][t] * arr[i][cur_col] - arr[i][t] * arr[j][cur_col]) % 5;
        if (arr[j][t] < 0) arr[j][t] += 5;
      }
    }
    col_leader[cur_col] = i;
    cur_col++;
  }
  int q;
  cin >> q;
  long long ans = 1;
  for (int i = 0; i < n - non_empty_row; i++) {
    ans *= 5;
    ans %= 1000000007;
  }
  while (q--) {
    cin >> in;
    for (int i = 0; i < m; i++) {
      query[i] = in[i] - 'a';
    }
    bool ok = true;
    for (int i = 0; i < m; i++) {
      if (query[i] == 0) continue;
      if (col_leader[i] == -1) {
        ok = false;
        break;
      }
      for (int j = m - 1; j >= i; j--) {
        query[j] = (query[j] * arr[col_leader[i]][i] -
                    arr[col_leader[i]][j] * query[i]) %
                   5;
        if (query[j] < 0) {
          query[j] += 5;
        }
      }
    }
    if (ok) {
      cout << ans << endl;
    } else {
      cout << 0 << endl;
    }
  }
}
