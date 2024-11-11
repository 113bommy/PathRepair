#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int n, m;
    cin >> n >> m;
    vector<string> v;
    string b;
    for (int j = 0; j < n; j++) {
      cin >> b;
      v.push_back(b);
    }
    int count = 0;
    int k = 0;
    int j = 0;
    for (int j = 0; j < m - 1; j++) {
      if (v.at(n - 1).at(j) != 'R') {
        count += 1;
      }
    }
    for (int j = 0; j < n - 1; j++) {
      if (v.at(j).at(m - 1) != 'D') {
        count += 1;
      }
    }
    cout << count << endl;
    v.clear();
  }
  return 0;
}
