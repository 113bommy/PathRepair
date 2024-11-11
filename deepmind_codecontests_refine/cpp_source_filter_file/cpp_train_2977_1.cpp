#include <bits/stdc++.h>
using namespace std;
template <class T>
bool tmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool tmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
void setIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}
int n, k;
void solve() {
  if (k == 1) {
    cout << n << endl;
    return;
  }
  vector<int> ans;
  for (int f = 2; f <= n && (int)(ans).size() < k; f++) {
    if (n % f != 0) continue;
    while (n % f == 0) {
      ans.push_back(f);
      n /= f;
      if ((int)(ans).size() == k - 1) {
        ans.push_back(n);
        break;
      }
    }
  }
  if ((int)(ans).size() != k)
    cout << "-1\n";
  else {
    for (auto& x : ans) cout << x << " ";
    cout << endl;
  }
}
int main() {
  setIO();
  cin >> n >> k;
  solve();
  return 0;
}
