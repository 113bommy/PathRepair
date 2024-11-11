#include <bits/stdc++.h>
using namespace std;
struct Period {
  int l;
  int r;
};
int main() {
  int n, P1, P2, P3, T1, T2;
  Period* p = NULL;
  int result = 0;
  cin >> n;
  cin >> P1 >> P2 >> P3 >> T1 >> T2;
  p = new Period[n];
  for (int i = 0; i < n; ++i) {
    cin >> p[i].l;
    cin >> p[i].r;
  }
  if (n == 1) {
    result = (p[0].r - p[0].l) * P1;
    cout << result;
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    int timeBreak = 0;
    result += (p[i].r - p[i].l) * P1;
    if (i + 1 < n) {
      timeBreak = p[i + 1].l - p[i].r;
      if (timeBreak <= T1) {
        result += timeBreak * P1;
      } else {
        timeBreak -= T1;
        result += T1 * P1;
        if (timeBreak <= T2) {
          result += timeBreak * P2;
        } else {
          result += T2 * P2;
          timeBreak -= T2;
          result += timeBreak * P3;
        }
      }
    }
  }
  cout << result << endl;
  delete[] p;
  return 0;
}
