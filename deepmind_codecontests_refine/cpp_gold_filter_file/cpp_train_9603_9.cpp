#include <bits/stdc++.h>
using namespace std;
bool sortinrev(const pair<long long int, long long int> &a,
               const pair<long long int, long long int> &b) {
  return (a.first > b.first);
}
bool sortbysec(const pair<long long int, long long int> &a,
               const pair<long long int, long long int> &b) {
  return (a.second < b.second);
}
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int a, b, c, d;
    cin >> a >> b >> c >> d;
    long long int ans = 0;
    if (d >= c) {
      if (a <= b) {
        ans = b;
      } else
        ans = -1;
    } else if (d < c) {
      if (a <= b)
        ans = b;
      else if (a > b) {
        ans += b;
        long long int count = 0;
        long long int diff = (c - d);
        long long int need = a - b;
        count += (need / diff);
        long long int rem = need % diff;
        if (rem) count++;
        ans += (count * c);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
