#include <bits/stdc++.h>
const int kMaxDem = 2005;
int pnt[2][kMaxDem][kMaxDem];
int N, M, K;
bool rotated;
inline void Swap(int &x, int &y) {
  int tmp = x;
  x = y;
  y = tmp;
}
void Init(int N, int M) {
  for (int i = 0; i <= N + 1; i++) {
    for (int j = 1; j <= M; j++) {
      pnt[0][i][j] = pnt[1][i][j] = i;
    }
  }
}
void Check(int &result, int &r_res, int &c_res, int dist, int r_tmp,
           int c_tmp) {
  if (dist < result) {
    r_res = r_tmp;
    c_res = c_tmp;
    result = dist;
  } else if (dist == result) {
    if ((!rotated) && ((r_tmp < r_res) || (r_tmp == r_res && c_tmp < c_res))) {
      r_res = r_tmp;
      c_res = c_tmp;
    } else if (rotated &&
               ((c_tmp < c_res) || (c_tmp == c_res && r_tmp < r_res))) {
      r_res = r_tmp;
      c_res = c_tmp;
    }
  }
}
int FindUp(int r, int c) {
  if (pnt[0][r][c] == r) return r;
  return pnt[0][r][c] = FindUp(pnt[0][r][c], c);
}
int FindDown(int r, int c) {
  if (pnt[1][r][c] == r) return r;
  return pnt[1][r][c] = FindDown(pnt[1][r][c], c);
}
int FindNeighbour(int idx, int r, int c) {
  if (idx == 0) {
    return FindUp(r, c);
  } else if (idx == 1) {
    return FindDown(r, c);
  }
  printf("Never!\n");
  return -1;
}
void Update(int r_res, int c_res) {
  pnt[0][r_res][c_res] = FindNeighbour(0, r_res - 1, c_res);
  pnt[1][r_res][c_res] = FindNeighbour(1, r_res + 1, c_res);
}
void GetLocation(int k, int r, int c, int &r_res, int &c_res) {
  int left = (1) > (c - k) ? (1) : (c - k);
  int right = (M) < (c + k) ? (M) : (c + k);
  int up_pnt, down_pnt;
  int result = (1 << 30);
  int dist;
  for (int j = left; j <= right; j++) {
    up_pnt = FindNeighbour(0, r, j);
    down_pnt = FindNeighbour(1, r, j);
    if (up_pnt != 0) {
      dist = ((up_pnt - r) >= 0 ? (up_pnt - r) : -(up_pnt - r)) +
             ((j - c) >= 0 ? (j - c) : -(j - c));
      Check(result, r_res, c_res, dist, up_pnt, j);
    }
    if (down_pnt != N + 1) {
      dist = ((down_pnt - r) >= 0 ? (down_pnt - r) : -(down_pnt - r)) +
             ((j - c) >= 0 ? (j - c) : -(j - c));
      Check(result, r_res, c_res, dist, down_pnt, j);
    }
  }
  Update(r_res, c_res);
}
int main() {
  scanf("%d%d%d", &N, &M, &K);
  if (N < M) {
    Swap(N, M);
    rotated = true;
  } else {
    rotated = false;
  }
  Init(N, M);
  int r, c, k;
  int r_res, c_res;
  for (int i = 0; i < K; i++) {
    scanf("%d%d", &r, &c);
    if (rotated) Swap(r, c);
    k = sqrt(i * 2.0 + 1.0) + 1;
    GetLocation(k, r, c, r_res, c_res);
    if (!rotated)
      printf("%d %d\n", r_res, c_res);
    else
      printf("%d %d\n", c_res, r_res);
  }
  return 0;
}
