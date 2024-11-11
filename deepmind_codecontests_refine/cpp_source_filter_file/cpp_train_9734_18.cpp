#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
const int M = 3000;
const int P = 1e9 + 7;
const int inv = 5e8 + 4;
int p, a;
char A[N];
int f[2][2][2][M];
void Basetransform(char A[], int p, int &cnt, vector<int> &v) {
  vector<int> tmp, tmp3;
  v.clear();
  int len = strlen(A);
  for (int i = len - 1; i >= 0; i--) tmp.push_back(A[i] - '0');
  cnt = 0;
  if (tmp.size() == 1 && tmp[0] == 0) {
    cnt = 1;
    v.push_back(0);
    return;
  }
  while (!(tmp.size() == 1 && tmp[0] == 0)) {
    cnt++;
    int tmp2 = 0;
    for (int i = tmp.size() - 1; i >= 0; i--) {
      tmp2 = (1LL * tmp2 * 10 + tmp[i]) % p;
    }
    v.push_back(tmp2);
    tmp3.clear();
    long long down = 0;
    for (int i = tmp.size() - 1; i >= 0; i--) {
      down = down * 10 + tmp[i];
      tmp[i] = down / p;
      down %= p;
    }
    for (int i = tmp.size() - 1; i >= 0; i--)
      if (tmp[i] == 0)
        tmp.pop_back();
      else
        break;
    if (tmp.size() == 0) tmp.push_back(0);
  }
}
int cnt;
vector<int> v;
void add(int &x, int y) { x = (x + y) % P; }
int main() {
  scanf("%d%d", &p, &a);
  scanf("%s", A);
  Basetransform(A, p, cnt, v);
  if (a >= cnt) {
    puts("0");
    return 0;
  }
  int now, tmp;
  f[0][0][0][0] = 1;
  f[0][0][1][0] = 1;
  f[0][1][0][0] = 1;
  f[0][1][1][0] = 1;
  for (int i = 1; i <= cnt; i++) {
    now = i & 1;
    memset(f[now], 0, sizeof(f[now]));
    for (int j = 0; j < (int)(M - 1); j++)
      add(f[now][0][0][j + 1],
          1LL * (p - 1) * p % P * inv % P * f[now ^ 1][0][0][j] % P);
    for (int j = 0; j < (int)(M); j++)
      add(f[now][0][0][j],
          1LL * (p - 1) * p % P * inv % P * f[now ^ 1][0][0][j] % P);
    for (int j = 0; j < (int)(M - 1); j++)
      add(f[now][0][0][j + 1],
          1LL * p * (f[now ^ 1][0][0][j] - f[now ^ 1][0][1][j]) % P);
    for (int j = 0; j < (int)(M); j++)
      add(f[now][0][0][j], 1LL * p * f[now ^ 1][0][1][j] % P);
    for (int j = 0; j < (int)(M); j++)
      add(f[now][0][1][j],
          1LL * (p - 1) * p % P * inv % P * f[now ^ 1][0][0][j] % P);
    for (int j = 0; j < (int)(M); j++)
      add(f[now][0][1][j], 1LL * p * f[now ^ 1][0][1][j] % P);
    tmp = v[i - 1];
    for (int j = 0; j < (int)(M - 1); j++)
      add(f[now][1][0][j + 1], 1LL * (2 * p - tmp - 1) * tmp % P * inv % P *
                                   f[now ^ 1][0][0][j] % P);
    for (int j = 0; j < (int)(M); j++)
      add(f[now][1][0][j],
          1LL * (tmp - 1) * tmp % P * inv % P * f[now ^ 1][0][0][j] % P);
    for (int j = 0; j < (int)(M - 1); j++)
      add(f[now][1][0][j + 1],
          1LL * tmp * (f[now ^ 1][0][0][j] - f[now ^ 1][0][1][j]) % P);
    for (int j = 0; j < (int)(M); j++)
      add(f[now][1][0][j], 1LL * tmp * f[now ^ 1][0][1][j] % P);
    for (int j = 0; j < (int)(M); j++)
      add(f[now][1][0][j], 1LL * tmp * f[now ^ 1][1][0][j] % P);
    for (int j = 0; j < (int)(M - 1); j++)
      add(f[now][1][0][j + 1], 1LL * (p - tmp - 1) * f[now ^ 1][1][0][j] % P);
    for (int j = 0; j < (int)(M - 1); j++)
      add(f[now][1][0][j + 1], (f[now ^ 1][1][0][j] - f[now ^ 1][1][1][j]) % P);
    for (int j = 0; j < (int)(M); j++)
      add(f[now][1][0][j], f[now ^ 1][1][1][j]);
    for (int j = 0; j < (int)(M); j++)
      add(f[now][1][1][j],
          1LL * (tmp - 1) * tmp % P * inv % P * f[now ^ 1][0][0][j] % P);
    for (int j = 0; j < (int)(M); j++)
      add(f[now][1][1][j], 1LL * tmp * f[now ^ 1][0][1][j] % P);
    for (int j = 0; j < (int)(M); j++)
      add(f[now][1][1][j], 1LL * tmp * f[now ^ 1][1][0][j] % P);
    for (int j = 0; j < (int)(M); j++)
      add(f[now][1][1][j], f[now ^ 1][1][1][j]);
  }
  int ans = 0;
  for (int i = a; i < M; i++) add(ans, f[now][1][1][i]);
  ans = (ans % P + P) % P;
  printf("%d\n", ans);
  return 0;
}
