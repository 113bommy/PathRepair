#include <bits/stdc++.h>
using namespace std;
int offset[] = {1, 0, -1, 0, 1};
long long int n, a, r, m;
long long int sum = 0;
long long int cost(long long int h, vector<long long int> &v) {
  long long int req = n * h;
  long long int temp = 0;
  if (req >= sum) {
    temp += a * (req - sum);
    for (long long int i = n - 1; i >= 0; i--) {
      if (v[i] > h)
        temp += (v[i] - h) * m;
      else
        break;
    }
  } else {
    temp += r * (sum - req);
    for (long long int i = 0; i < n; i++) {
      if (v[i] < h)
        temp += (h - v[i]) * m;
      else
        break;
    }
  }
  return temp;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> a >> r >> m;
  m = min(m, a + r);
  vector<long long int> v(n);
  for (long long int i = 0; i < n; i++) cin >> v[i], sum += v[i];
  sort(v.begin(), v.end());
  long long int low = 0, high = 1e18;
  while (low < high) {
    long long int mid = (low + high) / 2;
    if (cost(mid, v) < cost(mid + 1, v))
      high = mid;
    else
      low = mid + 1;
  }
  cout << cost(low, v) << endl;
  return 0;
}
