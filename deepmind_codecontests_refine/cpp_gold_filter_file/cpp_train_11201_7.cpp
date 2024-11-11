#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  int n, a, b;
  cin >> n;
  string ans = "unrated";
  vector<int> vec;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    if (a != b) {
      ans = "rated";
    }
    vec.push_back(b);
  }
  vector<int> vec2;
  for (int i = n - 1; i >= 0; i--) {
    vec2.push_back(vec[i]);
  }
  sort(vec.begin(), vec.end());
  if (ans == "unrated") {
    ans = "maybe";
    for (int i = 0; i < n; i++) {
      if (vec[i] != vec2[i]) {
        ans = "unrated";
      }
    }
  }
  cout << ans;
}
