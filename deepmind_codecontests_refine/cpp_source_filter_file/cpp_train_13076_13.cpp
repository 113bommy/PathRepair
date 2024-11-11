#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s[n];
  bool sched[n][7];
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    for (int q = 0; q < 7; q++) {
      sched[i][q] = s[i][q];
    }
  }
  int MAX = 0;
  for (int i = 0; i < 7; i++) {
    int cnt = 0;
    for (int q = 0; q < n; q++) {
      if (sched[q][i]) {
        cnt++;
      }
    }
    if (cnt > MAX) {
      MAX = cnt;
    }
  }
  cout << MAX;
}
