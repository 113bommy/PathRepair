#include <bits/stdc++.h>
using namespace std;
long long A[100010];
int mex[1000000 + 2];
bool used[10];
int main() {
  int N = 0;
  cin >> N;
  for (int i = 0; i < (N); ++i) cin >> A[i];
  sort(A, A + N);
  memset(mex, -1, sizeof(mex));
  mex[0] = 0;
  for (int k = 1; k * k <= 1000000; ++k) {
    for (int p2 = (k - 1) * (k - 1) + 1; p2 < k * k; ++p2) {
      if (mex[p2] >= 0) continue;
      mex[p2] = mex[p2 - 1];
    }
    for (int s = k * k - 1; s <= k * k + 1; s++) {
      long double b = sqrt(s);
      long double a = sqrt(b);
      memset(used, 0, sizeof(used));
      for (int x = (int)a; x <= b && x < s; ++x) {
        if (x < a) continue;
        used[mex[x]] = true;
      }
      for (int m = 0; m < 10; ++m) {
        if (!used[m]) {
          mex[s] = m;
          break;
        }
      }
      assert(mex[s] >= 0);
    }
  }
  int ans = 0;
  for (int i = 0; i < (N); ++i) {
    long long s = A[i];
    if (s < 1000000) {
      ans ^= mex[s];
    } else {
      long double b = sqrt(s);
      long double a = sqrt(b);
      memset(used, 0, sizeof(used));
      for (int r = (int)sqrt(a) - 1, x = r * r; x <= b && x < s;
           x = ((x == r * r) ? (x + 1) : (r + 1) * (r + 1)),
               r = (x == (r + 1) * (r + 1) ? (r + 1) : r)) {
        if (x < a) {
          continue;
        }
        assert(mex[x] < 10);
        used[mex[x]] = true;
      }
      int ms = -1;
      for (int m = 0; m < 10; ++m) {
        if (!used[m]) {
          ms = m;
          break;
        }
      }
      assert(ms >= 0);
      ans ^= ms;
    }
  }
  if (ans)
    cout << "Furlo" << endl;
  else
    cout << "Rublo" << endl;
}
