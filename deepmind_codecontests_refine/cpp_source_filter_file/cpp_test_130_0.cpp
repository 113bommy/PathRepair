#include <bits/stdc++.h>
using namespace std;
int ask(int a, int b, int c) {
  cout << "? " << a + 1 << " " << b + 1 << " " << c + 1 << endl;
  int r;
  cin >> r;
  return r;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int q[n];
    fill(q, q + n, -1);
    int one = -1, zero = -1;
    for (int i = 1; i < n;) {
      q[i] = ask(i - 1, i, i + 1);
      i += 3;
    }
    for (int i = 1; i < n - 1; i += 3) {
      if (q[i] != q[i + 3]) {
        if (q[i] == 0) {
          zero = i, one = i + 3;
        } else {
          zero = i + 3, one = i;
        }
      }
    }
    int crew = -1, imp = -1;
    for (int i = min(zero, one); i <= max(zero, one); ++i) {
      if (q[i] == -1) q[i] = ask(i - 1, i, i + 1);
    }
    for (int i = min(zero, one); i < max(zero, one); ++i) {
      if (q[i] != q[i + 1]) {
        if (q[i] == 0) {
          crew = i + 2, imp = i - 1;
        } else {
          crew = i - 1, imp = i + 2;
        }
      }
    }
    int tp[n];
    memset(tp, -1, n);
    tp[crew] = 0, tp[imp] = 1;
    for (int i = 1; i < n;) {
      if (q[i] == 0) {
        if (abs(i - crew) <= 1 && abs(i - imp) <= 1) {
          int v = i - 1 + i + i + 1 - crew - imp;
          tp[crew] = 1, tp[imp] = 0, tp[v] = ask(crew, imp, v);
        } else if (abs(i - crew) <= 1) {
          tp[i - 1] = tp[i] = tp[i + 1] = 0;
          tp[crew] = 1;
        } else if (abs(i - imp) <= 1) {
          if (imp == i - 1) {
            tp[i - 1] = 0, tp[i] = ask(imp, crew, i),
                   tp[i + 1] = ask(imp, crew, i + 1);
          } else if (imp == i) {
            tp[i - 1] = ask(imp, crew, i - 1), tp[i] = 0,
                   tp[i + 1] = ask(imp, crew, i + 1);
          } else {
            tp[i - 1] = ask(imp, crew, i - 1), tp[i] = ask(imp, crew, i),
                   tp[i + 1] = 0;
          }
        } else {
          int p1 = ask(i - 1, i, crew), p2 = ask(i, i + 1, crew);
          if (p1 == 1 && p2 == 1) {
            tp[i - 1] = 0, tp[i] = 1, tp[i + 1] = 0;
          } else if (p1 == 1) {
            tp[i - 1] = 1, tp[i] = 0, tp[i + 1] = 0;
          } else if (p2 == 1) {
            tp[i - 1] = 0, tp[i] = 0, tp[i + 1] = 1;
          } else {
            tp[i - 1] = tp[i] = tp[i + 1] = 0;
          }
        }
      } else {
        if (abs(i - crew) <= 1 && abs(i - imp) <= 1) {
          int v = i - 1 + i + i + 1 - crew - imp;
          tp[crew] = 1, tp[imp] = 0, tp[v] = ask(crew, imp, v);
        } else if (abs(i - crew) <= 1) {
          if (crew == i - 1) {
            tp[i - 1] = 1, tp[i] = ask(imp, crew, i),
                   tp[i + 1] = ask(imp, crew, i + 1);
          } else if (crew == i) {
            tp[i - 1] = ask(imp, crew, i - 1), tp[i] = 1,
                   tp[i + 1] = ask(imp, crew, i + 1);
          } else {
            tp[i - 1] = ask(imp, crew, i - 1), tp[i] = ask(imp, crew, i),
                   tp[i + 1] = 1;
          }
        } else if (abs(i - imp) <= 1) {
          tp[i - 1] = tp[i] = tp[i + 1] = 1;
          tp[imp] = 0;
        } else {
          int p1 = ask(i - 1, i, imp), p2 = ask(i, i + 1, imp);
          if (p1 == 0 && p2 == 0) {
            tp[i - 1] = 1, tp[i] = 0, tp[i + 1] = 1;
          } else if (p1 == 0) {
            tp[i - 1] = 0, tp[i] = 1, tp[i + 1] = 1;
          } else if (p2 == 0) {
            tp[i - 1] = 1, tp[i] = 1, tp[i + 1] = 0;
          } else {
            tp[i - 1] = tp[i] = tp[i + 1] = 1;
          }
        }
      }
      i += 3;
    }
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
      if (tp[i] == 0) ans.push_back(i);
    }
    cout << "! " << ans.size() << " ";
    for (auto u : ans) {
      cout << u + 1 << " ";
    }
    cout << endl;
  }
}
