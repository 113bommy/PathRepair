#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  while (cin >> n >> m) {
    int candidate[110];
    memset(candidate, 0, sizeof(candidate));
    for (int i = 0; i < m; i++) {
      int curmax = 0;
      int curcan = 0;
      for (int j = 0; j < n; j++) {
        int temp;
        cin >> temp;
        if (temp > curmax) {
          curmax = temp;
          curcan = j;
        }
      }
      candidate[curcan]++;
    }
    int lastcan = 0;
    int lastvote = candidate[0];
    for (int i = 0; i < n; i++) {
      if (candidate[i] > lastvote) {
        lastvote = candidate[i];
        lastcan = i;
      }
    }
    cout << lastcan + 1;
  }
  return 0;
}
