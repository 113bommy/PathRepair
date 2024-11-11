#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k, x;
  cin >> n >> k >> x;
  string s;
  cin >> s;
  vector<long long> num;
  long long curr = 0;
  for (auto i : s) {
    if (i == '*') {
      curr++;
    } else {
      if (curr != 0) {
        num.push_back(curr * k + 1);
      }
      curr = 0;
    }
  }
  if (curr != 0) {
    num.push_back(curr * k + 1);
  }
  vector<long long> ans;
  long long st = 1;
  for (int i = 0; i < num.size(); i++) {
    long double mul = 1;
    for (int j = i + 1; j < num.size(); j++) mul *= num[j];
    long long now;
    if (mul + st - 1 >= x) {
      now = 0;
    } else {
      now = (x - st) / (long long)mul;
      st += now * mul;
    }
    ans.push_back(now);
  }
  long long u = 0;
  string news = "";
  long long check = 0;
  long long i = 0;
  while (i < n) {
    if (s[i] == 'a') {
      news += 'a';
      i++;
    } else {
      for (int j = 0; j < ans[u]; j++) {
        news += 'b';
      }
      u++;
      while (s[i] == '*') {
        i++;
      }
    }
  }
  cout << news << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
