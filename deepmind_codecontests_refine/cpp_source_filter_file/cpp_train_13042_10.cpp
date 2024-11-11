#include <bits/stdc++.h>
using namespace std;
class DisjSet {
  int *rank, *parent, n;

 public:
  DisjSet(int n) {
    rank = new int[n];
    parent = new int[n];
    this->n = n;
    makeSet();
  }
  void makeSet() {
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
  }
  int find(int x) {
    if (parent[x] != x) {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  }
  void Union(int x, int y) {
    int xset = find(x);
    int yset = find(y);
    if (xset == yset) return;
    if (rank[xset] < rank[yset]) {
      parent[xset] = yset;
    } else if (rank[xset] > rank[yset]) {
      parent[yset] = xset;
    } else {
      parent[yset] = xset;
      rank[xset] = rank[xset] + 1;
    }
  }
};
unsigned long long power(unsigned long long x, int y, int p) {
  unsigned long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
unsigned long long modInverse(unsigned long long n, int p) {
  return power(n, p - 2, p);
}
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX;
const long double PI = 3.141592653589793238463;
void solve() {
  long long n, m;
  cin >> n >> m;
  char a[n][m];
  for (long long i = 0; i <= (long long)n - 1; i += 1) {
    string s;
    cin >> s;
    for (long long j = 0; j <= (long long)m - 1; j += 1) a[i][j] = s[j];
  }
  vector<long long> x1, x2, x3, y1, y2, y3;
  for (long long i = 0; i <= (long long)n - 2; i += 1) {
    for (long long j = 0; j <= (long long)m - 3; j += 1) {
      if ((a[i][j] == '0') && (a[i + 1][j] == '1')) {
        y1.push_back(j + 1), y2.push_back(j + 2), y3.push_back(j + 2);
        x1.push_back(i + 2), x2.push_back(i + 1), x3.push_back(i + 2);
        a[i + 1][j] = '0';
        a[i + 1][j + 1] = (a[i + 1][j + 1] == '0') ? '1' : '0';
        a[i][j + 1] = (a[i][j + 1] == '0') ? '1' : '0';
      } else if ((a[i][j] == '1') && (a[i + 1][j] == '0')) {
        y1.push_back(j + 1), y2.push_back(j + 2), y3.push_back(j + 2);
        x1.push_back(i + 1), x2.push_back(i + 1), x3.push_back(i + 2);
        a[i][j] = '0';
        a[i + 1][j + 1] = (a[i + 1][j + 1] == '0') ? '1' : '0';
        a[i][j + 1] = (a[i][j + 1] == '0') ? '1' : '0';
      } else if ((a[i][j] == '1') && (a[i + 1][j] == '1')) {
        y1.push_back(j + 1), y2.push_back(j + 1), y3.push_back(j + 2);
        x1.push_back(i + 1), x2.push_back(i + 2), x3.push_back(i + 1);
        a[i][j] = '0';
        a[i + 1][j] = '0';
        a[i][j + 1] = (a[i][j + 1] == '0') ? '1' : '0';
      }
    }
  }
  for (long long i = 0; i <= (long long)n - 2; i += 1) {
    if ((a[i][m - 1] == '0') && (a[i][m - 2] == '1')) {
      y1.push_back(m - 1), y2.push_back(m - 1), y3.push_back(m);
      x1.push_back(i + 1), x2.push_back(i + 2), x3.push_back(i + 2);
      a[i][m - 2] = '0';
      a[i + 1][m - 1] = (a[i + 1][m - 1] == '0') ? '1' : '0';
      a[i + 1][m - 2] = (a[i + 1][m - 2] == '0') ? '1' : '0';
    } else if ((a[i][m - 1] == '1') && (a[i][m - 2] == '0')) {
      y1.push_back(m), y2.push_back(m - 1), y3.push_back(m);
      x1.push_back(i + 1), x2.push_back(i + 2), x3.push_back(i + 2);
      a[i][m - 1] = '0';
      a[i + 1][m - 1] = (a[i + 1][m - 1] == '0') ? '1' : '0';
      a[i + 1][m - 2] = (a[i + 1][m - 2] == '0') ? '1' : '0';
    } else if ((a[i][m - 1] == '1') && (a[i][m - 2] == '1')) {
      y1.push_back(m), y2.push_back(m - 1), y3.push_back(m - 1);
      x1.push_back(i + 1), x2.push_back(i + 1), x3.push_back(i + 2);
      a[i][m - 1] = '0';
      a[i][m - 2] = '0';
      a[i + 1][m - 2] = (a[i + 1][m - 2] == '0') ? '1' : '0';
    }
  }
  if (a[n - 1][m - 1] == '1' && a[n - 1][m - 2] == '1') {
    y1.push_back(m), y2.push_back(m - 1), y3.push_back(m - 1);
    x1.push_back(n), x2.push_back(n), x3.push_back(n - 1);
    y1.push_back(m - 1), y2.push_back(m - 1), y3.push_back(m);
    x1.push_back(n - 1), x2.push_back(n), x3.push_back(n - 1);
    a[n - 1][m - 1] = '0', a[n - 1][m - 2] = '0';
  } else if (a[n - 1][m - 1] == '0' && a[n - 1][m - 2] == '1') {
    y1.push_back(m - 1), y2.push_back(m), y3.push_back(m - 1);
    x1.push_back(n), x2.push_back(n - 1), x3.push_back(n - 1);
    y1.push_back(m - 1), y2.push_back(m - 1), y3.push_back(m);
    x1.push_back(n - 1), x2.push_back(n), x3.push_back(n);
    y1.push_back(m - 1), y2.push_back(m), y3.push_back(m);
    x1.push_back(n), x2.push_back(n), x3.push_back(n - 1);
    a[n - 1][m - 2] = '0';
  } else if (a[n - 1][m - 1] == '1' && a[n - 1][m - 2] == '0') {
    y1.push_back(m), y2.push_back(m), y3.push_back(m - 1);
    x1.push_back(n), x2.push_back(n - 1), x3.push_back(n - 1);
    y1.push_back(m - 1), y2.push_back(m - 1), y3.push_back(m);
    x1.push_back(n - 1), x2.push_back(n), x3.push_back(n);
    y1.push_back(m - 1), y2.push_back(m), y3.push_back(m);
    x1.push_back(n), x2.push_back(n), x3.push_back(n - 1);
    a[n - 1][m - 1] = '0';
  }
  cout << x1.size() << '\n';
  for (long long i = 0; i <= (long long)x1.size() - 1; i += 1) {
    cout << x1[i] << " ";
    cout << y1[i] << " ";
    cout << x2[i] << " ";
    cout << y2[i] << " ";
    cout << x3[i] << " ";
    cout << y3[i] << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long T;
  T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}
