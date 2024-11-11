#include <bits/stdc++.h>
const int maxn = 705;
struct bigint {
  int data[50], size;
  bigint(int key = 0) {
    memset(data, 0, sizeof(data));
    size = 0;
    do {
      data[size++] = key % 10;
      key /= 10;
    } while (key);
  }
  bigint operator*(const bigint &ot) {
    bigint ret;
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < ot.size; j++) {
        ret.data[i + j] += data[i] * ot.data[j];
        int h = i + j;
        while (ret.data[h] >= 10) {
          ret.data[h + 1] += ret.data[h] / 10;
          ret.data[h++] %= 10;
        }
      }
    }
    ret.size = size + ot.size;
    while (!ret.data[ret.size - 1] && ret.size > 1) ret.size--;
    return ret;
  }
  bool operator<(const bigint &ot) {
    if (size != ot.size)
      return size < ot.size;
    else {
      for (int i = size; i > 0; i--) {
        if (data[i - 1] < ot.data[i - 1])
          return true;
        else if (data[i - 1] > ot.data[i - 1])
          return false;
      }
    }
    return false;
  }
  void print() {
    for (int i = size; i > 0; i--) printf("%d", data[i - 1]);
    printf("\n");
  }
};
bigint dp[maxn][maxn];
int mat[maxn][maxn], num[maxn], n;
bigint getmax(bigint a, bigint b) { return a < b ? b : a; }
int getmin(int a, int b) { return a < b ? a : b; }
void init() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    mat[x][++mat[x][0]] = y;
    mat[y][++mat[y][0]] = x;
  }
}
void getans(int x, int pnt) {
  num[x] = 1;
  dp[x][1] = bigint(1);
  for (int i = 1; i <= mat[x][0]; i++) {
    int y = mat[x][i];
    if (y == pnt) continue;
    getans(y, x);
    for (int j = num[x]; j > 0; j--) {
      for (int h = num[y]; h >= 0; h--) {
        dp[x][j + h] = getmax(dp[x][j + h], dp[x][j] * dp[y][h]);
      }
    }
    num[x] += num[y];
  }
  for (int i = 1; i <= num[x]; i++)
    dp[x][0] = getmax(dp[x][0], dp[x][i] * bigint(i));
  dp[x][0] = getmax(dp[x][0], bigint(num[x]));
}
int main() {
  init();
  getans(1, 0);
  dp[1][0].print();
  return 0;
}
