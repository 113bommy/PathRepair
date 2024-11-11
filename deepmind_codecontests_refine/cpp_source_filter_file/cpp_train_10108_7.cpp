#include <bits/stdc++.h>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
double pi = 3.141592653589793;
long long mod = 1000000007;
int intmax = 2147483647;
int intmin = -2147483648;
long long llmax = 9223372036854775807;
long long llmin = -9223372036854775807;
int iinf = intmax / 8;
long long inf = llmax / 8;
double eps = 1e-11;
vector<int> g[1000010];
int main() {
  int N;
  cin >> N;
  int mark[N];
  int child[N][2];
  int data[N];
  fill(data, data + N, -1);
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    int x, y;
    if (s == "AND") {
      mark[i] = 0;
    } else if (s == "OR") {
      mark[i] = 1;
    } else if (s == "XOR") {
      mark[i] = 2;
    } else if (s == "NOT") {
      mark[i] = 3;
    } else {
      mark[i] = 4;
    }
    if (mark[i] <= 2) {
      cin >> x >> y;
      child[i][0] = x - 1;
      child[i][1] = y - 1;
    } else if (mark[i] == 3) {
      cin >> x;
      child[i][0] = x - 1;
      child[i][1] = -1;
    } else {
      cin >> x;
      data[i] = x;
      child[i][0] = -1;
      child[i][1] = -1;
    }
  }
  int rank[N];
  queue<int> que;
  rank[0] = 0;
  que.push(0);
  g[0].push_back(0);
  int maxrank = 0;
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    int v1 = child[v][0];
    int v2 = child[v][1];
    if (v1 != -1) {
      rank[v1] = rank[v] + 1;
      if (rank[v1] > maxrank) {
        maxrank = rank[v1];
      }
      que.push(v1);
      g[rank[v1]].push_back(v1);
    }
    if (v2 != -1) {
      rank[v2] = rank[v] + 1;
      que.push(v2);
      g[rank[v2]].push_back(v2);
    }
  }
  for (int i = maxrank - 1; i >= 0; i--) {
    int len = g[i].size();
    for (int j = 0; j < len; j++) {
      int v = g[i][j];
      int mk = mark[v];
      int v1 = child[v][0];
      int v2 = child[v][1];
      if (mk == 0) {
        data[v] = data[v1] & data[v2];
      } else if (mk == 1) {
        data[v] = data[v1] | data[v2];
      } else if (mk == 2) {
        data[v] = data[v1] ^ data[v2];
      } else if (mk == 3) {
        data[v] = (data[v1] + 1) % 2;
      }
    }
  }
  bool change[N];
  change[0] = true;
  for (int i = 0; i <= maxrank; i++) {
    int len = g[i].size();
    for (int j = 0; j < len; j++) {
      int v = g[i][j];
      int mk = mark[v];
      int v1 = child[v][0];
      int v2 = child[v][1];
      if (change[v]) {
        if (mk == 0) {
          if (data[v1] == 1) {
            change[v2] = true;
          } else {
            change[v2] = false;
          }
          if (data[v2] == 1) {
            change[v1] = true;
          } else {
            change[v2] = false;
          }
        } else if (mk == 1) {
          if (data[v1] == 0) {
            change[v2] = true;
          } else {
            change[v2] = false;
          }
          if (data[v2] == 0) {
            change[v1] = true;
          } else {
            change[v2] = false;
          }
        } else if (mk == 2) {
          change[v1] = true;
          change[v2] = true;
        } else if (mk == 3) {
          change[v1] = true;
        }
      } else {
        if (mk <= 2) {
          change[v1] = false;
          change[v2] = false;
        } else if (mk == 3) {
          change[v1] = false;
        }
      }
    }
  }
  for (int i = 0; i < N; i++) {
    if (mark[i] == 4) {
      if (change[i]) {
        cout << (data[i] + 1) % 2;
      } else {
        cout << data[i];
      }
    }
  }
  cout << endl;
}
