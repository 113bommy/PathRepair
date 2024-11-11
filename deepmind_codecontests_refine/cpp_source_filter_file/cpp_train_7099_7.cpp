#include <bits/stdc++.h>
using namespace std;
int main() {
  int query;
  cin >> query;
  while (query--) {
    int n;
    cin >> n;
    vector<int> p;
    p.push_back(-1);
    for (int i = 1; i <= n; i++) {
      int temp;
      cin >> temp;
      p.push_back(temp);
    }
    vector<vector<int>> a;
    int count = 0;
    int begin = 1;
    int beginNum = 1;
    while (count != n) {
      vector<int> zanShi;
      int temp1 = begin;
      while (1) {
        int k = temp1;
        temp1 = p[temp1];
        zanShi.push_back(temp1);
        p[k] = -1;
        count++;
        if (temp1 == beginNum) {
          break;
        }
      }
      a.push_back(zanShi);
      for (int i = 1; i <= n; i++) {
        if (p[i] != -1) {
          begin = i;
          break;
        }
      }
      beginNum = begin;
      if (count == n) {
        break;
      }
    }
    for (int i = 0; i < a.size(); i++) {
      int x = a[i].size();
      for (int j = 0; j < x; j++) {
        p[a[i][j]] = x;
      }
    }
    for (int i = 0; i < n; i++) {
      cout << p[i] << " ";
    }
    cout << endl;
  }
}
