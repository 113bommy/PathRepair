#include <bits/stdc++.h>
using namespace std;
const int MAX = 40004;
int code[MAX];
int main() {
  int n, k, t;
  cin >> n >> k;
  for (int i = 0; i < k; ++i) {
    int x, y;
    cin >> t >> x;
    if (t == 1) {
      cin >> y;
      code[y] = 1;
    }
    code[x] = 2;
  }
  int max = 0, min = 0;
  int ant = 1;
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    if (!code[i] && i != n) {
      ++max;
      ++cnt;
    } else {
      if (ant == 1) {
        min += (cnt + 1) / 2;
      } else {
        min += (cnt + 1) / 2;
      }
      cnt = 0;
      ant = code[i];
    }
  }
  cout << min << " " << max << endl;
  return 0;
}
