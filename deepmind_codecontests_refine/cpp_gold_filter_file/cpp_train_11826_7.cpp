#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<long long> v;
  int n;
  cin >> n;
  v.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  long long min = 2000000005;
  int cnt = 0;
  for (int i = 1; i < n; i++) {
    long long val = abs(v[i] - v[i - 1]);
    if (val < min) {
      min = val;
      cnt = 1;
    } else if (val == min) {
      cnt++;
    }
  }
  cout << min << " " << cnt << endl;
  return 0;
}
