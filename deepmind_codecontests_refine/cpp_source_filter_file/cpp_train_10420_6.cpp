#include <bits/stdc++.h>
using namespace std;
void reverse_(vector<int> num) {
  vector<int> a;
  for (int i = num.size() - 1; i > -1; i--) a.push_back(num[i]);
  num = a;
}
int main() {
  int n, x;
  cin >> n >> x;
  vector<int> num(n), used(1e5 + 7, 0), step(1e5 + 7, 1e9);
  set<int> all;
  for (int i = 0; i < n; i++) {
    cin >> num[i];
    used[num[i]] = 1;
    all.insert(num[i]);
  }
  if (all.size() < n) {
    cout << "0\n";
    return 0;
  }
  int ans = 1e9;
  sort(num.begin(), num.end());
  reverse_(num);
  for (int i = 0; i < n; i++) {
    int now = num[i];
    int prev = -1;
    int shag = 0;
    while (now > 0 && prev != now) {
      if (now != num[i]) {
        if (used[now]) {
          ans = min(ans, shag);
        }
      }
      if (step[now] != 1e9) {
        ans = min(step[now] + shag, ans);
      }
      step[now] = min(step[now], shag);
      prev = now;
      now = now & x;
      shag++;
    }
  }
  if (ans == 1e9) {
    cout << "-1\n";
    return 0;
  }
  cout << ans << "\n";
  return 0;
}
