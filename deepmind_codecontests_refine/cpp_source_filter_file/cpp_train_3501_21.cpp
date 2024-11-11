#include <bits/stdc++.h>
using namespace std;
struct oper {
  int l;
  int r;
  char c1;
  char c2;
};
int main() {
  int n, m;
  cin >> n >> m;
  string inp;
  cin >> inp;
  vector<oper> a(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i].l >> a[i].r >> a[i].c1 >> a[i].c2;
  }
  for (int i = 0; i < m; i++) {
    for (int j = a[i].l; j <= a[i].r; j++) {
      if (inp[j] == a[i].c1) {
        inp[j] = a[i].c2;
      }
    }
  }
  cout << inp;
  return 0;
}
