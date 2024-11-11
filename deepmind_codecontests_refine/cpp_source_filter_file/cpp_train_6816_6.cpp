#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, m;
  cin >> n >> m;
  long long int i, j, a = 0, cur, flag = 0, M = 10000000009, p;
  string st, check;
  unordered_set<long long int> s;
  for (i = 0; i < n; i++) {
    cin >> st;
    a = 0;
    for (j = 0; j < st.length(); j++) {
      a = (a * 3 + st[j]) % M;
    }
    s.insert(a);
  }
  while (m--) {
    cin >> check;
    a = 0;
    flag = 0;
    for (j = 0; j < check.length(); j++) {
      a = (a * 3 + check[j]) % M;
    }
    p = 1;
    for (i = check.length() - 1; i >= 0; i--) {
      if (check[i] == 'a') {
        if (s.find((a + p) % M) != s.end()) {
          flag = 1;
          break;
        }
        if (s.find((a + p + p) % M) != s.end()) {
          flag = 1;
          break;
        }
      } else if (check[i] == 'b') {
        if (s.find((a + p) % M) != s.end()) {
          flag = 1;
          break;
        }
        if (s.find((a - p + M) % M) != s.end()) {
          flag = 1;
          break;
        }
      } else {
        if (s.find((a - p + M) % M) != s.end()) {
          flag = 1;
          break;
        }
        if (s.find((a - p - p + M) % M) != s.end()) {
          flag = 1;
          break;
        }
      }
      p = (p * 3) % M;
    }
    if (flag == 1)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
