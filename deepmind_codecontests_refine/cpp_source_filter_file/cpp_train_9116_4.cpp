#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;
const int M = 1000 + 10;
const int N = 6000;
struct Node {
  int id, t;
  char c[M];
  char op;
  int op1, op2;
};
Node a[N];
char buf[100];
char ret[2][M];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  map<string, int> idx;
  idx["?"] = n;
  for (int i = 0; i < n; ++i) {
    scanf("%s", buf);
    string s(buf);
    idx[s] = i;
    a[i].id = i;
    scanf("%s", buf);
    scanf("%s", buf);
    if (buf[0] >= '0' && buf[0] <= '9') {
      a[i].t = 0;
      copy(buf, buf + m, a[i].c);
    } else {
      a[i].t = 1;
      if (buf[0] == '?') {
        a[i].op1 = -1;
      } else {
        string s(buf);
        a[i].op1 = idx[s];
      }
      scanf("%s", buf);
      a[i].op = buf[0];
      scanf("%s", buf);
      if (buf[0] == '?') {
        a[i].op2 = -1;
      } else {
        string s(buf);
        a[i].op2 = idx[s];
      }
    }
  }
  for (int i = 0; i < m; ++i) {
    vector<int> sum(2);
    for (int k = 0; k < 2; ++k) {
      vector<int> A(n);
      for (int j = 0; j < n; ++j) {
        if (a[j].t == 0) {
          A[j] = a[j].c[i] - '0';
        } else {
          int u = a[j].op1, v = a[j].op2;
          u = u < 0 ? k : A[u];
          v = v < 0 ? k : A[v];
          if (a[j].op == 'A') {
            A[j] = u & v;
          } else if (a[j].op == 'O') {
            A[j] = u | v;
          } else {
            A[j] = u ^ v;
          }
        }
        sum[k] += A[j];
      }
    }
    if (sum[0] < sum[1]) {
      ret[0][i] = '0';
      ret[1][i] = '1';
    } else if (sum[0] == sum[1]) {
      ret[0][i] = ret[1][i] = '0';
    } else {
      ret[0][i] = '1';
      ret[1][i] = '0';
    }
  }
  ret[0][m] = ret[1][m] = 0;
  puts(ret[0]);
  puts(ret[1]);
  return 0;
}
