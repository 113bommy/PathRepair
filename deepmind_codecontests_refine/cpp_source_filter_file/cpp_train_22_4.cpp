#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int inf = 0x3f3f3f3f;
const long long int infl = 1e18;
long long int din[109][109];
int prv[109][109], t;
struct st {
  int x, y, id;
};
st p[100];
int main() {
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    memset(din, -1, sizeof(din));
    for (int i = 1; i <= n; ++i) {
      cin >> p[i].x >> p[i].y;
      p[i].id = i;
    }
    sort(p, p + n, [](st a, st b) { return a.y < b.y; });
    din[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= k + 1; ++j) {
        if (din[i][j] == -1) {
          continue;
        }
        if (j + 1 <= k) {
          long long int c = din[i][j] + p[i].x + p[i].y * j;
          if (din[i + 1][j + 1] < c) {
            prv[i + 1][j + 1] = j;
            din[i + 1][j + 1] = c;
          }
        }
        long long int c = din[i][j] + p[i].y * (k - 1);
        if (din[i + 1][j] < c) {
          prv[i + 1][j] = j;
          din[i + 1][j] = c;
        }
      }
    }
    int nx = n, ny = k;
    vector<int> A, B;
    while (nx) {
      if (prv[nx][ny] != ny) {
        A.push_back(p[nx - 1].id);
      } else {
        B.push_back(p[nx - 1].id);
      }
      ny = prv[nx][ny];
      nx--;
    }
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    cout << A.size() + B.size() * 2 << "\n";
    for (int i = 0; i < A.size() - 1; ++i) {
      cout << A[i] + 1 << " ";
    }
    for (int i : B) {
      cout << i + 1 << " " << -i - 1 << " ";
    }
    cout << A.back() + 1 << "\n";
  }
}
