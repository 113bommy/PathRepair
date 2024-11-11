#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int cnt[N][N];
char pat[N][N];
int n, k;
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) scanf("%s", pat[i] + 1);
  int br = 0, bc = 0;
  for (int r = 1; r <= n; r++) {
    for (int c = 1; c <= n; c++) {
      if (pat[r][c] == '#') continue;
      bool ok = true;
      for (int i = 1; i < k; i++) {
        int nr = r + i;
        if (nr > n || pat[nr][c] == '#') {
          ok = false;
          break;
        }
      }
      if (ok) {
        for (int i = 0; i < k; i++) {
          cnt[r + i][c]++;
        }
      }
      ok = true;
      for (int i = 1; i < k; i++) {
        int nc = c + i;
        if (nc > n || pat[r][nc] == '#') {
          ok = false;
          break;
        }
      }
      if (ok) {
        for (int i = 0; i < k; i++) {
          cnt[r][c + i]++;
        }
      }
      if (cnt[r][c] > cnt[br][bc]) {
        br = r;
        bc = c;
      }
    }
  }
  cout << br << ' ' << bc << endl;
  return 0;
}
