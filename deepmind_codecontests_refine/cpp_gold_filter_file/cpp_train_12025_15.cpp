#include <bits/stdc++.h>
using namespace std;
int n = 0, res = 0;
int costs[100001];
int meat[100001];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    meat[i] = a;
    costs[i] = b;
  }
  for (int i = 0; i < n; i++) {
    bool flag = false;
    res += (costs[i] * meat[i]);
    for (int j = i + 1; j < n; j++) {
      if (costs[j] < costs[i]) {
        i = j - 1;
        break;
      }
      res += (costs[i] * meat[j]);
      if (j == n - 1) flag = true;
    }
    if (flag) break;
  }
  cout << res;
}
