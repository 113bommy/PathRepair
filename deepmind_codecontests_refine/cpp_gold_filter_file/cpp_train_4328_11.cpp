#include <bits/stdc++.h>
using namespace std;
int n, x[1000001], y[1000001];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n;
  vector<int> vec;
  long long sum1 = 0, sum2 = 0;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    sum1 += x[i];
    sum2 += y[i];
  }
  int ans1 = 0, ans2 = 0;
  for (int i = 0; i < n; i++) {
    if (x[i] >= y[i]) {
      ans1++;
    }
  }
  for (int i = 0; i < n; i++) {
    if (x[i] <= y[i]) {
      ans2++;
    }
  }
  if (ans1 == n || ans2 == n) {
    cout << 0;
    return 0;
  }
  int cur = 0;
  for (int i = 0; i < n; i++) {
    cur = max(x[i], y[i]);
    vec.push_back(sum1 - x[i] + cur);
    vec.push_back(sum2 - y[i] + cur);
  }
  int mx = vec[0];
  int in = 0;
  for (int i = 0; i < vec.size(); i++) {
    if (mx < vec[i]) {
      mx = vec[i];
      in = i;
    }
  }
  if ((in + 1) % 2 == 0) {
    cout << (in + 1) / 2;
  } else {
    cout << (in + 1) / 2 + 1;
  }
  return 0;
}
