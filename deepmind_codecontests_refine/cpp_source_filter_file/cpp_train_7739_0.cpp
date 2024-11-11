#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<string> X(n);
  for (int i = 0; i < n; ++i) cin >> X[i];
  int m;
  cin >> m;
  vector<vector<string> > Y(m);
  for (int i = 0; i < m; ++i) {
    int k;
    cin >> k;
    for (int j = 0; j < k; ++j) {
      string x;
      cin >> x;
      Y[i].push_back(x);
    }
  }
  int p = -1, nr;
  if (n == 4) {
    for (int a = 0; a < n; ++a) {
      for (int b = 0; b < n; ++b) {
        for (int c = 0; c < n; ++c) {
          for (int d = 0; d < n; ++d) {
            if (a != b && a != c && a != d && b != c && b != d && c != d) {
              int inw = 0;
              if (a > b) ++inw;
              if (a > c) ++inw;
              if (a > d) ++inw;
              if (b > c) ++inw;
              if (b > d) ++inw;
              if (c > d) ++inw;
              bool jest = false;
              int nr2;
              for (int i = 0; i < m; ++i) {
                for (int x = 0; x < Y[i].size(); ++x) {
                  for (int y = x + 1; y < Y[i].size(); ++y) {
                    for (int z = y + 1; z < Y[i].size(); ++z) {
                      for (int w = z + 1; w < Y[i].size(); ++w) {
                        if (Y[i][x] == X[a] && Y[i][y] == X[b] &&
                            Y[i][z] == X[c] && Y[i][w] == X[d] && !jest) {
                          jest = true;
                          nr2 = i;
                        }
                      }
                    }
                  }
                }
              }
              int P = n * (n - 1) / 2 - inw + 1;
              if (jest && P > p || (P == p && nr2 < nr)) {
                p = P;
                nr = nr2;
              }
            }
          }
        }
      }
    }
  }
  if (n == 3) {
    for (int a = 0; a < n; ++a) {
      for (int b = 0; b < n; ++b) {
        for (int c = 0; c < n; ++c) {
          if (a != b && a != c && b != c) {
            int inw = 0;
            if (a > b) ++inw;
            if (a > c) ++inw;
            if (b > c) ++inw;
            bool jest = false;
            int nr2;
            for (int i = 0; i < m; ++i) {
              for (int x = 0; x < Y[i].size(); ++x) {
                for (int y = x + 1; y < Y[i].size(); ++y) {
                  for (int z = y + 1; z < Y[i].size(); ++z) {
                    if (Y[i][x] == X[a] && Y[i][y] == X[b] && Y[i][z] == X[c] &&
                        !jest) {
                      jest = true;
                      nr2 = i;
                    }
                  }
                }
              }
            }
            int P = n * (n - 1) / 2 - inw + 1;
            if (jest && P > p || (P == p && nr2 < nr)) {
              p = P;
              nr = nr2;
            }
          }
        }
      }
    }
  }
  if (n == 2) {
    for (int a = 0; a < n; ++a) {
      for (int b = 0; b < n; ++b) {
        if (a != b) {
          int inw = 0;
          if (a > b) ++inw;
          bool jest = false;
          int nr2;
          for (int i = 0; i < m; ++i) {
            for (int x = 0; x < Y[i].size(); ++x) {
              for (int y = x + 1; y < Y[i].size(); ++y) {
                if (Y[i][x] == X[a] && Y[i][y] == X[b] && !jest) {
                  jest = true;
                  nr2 = i;
                  ;
                }
              }
            }
          }
          int P = n * (n - 1) / 2 - inw + 1;
          if (jest && P > p || (P == p && nr2 < nr)) {
            p = P;
            nr = nr2;
          }
        }
      }
    }
  }
  if (n == 1) {
    for (int a = 0; a < n; ++a) {
      int inw = 0;
      bool jest = false;
      int nr2;
      for (int i = 0; i < m; ++i) {
        for (int x = 0; x < Y[i].size(); ++x) {
          if (Y[i][x] == X[a] && !jest) {
            jest = true;
            nr = i;
          }
        }
      }
      int P = n * (n - 1) / 2 - inw + 1;
      if (jest && P > p || (P == p && nr2 < nr)) {
        p = P;
        nr = nr2;
      }
    }
  }
  if (p != -1) {
    cout << nr + 1 << endl;
    cout << "[:";
    for (int i = 0; i < p; ++i) cout << "|";
    cout << ":]";
  } else
    cout << "Brand new problem!";
  return 0;
}
