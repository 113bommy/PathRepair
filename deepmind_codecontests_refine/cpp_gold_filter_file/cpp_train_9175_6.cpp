#include <bits/stdc++.h>
using namespace std;
int nextInt() {
  int x;
  scanf("%d", &x);
  return x;
}
long long nextLong() {
  long long x;
  scanf("%I64d", &x);
  return x;
}
double nextDouble() {
  double x;
  scanf("%lf", &x);
  return x;
}
const int BUFSIZE = 1000000;
char buf[BUFSIZE + 1];
string nextString() {
  scanf("%s", buf);
  return buf;
}
int getV(int i, int j, int n) {
  if (i > j) {
    swap(i, j);
  }
  return (2 * n + 1 - i) * i / 2 + j - i;
}
const int N = 22 * 23 / 2;
double A[N][N], B[N][N];
void square(int n) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      B[i][j] = 0;
      for (int k = 0; k < n; ++k) {
        B[i][j] += A[i][k] * A[k][j];
      }
      if (B[i][j] < 1e-20) {
        B[i][j] = 0;
      }
    }
  }
  memcpy(A, B, sizeof(B));
}
int main() {
  if (false) {
    freopen("stdin.txt", "wt", stdout);
    int n = 22;
    int m = n * (n - 1) / 2;
    printf("%d %d %d %d\n", n, m, 1, 2);
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        printf("%d %d\n", i + 1, j + 1);
      }
    }
    for (int i = 0; i < n; ++i) {
      printf("%.2lf\n", 0.5);
    }
    return 0;
  }
  memset(A, 0, sizeof(A));
  int n = nextInt();
  int m = nextInt();
  int a = nextInt() - 1;
  int b = nextInt() - 1;
  vector<vector<int> > adj(n);
  for (int i = 0; i < m; ++i) {
    int x = nextInt() - 1;
    int y = nextInt() - 1;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  vector<double> p(n);
  for (int i = 0; i < n; ++i) {
    p[i] = nextDouble();
  }
  int npos = n * (n - 1) / 2;
  for (int i = 0; i < n; ++i) {
    int x = getV(i, i, n);
    A[x][x] = 1;
    for (int j = i + 1; j < n; ++j) {
      vector<pair<int, double> > toi;
      toi.push_back(make_pair(i, p[i]));
      for (int t = 0; t < adj[i].size(); ++t) {
        toi.push_back(make_pair(adj[i][t], (1 - p[i]) / adj[i].size()));
      }
      vector<pair<int, double> > toj;
      toj.push_back(make_pair(j, p[j]));
      for (int t = 0; t < adj[j].size(); ++t) {
        toj.push_back(make_pair(adj[j][t], (1 - p[j]) / adj[j].size()));
      }
      for (int ti = 0; ti < toi.size(); ++ti) {
        for (int tj = 0; tj < toj.size(); ++tj) {
          int x = getV(i, j, n);
          int y = getV(toi[ti].first, toj[tj].first, n);
          A[x][y] += toi[ti].second * toj[tj].second;
        }
      }
    }
  }
  for (int i = 0; i < 20; ++i) {
    cerr << "iteration: " << i << endl;
    square(n * (n + 1) / 2);
  }
  int x = getV(a, b, n);
  for (int i = 0; i < n; ++i) {
    int y = getV(i, i, n);
    if (i > 0) {
      printf(" ");
    }
    printf("%.10lf", A[x][y]);
  }
  printf("\n");
  cerr << "time = " << clock() << endl;
  return 0;
}
