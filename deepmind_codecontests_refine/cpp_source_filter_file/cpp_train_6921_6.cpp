#include <bits/stdc++.h>
using namespace std;
void fastio() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  fastio();
  vector<int> vec;
  long long int n, cnt = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    long long int x;
    cin >> x;
    vec.push_back(x);
  }
  sort(vec.begin(), vec.end());
  long long int ans = 0;
  for (int i = 0; i < n; i++) {
    if (ans <= vec[i]) {
      ans += vec[i];
      cnt++;
    }
  }
  if (n == 1)
    cout << 0;
  else
    cout << cnt;
  return 0;
}
