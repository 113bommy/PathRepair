#include <bits/stdc++.h>
const long long INF = (1ll) * 1e18;
using namespace std;
void test_case() {
  long long w, h;
  cin >> w >> h;
  long long s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  long long k, a;
  cin >> k;
  for (int j = 0; j < k; j++) {
    cin >> a;
    if (j == 0)
      s1 -= a;
    else if (j == k - 1)
      s1 += a;
  }
  cin >> k;
  for (int j = 0; j < k; j++) {
    cin >> a;
    if (j == 0)
      s2 -= a;
    else if (j == k - 1)
      s2 += a;
  }
  cin >> k;
  for (int j = 0; j < k; j++) {
    cin >> a;
    if (j == 0)
      s3 -= a;
    else if (j == k - 1)
      s3 += a;
  }
  cin >> k;
  for (int j = 0; j < k; j++) {
    cin >> a;
    if (j == 0)
      s4 -= a;
    else if (j == k - 1)
      s4 += a;
  }
  cout << max(max(s1 * h, s2 * h), max(s3 * w, s4 * h));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  auto start = chrono::high_resolution_clock::now();
  int testno = 1;
  cin >> testno;
  for (int i = 1; i <= testno; i++) {
    test_case();
    cout << '\n';
  }
  auto end = chrono::high_resolution_clock::now();
  double time_taken =
      chrono::duration_cast<chrono::nanoseconds>(end - start).count();
  time_taken *= 1e-9;
  cerr << fixed << time_taken << setprecision(9) << " sec" << endl;
  return 0;
}
