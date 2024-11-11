#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, a, b, k;
  cin >> n >> a >> b >> k;
  int ans = 0;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    long long x;
    cin >> x;
    if (x <= a)
      ans++;
    else if (x % (a + b) <= a && x % (a + b) != 0)
      ans++;
    else
      v.push_back(x % (a + b));
  }
  int x = v.size();
  for (int i = 0; i < x; i++) {
    if (v[i] == 0)
      v[i] += b;
    else if (v[i] < (a + b) && v[i] > a) {
      v[i] = v[i] - a;
    } else {
    }
  }
  for (int i = 0; i < x; i++) {
    v[i] = ceil((float)v[i] / a);
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < x; i++) {
    if (k >= v[i]) {
      k = k - v[i];
      ans++;
    }
  }
  cout << ans << endl;
}
