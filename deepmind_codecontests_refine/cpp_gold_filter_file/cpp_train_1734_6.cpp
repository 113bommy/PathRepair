#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
int N;
vector<int> ans;
vector<int> now;
void f(int digit, set<int> st) {
  if (digit >= 20) return;
  if (st.empty()) {
    if (ans.size() > now.size()) {
      ans = now;
    }
    return;
  }
  bool odd = false;
  for (auto val : st) {
    if (abs(val) % 2 == 1) odd = true;
  }
  set<int> New;
  if (!odd) {
    for (auto val : st) {
      New.insert(val / 2);
    }
    f(digit + 1, New);
    return;
  }
  for (auto val : st) {
    if (abs(val) % 2 == 1) val++;
    val /= 2;
    if (val) New.insert(val);
  }
  now.push_back(-(1 << digit));
  f(digit + 1, New);
  now.pop_back();
  New.clear();
  for (auto val : st) {
    if (abs(val) % 2 == 1) val--;
    val /= 2;
    if (val) New.insert(val);
  }
  now.push_back((1 << digit));
  f(digit + 1, New);
  now.pop_back();
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  set<int> st;
  cin >> N;
  for (int i = 0; i <= 100; i++) ans.push_back(-1);
  for (int i = 1; i <= N; i++) {
    int a;
    cin >> a;
    if (a) st.insert(a);
  }
  f(0, st);
  cout << ans.size() << endl;
  for (auto val : ans) cout << val << " ";
  cout << endl;
  return 0;
}
