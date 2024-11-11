#include <bits/stdc++.h>
using namespace std;
struct triple {
 public:
  int x;
  int y;
  int t;
  triple() {}
  triple(int a, int b, int c) : x(a), y(b), t(c) {}
};
bool dist_possible(triple a, triple b) {
  int dist = abs(a.x - b.x) + abs(a.y - b.y);
  if (abs(a.t - b.t) >= dist) return true;
  return false;
}
int main() {
  int T;
  cin >> T;
  for (int testcases = 0; testcases < T; testcases++) {
    int n, k;
    cin >> n >> k;
    long long arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n, greater<long long>());
    long long mx = 0;
    for (int i = 0; i < k + 1; i++) {
      mx += arr[i];
    }
    long long mn = arr[n - 1];
    if (k > 0) mn = 0;
    cout << mx - mn << endl;
  }
}
