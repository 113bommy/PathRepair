#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, c;
  cin >> a >> c;
  int ans = 0;
  int b[a][c];
  vector<int> m1, m2;
  for (int i = 0; i < a; i++) {
    int k = 0;
    for (int t = 0; t < c; t++) {
      int temp;
      cin >> temp;
      b[i][t] = temp;
      if (temp == 1) {
        k++;
        ans++;
      }
      if (k == c) {
        m1.push_back(i);
      }
    }
  }
  for (int i = 0; i < c; i++) {
    int k = 0;
    for (int t = 0; t < a; t++) {
      if (b[t][i] == 1) {
        k++;
      }
      if (k == a) {
        m2.push_back(i);
      }
    }
  }
  if (m1.empty() == true || m2.empty() == true) {
    if (ans != 0) {
      cout << "NO";
      exit(0);
    } else {
      cout << "YES" << endl;
      for (int i = 0; i < a; i++) {
        for (int t = 0; t < c; t++) {
          cout << b[i][t] << " ";
        }
        cout << endl;
      }
    }
  }
  for (int i = 0; i < a; i++) {
    for (int t = 0; t < c; t++) {
      if (b[i][t] == 1 && find(m1.begin(), m1.end(), i) == m1.end() &&
          find(m2.begin(), m2.end(), t) == m2.end()) {
        cout << "NO";
        exit(0);
      }
      b[i][t] = 0;
    }
  }
  if (m1.empty() != true && m2.empty() != true) {
    cout << "YES" << endl;
    for (int i = 0; i < m2.size(); i++) {
      b[m1[0]][m2[i]] = 1;
    }
    for (int i = 0; i < m1.size(); i++) {
      b[m1[i]][m2[0]] = 1;
    }
    for (int i = 0; i < a; i++) {
      for (int t = 0; t < c; t++) {
        cout << b[i][t] << " ";
      }
      cout << endl;
    }
  }
  return 0;
}
