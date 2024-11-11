#include <bits/stdc++.h>
using namespace std;
class Solution {
  struct Node {
    long long a, b;
    friend bool operator<(const Node& A, const Node& B) {
      if (A.a != B.a) return A.a > B.a;
      return A.b > B.b;
    }
  };
  static const int N = 100005;
  Node arr[N];
  long long sum[N] = {0}, Find[N];
  long long T, n, m;

 public:
  Solution() { cin >> T; }
  void solve() {
    while (T--) {
      cin >> n >> m;
      for (int i = 1; i <= m; ++i) {
        cin >> arr[i].a >> arr[i].b;
      }
      sort(arr + 1, arr + 1 + m);
      for (int i = 1; i <= m; ++i)
        sum[i] = sum[i - 1] + arr[i].a, Find[i] = arr[i].a;
      long long ans = 0;
      for (int i = 1; i <= m; ++i) {
        long long pos = lower_bound(Find + 1, Find + 1 + m, arr[i].b,
                                    greater<long long>()) -
                        Find - 1;
        if (pos > n)
          ans = max(ans, sum[n]);
        else if (pos < i)
          ans = max(ans, sum[pos] + arr[i].a + (n - pos - 1) * arr[i].b);
        else
          ans = max(ans, sum[pos] + (n - pos) * arr[i].b);
      }
      cout << ans << endl;
    }
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution* solution = new Solution;
  solution->solve();
  delete solution;
  return 0;
}
