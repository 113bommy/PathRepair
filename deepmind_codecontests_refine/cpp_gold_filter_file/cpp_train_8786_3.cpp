#include <bits/stdc++.h>
using namespace std;
const unsigned long long N = 100100, INF = 10e10;
int n, arr[N], x, y, all = 0;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    all += arr[i];
  }
  cin >> x >> y;
  int tek = 0;
  for (int i = 0; i < n; i++) {
    if (((tek >= x) && (tek <= y)) && (all - tek >= x) && (all - tek <= y)) {
      cout << i + 1 << endl;
      return 0;
    }
    tek += arr[i];
  }
  cout << 0 << endl;
  return 0;
}
