#include <bits/stdc++.h>
using namespace std;
const int INF = ~(1 << 31);
int main() {
  long long n, m;
  cin >> n >> m;
  vector<pair<long long, long long> > arr(m);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    arr[i] = pair<long long, long long>(b, a);
  }
  sort(arr.rbegin(), arr.rend());
  long long cnt = 0;
  long long at = 0;
  while (at != m) {
    if (arr[at].second >= n) {
      cnt += n * arr[at].first;
      cout << cnt << endl;
      return 0;
    }
    cnt += arr[at].second * arr[at].first;
    n -= arr[at].second;
    at++;
  }
  cout << cnt << endl;
}
