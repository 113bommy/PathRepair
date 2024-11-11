#include <bits/stdc++.h>
using namespace std;
const long double epsilon = 1e-9;
int mat[16];
void solveSmall(int n) {
  int sz = n * n;
  sort(mat, mat + sz);
  int s = 0;
  for (int i = 0; i < sz; i++) s += mat[i];
  s /= n;
  vector<int> rows(n);
  vector<int> cols(n);
  do {
    for (int i = 0; i < n; i++) {
      rows[i] = cols[i] = 0;
    }
    for (int i = 0; i < sz; i++) {
      rows[i / n] += mat[i];
      cols[i % n] += mat[i];
    }
    bool does = true;
    for (int i = 0; i < n; i++) {
      if (rows[i] != s || cols[i] != s) {
        does = false;
        break;
      }
    }
    if (!does) continue;
    int diag = 0, diag2 = 0;
    for (int i = 0; i < n; i++) {
      diag += mat[i * n + i];
      diag2 += mat[n - i - 1 + i * n];
    }
    if (diag != s || diag2 != s) continue;
    cout << s << endl;
    for (int i = 0; i < sz; i++) {
      cout << mat[i];
      if (i % n != n - 1)
        cout << " ";
      else
        cout << endl;
    }
    return;
  } while (next_permutation(mat, mat + sz));
}
int cnt[8];
bool used[16];
int te;
int S;
int SUM;
void initialize() {
  te = S - mat[cnt[1]] - mat[cnt[2]] - mat[cnt[3]];
  bool found = false;
  for (int k = 0; k < 16; k++) {
    if (mat[k] == te && !used[k]) {
      found = true;
    }
  }
  if (!found) {
    for (int i = 7; i > 3; i--) {
      used[cnt[i]] = false;
    }
    for (int i = 3; i >= 0; i--) {
      used[cnt[i]] = false;
      for (int j = cnt[i] + 1; j < 16; j++) {
        if (!used[j]) {
          used[j] = true;
          if (i == 3) {
            te = S - mat[cnt[1]] - mat[cnt[2]] - mat[j];
            bool found = false;
            for (int k = 0; k < 16; k++) {
              if (mat[k] == te && !used[k]) {
                found = true;
              }
            }
            if (!found) {
              used[j] = false;
              continue;
            }
          }
          cnt[i] = j;
          te = 0;
          for (int k = i + 1; k < 8; k++) {
            for (; te < 16; te++) {
              if (!used[te]) {
                used[te] = true;
                cnt[k] = te;
                break;
              }
            }
          }
          return;
        }
      }
    }
  }
}
bool getNextCnt() {
  for (int i = 7; i > 5; i--) {
    used[cnt[i]] = false;
    for (int j = cnt[i] + 1; j < 16; j++) {
      if (!used[j]) {
        cnt[i] = j;
        te = 0;
        used[j] = true;
        for (int k = i + 1; k < 8; k++) {
          for (; te < 16; te++) {
            if (!used[te]) {
              used[te] = true;
              cnt[k] = te;
              break;
            }
          }
        }
        return true;
      }
    }
  }
  used[cnt[5]] = false;
  SUM = mat[cnt[1]] + mat[cnt[2]] + mat[cnt[4]];
  for (int j = cnt[5] + 1; j < 16; j++) {
    if (!used[j] && SUM + mat[j] == S) {
      cnt[5] = j;
      te = 0;
      used[j] = true;
      for (int k = 6; k < 8; k++) {
        for (; te < 16; te++) {
          if (!used[te]) {
            used[te] = true;
            cnt[k] = te;
            break;
          }
        }
      }
      return true;
    }
  }
  for (int i = 4; i >= 0; i--) {
    used[cnt[i]] = false;
    for (int j = cnt[i] + 1; j < 16; j++) {
      if (!used[j]) {
        used[j] = true;
        if (i == 3) {
          te = S - mat[cnt[1]] - mat[cnt[2]] - mat[j];
          bool found = false;
          for (int k = 0; k < 16; k++) {
            if (mat[k] == te && !used[k]) {
              found = true;
            }
          }
          if (!found) {
            used[j] = false;
            continue;
          }
        }
        cnt[i] = j;
        te = 0;
        for (int k = i + 1; k < 8; k++) {
          for (; te < 16; te++) {
            if (!used[te]) {
              used[te] = true;
              cnt[k] = te;
              break;
            }
          }
        }
        return true;
      }
    }
  }
  return false;
}
void solve4() {
  for (int i = 0; i < 8; i++) cnt[i] = i;
  int n = 4;
  int sz = n * n;
  int s = 0;
  for (int i = 0; i < sz; i++) s += mat[i];
  for (int i = 0; i < sz; i++) used[i] = i < 8;
  sort(mat, mat + sz);
  s /= n;
  S = s;
  int realMat[16];
  int a, x, y, c, z, t, q, b;
  vector<int> rows(n);
  vector<int> cols(n);
  int tmpMat[16];
  initialize();
  do {
    a = mat[cnt[0]];
    x = mat[cnt[1]];
    y = mat[cnt[2]];
    c = mat[cnt[3]];
    z = mat[cnt[4]];
    t = mat[cnt[5]];
    q = mat[cnt[6]];
    b = mat[cnt[7]];
    realMat[2] = a;
    realMat[5] = x;
    realMat[6] = y;
    realMat[7] = c;
    realMat[9] = z;
    realMat[10] = t;
    realMat[12] = q;
    realMat[15] = b;
    realMat[3] = s - z - y - q;
    realMat[4] = s - x - y - c;
    realMat[14] = s - a - y - t;
    realMat[13] = s - q - b - realMat[14];
    realMat[1] = s - x - z - realMat[13];
    realMat[0] = s - realMat[1] - realMat[2] - realMat[3];
    realMat[8] = s - realMat[0] - realMat[4] - realMat[12];
    realMat[11] = s - realMat[10] - realMat[9] - realMat[8];
    memcpy(tmpMat, realMat, sizeof(realMat));
    bool does = true;
    sort(tmpMat, tmpMat + sz);
    for (int i = 0; i < sz; i++) {
      if (tmpMat[i] != mat[i]) {
        does = false;
        break;
      }
    }
    if (!does) continue;
    for (int i = 0; i < n; i++) {
      rows[i] = cols[i] = 0;
    }
    for (int i = 0; i < sz; i++) {
      rows[i / n] += realMat[i];
      cols[i % n] += realMat[i];
    }
    for (int i = 0; i < n; i++) {
      if (rows[i] != s || cols[i] != s) {
        does = false;
        break;
      }
    }
    if (!does) continue;
    int diag = 0, diag2 = 0;
    for (int i = 0; i < n; i++) {
      diag += realMat[i * n + i];
      diag2 += realMat[n - i - 1 + i * n];
    }
    if (diag != s || diag2 != s) continue;
    cout << s << endl;
    for (int i = 0; i < sz; i++) {
      cout << realMat[i];
      if (i % n != n - 1)
        cout << " ";
      else
        cout << endl;
    }
    return;
  } while (getNextCnt());
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n * n; i++) {
    cin >> mat[i];
  }
  if (n <= 3) {
    solveSmall(n);
  } else
    solve4();
  return 0;
}
