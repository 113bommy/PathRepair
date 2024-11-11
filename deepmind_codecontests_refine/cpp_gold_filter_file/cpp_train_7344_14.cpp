#include <bits/stdc++.h>
using namespace std;
const int N = 0;
int n, k, x, t, a, b;
string s;
vector<int> v;
int main() {
  cin >> n >> b >> k;
  int sum = 0;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x > b) continue;
    sum += x;
    if (sum > k) {
      sum = 0;
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
