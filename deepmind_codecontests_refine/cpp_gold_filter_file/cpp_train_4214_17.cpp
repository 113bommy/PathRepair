#include <bits/stdc++.h>
using namespace std;
bool is_special(int x1, int x2, int x3, int x4) {
  assert(x1 <= x2 and x2 <= x3 and x3 <= x4);
  int mean = x1 + x2 + x3 + x4;
  int median = (x2 + x3) * 2;
  int range = (x4 - x1) * 4;
  return mean == median and median == range;
}
int main() {
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < (N); ++i) cin >> A[i];
  sort(A.begin(), A.end());
  switch (N) {
    case 0:
      assert(is_special(1, 1, 3, 3));
      cout << "YES" << endl << 1 << endl << 1 << endl << 3 << endl << 3 << endl;
      break;
    case 1: {
      int x1 = A[0];
      assert(is_special(x1, x1, 3 * x1, 3 * x1));
      cout << "YES" << endl << x1 << endl << 3 * x1 << endl << 3 * x1 << endl;
    } break;
    case 2:
      if ((A[0] + A[1]) % 4 == 0 and (A[0] + A[1]) / 4 <= A[0] and
          A[1] <= (A[0] + A[1]) / 4 * 3) {
        int x1 = (A[0] + A[1]) / 4;
        int x4 = 3 * x1;
        assert(is_special(x1, A[0], A[1], x4));
        cout << "YES" << endl << x1 << endl << x4 << endl;
      } else if (3 * A[0] == A[1]) {
        int x2 = 2 * A[0];
        int x3 = 2 * A[0];
        assert(is_special(A[0], x2, x3, A[1]));
        cout << "YES" << endl << x2 << endl << x3 << endl;
      } else if (A[0] <= 4 * A[0] - A[1] and
                 max(4 * A[0] - A[1], A[1]) <= 3 * A[0]) {
        int xt = 4 * A[0] - A[1];
        int x2 = min(xt, A[1]);
        int x3 = max(xt, A[1]);
        assert(is_special(A[0], x2, x3, 3 * A[0]));
        cout << "YES" << endl << xt << endl << 3 * A[0] << endl;
      } else if (0 < 4 * A[1] - 3 * A[0] and (4 * A[1] - 3 * A[0]) % 3 == 0 and
                 A[1] % 3 == 0 and
                 A[1] / 3 <= min(4 * A[1] - 3 * A[0], A[0]) and
                 max(4 * A[1] - 3 * A[0], A[0]) <= A[1]) {
        int x1 = A[1] / 3;
        int xt = (4 * A[1] - 3 * A[0]) / 3;
        int x2 = min(xt, A[0]);
        int x3 = max(xt, A[0]);
        assert(is_special(x1, x2, x3, A[1]));
        cout << "YES" << endl << x1 << endl << xt << endl;
      } else {
        cout << "NO" << endl;
      }
      break;
    case 3:
      if (4 * A[0] == A[1] + A[2]) {
        assert(is_special(A[0], A[1], A[2], A[0] * 3));
        cout << "YES" << endl << (A[0] * 3) << endl;
      } else if (3 * A[0] == A[2]) {
        assert(is_special(A[0], min(A[1], 4 * A[0] - A[1]),
                          max(A[1], 4 * A[0] - A[1]), A[2]));
        cout << "YES" << endl << (4 * A[0] - A[1]) << endl;
      } else if (3 * A[0] + 3 * A[1] == 4 * A[2] and A[2] % 3 == 0) {
        assert(is_special(A[2] / 3, A[0], A[1], A[2]));
        cout << "YES" << endl << (A[2] / 3) << endl;
      } else {
        cout << "NO" << endl;
      }
      break;
    case 4:
      cout << (is_special(A[0], A[1], A[2], A[3]) ? "YES" : "NO") << endl;
      break;
    default:
      assert(false);
  }
  return 0;
}
