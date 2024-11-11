#include <bits/stdc++.h>
using namespace std;
const int N = 200 + 10;
bool markA[N];
bool markB[N];
int main() {
  int n, m, x;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    markA[x] = 1;
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> x;
    markB[x] = 1;
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (markA[i] == 1 && markB[j] == 1 && markA[i + j] == 0 &&
          markB[i + j] == 0) {
        cout << i << ' ' << j << endl;
        return 0;
      }
    }
  }
  return 0;
}
