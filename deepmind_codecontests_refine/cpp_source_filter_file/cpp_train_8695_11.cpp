#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> A(1005, vector<long long>(1005, 0));
vector<vector<long long>> B(1005, vector<long long>(1005, 0));
vector<vector<char>> vis(1005, vector<char>(1005, 0));
vector<vector<long long>> seta;
long long parent[1005 * 1005];
long long size[1005 * 1005];
void make_set(long long n) {
  for (long long i = 0; i < n; i++) {
    parent[i] = i;
    size[i] = 1;
  }
}
long long find(long long v) {
  if (parent[v] == v) return v;
  return parent[v] = find(parent[v]);
}
void dounion(long long a, long long b) {
  a = find(a);
  b = find(b);
  if (a != b) {
    if (size[a] < size[b]) swap(a, b);
    parent[b] = a;
    size[a] += size[b];
  }
}
int main() {
  long long(n), (m);
  scanf("%lld%lld", &(n), &(m));
  ;
  long long(k);
  scanf("%lld", &(k));
  ;
  for (long long i = 0; i < (n); i++)
    for (long long j = 0; j < (m); j++) {
      scanf("%lld", &A[i][j]);
      seta.push_back(vector<long long>{A[i][j], i, j});
    }
  make_set(1005 * 1005);
  long long mx[5] = {0, 1, 0, -1, 0};
  long long my[5] = {0, 0, 1, 0, -1};
  sort((seta).begin(), (seta).end());
  reverse((seta).begin(), (seta).end());
  for (long long v = 0; v < (m * n); v++) {
    long long val = seta[v][0], x = seta[v][1], y = seta[v][2];
    for (long long i = 0; i < (5); i++) {
      long long nx = x + mx[i], ny = y + my[i];
      if (nx >= 0 && nx < n && ny < m && ny >= 0 && A[nx][ny] >= val) {
        dounion(x * m + y, nx * m + ny);
        long long a = val * size[find(x * m + y)];
        if (a >= k && (k % val) == 0) {
          long long qu = k / val, c = 1;
          queue<pair<long long, long long>> q;
          q.push({x, y});
          vis[x][y] = 1;
          B[x][y] = val;
          while (!q.empty() && c < qu) {
            pair<long long, long long> t = q.front();
            q.pop();
            for (long long i = 0; i < (4); i++) {
              long long nx = t.first + mx[i], ny = t.second + my[i];
              if (c < qu && nx >= 0 && nx < n && ny < m && ny >= 0 &&
                  A[nx][ny] >= val && !vis[nx][ny]) {
                vis[nx][ny] = 1;
                B[nx][ny] = val;
                q.push({nx, ny});
                c++;
              }
            }
          }
          printf("YES\n");
          for (long long i = 0; i < (n); i++) {
            for (long long j = 0; j < (m); j++) {
              printf("%lld ", B[i][j]);
            }
            printf("\n");
          }
          return 0;
        }
      }
    }
  }
  printf("NO\n");
  return 0;
}
