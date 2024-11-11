#include <bits/stdc++.h>
using namespace std;
std::hash<std::string> hashString;
struct point {
  long long x, y;
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, c;
  cin >> n >> c;
  if (c == 1) {
    cout << 0;
    return 0;
  }
  vector<long long> a;
  for (int i = 0; i < n; i++) {
    long long k;
    cin >> k;
    a.push_back(k);
  }
  multiset<long long> s;
  vector<long long> ans;
  ans.push_back(a[0]);
  s.insert(a[0]);
  long long sum = a[0];
  for (long long i = 1; i < n; i++) {
    if (i < c - 1) {
      ans.push_back(ans.back() + a[i]);
      s.insert(a[i]);
      sum += a[i];
    } else {
      ans.push_back(a[i] + ans[i - 1]);
      s.insert(a[i]);
      sum += a[i];
      if (i > c - 1 && ans[i] > ans[i - c] + sum - *s.begin() ||
          i == c - 1 && ans[i] > sum - *s.begin()) {
        if (i - c >= 0)
          ans[i] = ans[i - c] + sum - *s.begin();
        else
          ans[i] = sum - *s.begin();
      }
      sum -= a[i - c + 1];
      s.erase(s.find(a[i - c + 1]));
    }
  }
  cout << ans.back();
  return 0;
}
