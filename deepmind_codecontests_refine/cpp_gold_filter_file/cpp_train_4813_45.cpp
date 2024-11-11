#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    int mnm = 2e9;
    vector<int> vi[(int)1e5 + 100];
    for (int i = 1; i <= 30003; i++) {
      int A, B, C;
      int x = c % i;
      int y = i - x;
      if (y <= x) {
        C = c + y;
      } else
        C = c - x;
      int sq = sqrt(i);
      int mn = 2e9;
      bool f = false;
      for (int I = 1; I <= sq; I++) {
        if (!(i % I)) {
          int d = i / I;
          mn = min(mn, abs(a - d));
          mn = min(mn, abs(a - I));
          f = true;
        }
      }
      if (f) {
        int v = a + mn;
        int k = a - mn;
        if (v && !(i % v)) {
          A = v;
        } else if (k > 0 && !(i % k)) {
          A = k;
        }
        int dif = abs(A - a) + abs(b - i) + abs(C - c);
        mnm = min(mnm, dif);
        if (!vi[mnm].size()) {
          vi[mnm].push_back(A);
          vi[mnm].push_back(i);
          vi[mnm].push_back(C);
        }
      }
    }
    cout << mnm << endl;
    for (auto i : vi[mnm]) {
      cout << i << " ";
    }
    cout << endl;
  }
  return 0;
}
