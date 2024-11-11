#include <bits/stdc++.h>
using namespace std;
int N, M;
char A[105][105];
int srow[105][105], scol[105][105], size[105][105];
bool inside(int r, int c) { return (1 <= r && r <= N && 1 <= c && c <= M); }
bool test(int sr, int sc, int sz, char k) {
  char temp[105][105];
  memcpy(temp, A, sizeof(A));
  for (int r = sr; r < sr + sz; r++)
    for (int c = sc; c < sc + sz; c++) {
      if (!inside(r, c)) return false;
      if (temp[r][c] != k && temp[r][c] != '.') return false;
      temp[r][c] = k;
    }
  for (int r = sr - 1; r <= sr + sz; r++)
    for (int c = sc - 1; c <= sc + sz; c++) {
      if ((r == sr - 1 || r == sr + sz) ^ (c == sc - 1 || c == sc + sz)) {
        if (temp[r][c] == k) return false;
      }
    }
  return true;
}
void print() {
  for (int r = 1; r <= N; r++) {
    for (int c = 1; c <= M; c++) cout << A[r][c];
    cout << endl;
  }
}
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int main() {
  cin >> N >> M;
  memset(A, '.', sizeof(A));
  for (int r = 1; r <= N; r++) {
    for (int c = 1; c <= M; c++) {
      if (A[r][c] == '.') {
        for (char k = 'A'; k <= 'Z'; k++) {
          bool found = false;
          bool good = false;
          for (int d = 0; d < 4; d++) {
            int dr = dir[d][0], dc = dir[d][1];
            if (A[r + dr][c + dc] == k) {
              found = true;
              int sr = srow[r + dr][c + dc], sc = scol[r + dr][c + dc],
                  sz = size[r + dr][c + dc];
              if (test(sr, sc, sz + 1, k)) {
                for (int r = sr; r < sr + sz + 1; r++)
                  for (int c = sc; c < sc + sz + 1; c++) {
                    A[r][c] = k, srow[r][c] = sr, scol[r][c] = sc,
                    size[r][c] = sz + 1;
                  }
                good = true;
                break;
              }
            }
          }
          if (good) break;
          if (!found) {
            A[r][c] = k, srow[r][c] = r, scol[r][c] = c, size[r][c] = 1;
            break;
          }
        }
      }
    }
  }
  print();
}
