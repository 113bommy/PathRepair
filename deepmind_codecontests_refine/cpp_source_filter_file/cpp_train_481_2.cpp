#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int matX = 10;
const int mod = 1e9 + 7;
struct Matrix {
  long long n, m, s[matX][matX];
  Matrix(int n, int m) : n(n), m(m) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) s[i][j] = 0;
    }
  }
  Matrix operator*(const Matrix &P) const {
    Matrix ret(n, P.m);
    for (int i = 0; i < n; i++) {
      for (int k = 0; k < m; k++) {
        if (s[i][k]) {
          for (int j = 0; j < P.m; j++) {
            ret.s[i][j] = ((long long)s[i][k] * P.s[k][j] + ret.s[i][j]) % mod;
          }
        }
      }
    }
    return ret;
  }
  Matrix operator^(const long long &P) const {
    long long num = P;
    Matrix ret(n, m), tmp = *this;
    for (int i = 0; i < n; i++) ret.s[i][i] = 1;
    while (num) {
      if (num & 1) ret = ret * tmp;
      tmp = tmp * tmp;
      num >>= 1;
    }
    return ret;
  }
};
const int MAX = 1e4 + 10;
class Edge {
 public:
  long long l, r, a;
};
Edge edge[MAX];
int maps[5][MAX << 2];
vector<long long> disper;
void print(Matrix &b) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << b.s[i][j] << " ";
    }
    puts("");
  }
  puts("");
}
int find_key(long long x) {
  return lower_bound(disper.begin(), disper.end(), x) - disper.begin();
}
int str[MAX];
bool check(int i) {
  if (maps[1][i] == 0 && maps[1][i - 1] != 0) {
    return 0;
  }
  if (maps[1][i] != 0 && maps[1][i - 1] == 0) {
    return 0;
  }
  if (maps[2][i] == 0 && maps[2][i - 1] != 0) {
    return 0;
  }
  if (maps[2][i] != 0 && maps[2][i - 1] == 0) {
    return 0;
  }
  if (maps[3][i] == 0 && maps[3][i - 1] != 0) {
    return 0;
  }
  if (maps[3][i] != 0 && maps[3][i - 1] == 0) {
    return 0;
  }
  return 1;
}
int main() {
  long long n, m;
  scanf("%lld %lld", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d", &edge[i].a, &edge[i].l, &edge[i].r);
    disper.push_back(edge[i].l);
    disper.push_back(edge[i].r + 1);
  }
  disper.push_back(1);
  disper.push_back(m);
  sort(disper.begin(), disper.end());
  disper.erase(unique(disper.begin(), disper.end()), disper.end());
  for (int i = 0; i < n; i++) {
    maps[edge[i].a][find_key(edge[i].l)]++;
    maps[edge[i].a][find_key(edge[i].r + 1)]--;
  }
  for (int i = 1; i < disper.size(); i++) {
    for (int j = 1; j <= 3; j++) {
      maps[j][i] += maps[j][i - 1];
    }
  }
  Matrix base(3, 3);
  base.s[0][0] = 1, base.s[0][1] = 1, base.s[0][2] = 0;
  base.s[1][0] = 1, base.s[1][1] = 1, base.s[1][2] = 1;
  base.s[2][0] = 0, base.s[2][1] = 1, base.s[2][2] = 1;
  int per = 0;
  Matrix ans(3, 3);
  ans.s[0][0] = 0;
  ans.s[1][0] = 1;
  ans.s[2][0] = 0;
  for (int i = 1; i < disper.size(); i++) {
    bool flag = 0;
    if (!check(i) || disper[i] == m) {
      ans = (base ^ (disper[i] - disper[per] - 1)) * ans;
      per = i;
      flag = 1;
    }
    if (maps[1][i] > 0)
      base.s[0][0] = base.s[0][1] = base.s[0][2] = 0;
    else if (maps[1][i] == 0)
      base.s[0][0] = 1, base.s[0][1] = 1, base.s[0][2] = 0;
    if (maps[2][i] > 0)
      base.s[1][0] = base.s[1][1] = base.s[1][2] = 0;
    else if (maps[2][i] == 0)
      base.s[1][0] = 1, base.s[1][1] = 1, base.s[1][2] = 1;
    if (maps[3][i] > 0)
      base.s[2][0] = base.s[2][1] = base.s[2][2] = 0;
    else if (maps[2][i] == 0)
      base.s[2][0] = 0, base.s[2][1] = 1, base.s[2][2] = 1;
    if (flag) {
      ans = base * ans;
    }
  }
  cout << ans.s[1][0] << endl;
}
