#include <bits/stdc++.h>
using namespace std;
bool HasBit(int x, int pos) { return ((x >> pos) & 1); }
int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int n;
    cin >> n;
    int ans = 0;
    for (int b = 0; b <= 8; b++) {
      vector<int> A, B;
      for (int i = 0; i < n; i++) {
        if (HasBit(i, b)) {
          A.push_back(i);
        } else {
          B.push_back(i);
        }
      }
      if (A.empty() || B.empty()) continue;
      printf("%d %d ", (int)A.size(), (int)B.size());
      for (int a : A) {
        printf("%d ", a + 1);
      }
      for (int b : B) {
        printf("%d ", b + 1);
      }
      printf("\n");
      fflush(stdout);
      int x;
      cin >> x;
      ans = max(ans, x);
    }
    printf("-1 %d\n", ans);
    fflush(stdout);
  }
}
