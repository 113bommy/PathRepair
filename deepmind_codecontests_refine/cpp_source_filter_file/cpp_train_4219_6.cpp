#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  long long n, a, ans = 0, c = 0;
  cin >> n >> a;
  vector<long long> v;
  for (int i = 0; i < n; i++) {
    long long x;
    cin >> x;
    v.push_back(x);
  }
  sort(v.rbegin(), v.rend());
  for (int i = 0; i < v.size(); i++) {
    if (a >= ans) {
      ans = ans + v[i];
      c++;
    } else {
      break;
    }
  }
  cout << c << endl;
  return 0;
}
