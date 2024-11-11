#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, a, b;
  long long sum = 0;
  vector<int> v;
  cin >> n >> a >> b;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    v.push_back(t);
    sum += t;
  }
  double d = (a * v[0]);
  if (d / sum >= b) {
    cout << "0" << endl;
    return 0;
  }
  sort(v.begin(), v.end(), greater<int>());
  for (int i = 1; i < n; i++) {
    sum -= v[i];
    if ((d / sum) > b) {
      cout << i << endl;
      break;
    }
  }
  return 0;
}
