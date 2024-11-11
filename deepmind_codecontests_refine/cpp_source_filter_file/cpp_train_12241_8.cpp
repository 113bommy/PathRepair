#include <bits/stdc++.h>
using namespace std;
string s;
stack<int> st;
int a[105], ch[105][105];
int main() {
  int i, j, k, n, t, c = 0, mx = -1, m, r;
  cin >> n >> s;
  for (i = 0; i < n; i++) {
    if (s[i] == '[') {
      st.push(i);
      c++;
    } else {
      t = st.top();
      st.pop();
      a[t] = c;
      a[i] = c;
      c--;
    }
    mx = max(mx, c);
  }
  r = 2 * mx + 1;
  c = 0;
  for (i = 0; i < n; i++) {
    if (s[i] == '[') {
      int x = a[i] - 1;
      for (j = x; j < r - x; j++) {
        if (j == x || j == r - x - 1) {
          ch[j][c] = 1;
          ch[j][c + 1] = 2;
        } else {
          ch[j][c] = 3;
        }
      }
      c++;
    } else {
      if (s[i - 1] == '[') {
        c += 3;
      }
      int x = a[i] - 1;
      for (j = x; j < r - x; j++) {
        if (j == x || j == r - x - 1) {
          ch[j][c] = 1;
          ch[j][c - 1] = 2;
        } else {
          ch[j][c] = 3;
        }
      }
      c++;
    }
  }
  for (i = 0; i < r; i++) {
    for (j = 0; j < c; j++) {
      if (ch[i][j] == 0) {
        cout << " ";
      } else if (ch[i][j] == 1) {
        cout << "+";
      } else if (ch[i][j] == 2) {
        cout << "-";
      } else if (ch[i][j] == 3) {
        cout << "|";
      }
    }
    cout << "\n";
  }
  return 0;
}
