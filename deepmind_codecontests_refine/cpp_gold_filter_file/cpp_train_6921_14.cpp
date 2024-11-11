#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v.push_back(x);
  }
  sort(v.begin(), v.end());
  int sum = 0, cnt = 0;
  v[-1] = 0;
  for (int i = 1; i <= n; i++) {
    sum += v[i - 2];
    if (sum <= v[i - 1]) cnt++;
    if (sum > v[i - 1]) sum -= v[i - 1];
  }
  cout << cnt << endl;
}
