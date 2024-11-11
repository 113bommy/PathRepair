#include <bits/stdc++.h>
using namespace std;
vector<int> f(vector<int> v) {
  if (v.size() == 1) {
    return v;
  }
  vector<int> a = v;
  vector<int> b;
  vector<int> ans;
  ans.push_back(0);
  for (int i : v) {
    ans.back() *= 10;
    ans.back() += i;
  }
  for (int i = 1; i < v.size(); i++) {
    b.insert(b.begin(), a.back());
    a.pop_back();
    vector<int> left = f(a);
    vector<int> right = f(b);
    for (int A : left) {
      for (int B : right) {
        ans.push_back(A + B);
        ans.push_back(A - B);
        ans.push_back(A * B);
      }
    }
  }
  sort(ans.begin(), ans.end());
  ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
  return ans;
}
string print(int a, int b) {
  ostringstream os;
  os << a / 1000 << (a / 100) % 10 << (a / 10) % 10 << a % 10;
  os << b / 1000 << (b / 100) % 10 << (b / 10) % 10 << b % 10;
  os << "\n";
  return os.str();
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int> cnt[10000];
  for (int a = 0; a < 10; a++) {
    for (int b = 0; b < 10; b++) {
      for (int c = 0; c < 10; c++) {
        for (int d = 0; d < 10; d++) {
          vector<int> ans = f({a, b, c, d});
          for (int i : ans) {
            if (i >= 0) {
              cnt[a * 1000 + b * 100 + c * 10 + d].push_back(i);
            }
          }
        }
      }
    }
  }
  int k, m;
  cin >> k >> m;
  set<string> ans;
  for (int i = 0; ans.size() != m && i < 10000; i++) {
    for (int j : cnt[i]) {
      if (ans.size() != m) {
        if (abs(k - j) < 10000) {
          if (k - j >= 0) {
            ans.insert(print(k - j, i));
          } else {
            ans.insert(print(j - k, i));
          }
        }
      }
    }
  }
  for (string i : ans) {
    cout << i;
  }
}
