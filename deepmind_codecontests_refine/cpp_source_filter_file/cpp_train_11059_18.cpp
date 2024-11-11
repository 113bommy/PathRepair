#include <bits/stdc++.h>
using namespace std;
int main() {
  int test;
  cin >> test;
  while (test) {
    test--;
    string x;
    cin >> x;
    int n = x.size();
    vector<int> visited;
    visited.push_back(0);
    for (int i = 0; i < n; i++) {
      if (x[i] == 'R') {
        visited.push_back(i + 1);
      }
    }
    visited.push_back(n + 1);
    int siza = visited.size();
    int temp1 = -INT_MAX;
    if (!visited.size()) {
      cout << n + 1;
    } else {
      for (int i = 0; i < siza; i++) {
        temp1 = max(temp1, visited[i] - visited[i - 1]);
      }
    }
    cout << temp1 << endl;
  }
}
