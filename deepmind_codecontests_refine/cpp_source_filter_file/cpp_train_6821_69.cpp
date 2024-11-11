#include <bits/stdc++.h>
using namespace std;
const int max_n = 5050;
struct pp {
  int num;
  int a;
  bool operator<(const pp &p) const { return num < p.num; }
  pp() {}
  pp(int num, int a) {
    this->num = num;
    this->a = a;
  }
  void clear() {
    this->num = 0;
    this->a = 0;
  }
};
pp row[max_n];
pp column[max_n];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, k;
  while (cin >> n >> m >> k) {
    int op, id, num;
    for (int i = 0; i < max_n; i++) {
      row[i].clear();
      column[i].clear();
    }
    for (int i = 0; i < k; i++) {
      cin >> op >> id >> num;
      if (op == 1) {
        if (id > n) {
          continue;
        }
        row[id] = pp(i, num);
      } else {
        if (id > m) {
          continue;
        }
        column[id] = pp(i, num);
      }
    }
    for (int j = 1; j <= n; j++) {
      for (int i = 1; i <= m; i++) {
        if (row[j] < column[i]) {
          cout << column[i].a << " ";
        } else {
          cout << row[j].a << " ";
        }
      }
      cout << '\n';
    }
  }
  return 0;
}
