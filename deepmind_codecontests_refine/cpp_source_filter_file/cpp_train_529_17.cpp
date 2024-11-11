#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, a, L;
  long long int vis;
  long long int t, l;
  long long int sum_time;
  cin >> n >> L >> a;
  vis = 0;
  l = 0;
  t = 0;
  sum_time = 0;
  while (n--) {
    cin >> t >> l;
    sum_time += (t - vis) / a;
    vis = a + l;
  }
  sum_time += (L - t - l) / a;
  cout << sum_time << endl;
  return 0;
}
