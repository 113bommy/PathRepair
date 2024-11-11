#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
int main() {
  fast();
  map<int, int> m;
  vector<int> v1, v2, v3, v4;
  int n, cou = 0;
  cin >> n;
  string x, y;
  cin >> x >> y;
  for (int i = 0; i < x.size(); i++) {
    if (x[i] != y[i]) {
      if (x[i] == 'a') {
        m[i] = -1;
      } else {
        m[i] = 1;
      }
      v1.push_back(i);
      cou++;
    }
  }
  for (int i = 0; i < v1.size(); i++) {
    if (m[v1[i]] == -1) {
      v3.push_back(v1[i]);
    } else {
      v4.push_back(v1[i]);
    }
  }
  if (cou % 2 != 0) {
    cout << -1;
    return 0;
  } else if (cou == 0) {
    cout << 0;
    return 0;
  }
  if (v3.size() > v4.size()) swap(v3, v4);
  cout << (cou / 2) + min(v3.size(), v4.size()) % 2 << "\n";
  if (v3.size() % 2 != 0) {
    int an = v3[0] + 1;
    v4.push_back(v3[0]);
    cout << an << " " << an << "\n";
    for (int i = 1; i < (v3.size() - 1) / 2; i++) {
      cout << v3[i] + 1 << " " << v3[v3.size() - i] + 1 << "\n";
    }
  } else {
    for (int i = 0; i < v3.size() / 2; i++) {
      cout << v3[i] + 1 << " " << v3[v3.size() - 1 - i] + 1 << "\n";
    }
  }
  for (int i = 0; i < v4.size() / 2; i++) {
    cout << v4[i] + 1 << " " << v4[v4.size() - 1 - i] + 1 << "\n";
  }
}
