#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, q;
  cin >> n >> k >> q;
  vector<int> mas(n + 1);
  vector<int> st(k, -1);
  for (int i = 1; i <= n; ++i) {
    cin >> mas[i];
  }
  int x, y, z(0);
  for (int i = 0; i < q; ++i) {
    cin >> x >> y;
    if (x == 1) {
      if (z < k) {
        if (z == 0) {
          st[0] = y;
        } else {
          if (mas[st[0]] > mas[y]) {
            for (int j = z; j > 0; --j) {
              st[j] = st[j - 1];
            }
            st[0] = y;
          } else {
            for (int j = z; j > 0; --j) {
              st[j] = st[j - 1];
            }
            st[0] = y;
            for (int j = 1; j < z; ++j) {
              if (mas[st[j]] < mas[st[j - 1]]) {
                swap(st[j], st[j - 1]);
              }
            }
          }
        }
        ++z;
      } else {
        if (mas[st[0]] < mas[y]) {
          st[0] = y;
          for (int j = 1; j < st.size(); ++j) {
            if (mas[st[j]] < mas[st[j - 1]]) {
              swap(st[j], st[j - 1]);
            }
          }
        }
      }
    } else {
      if (z == 0) {
        cout << "NO" << endl;
      } else {
        if (mas[st[0]] <= mas[y]) {
          bool f(false);
          for (int j = 0; j < st.size(); ++j) {
            if (y == st[j]) {
              f = true;
              cout << "YES" << endl;
              break;
            }
          }
          if (!f) cout << "NO" << endl;
        } else {
          cout << "NO" << endl;
        }
      }
    }
  }
  return 0;
}
