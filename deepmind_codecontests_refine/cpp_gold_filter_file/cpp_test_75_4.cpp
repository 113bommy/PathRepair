#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
vector<int> v, ans_front, ans_back;
bool dfs(int left = 0, int right = 0, int last = -1) {
  if (left > n - 1 - right) return 0;
  if (v[left] > last && v[n - 1 - right] <= last) {
    int now = ans_front[left];
    now = min(now, n - right - left);
    if (now % 2) return 1;
    return 0;
  }
  if (v[left] <= last && v[n - 1 - right] > last) {
    int now = ans_back[n - 1 - right];
    now = min(now, n - right - left);
    if (now % 2) return 1;
    return 0;
  }
  if (v[left] > last && v[n - 1 - right] > last) {
    if (v[left] >= v[n - 1 - right]) {
      int now = ans_front[left];
      now = min(now, n - left - right);
      if (now % 2) return 1;
      return !dfs(left, right + 1, v[n - 1 - right]);
    }
    int now = ans_back[n - 1 - right];
    now = min(now, n - right - left);
    if (now % 2) return 1;
    return !dfs(left + 1, right, v[left]);
  }
  return 0;
}
int main() {
  cin >> n;
  v.resize(n);
  ans_front.resize(n);
  ans_back.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  int pos = n - 1;
  ans_front[n - 1] = 1;
  for (int i = n - 2; i >= 0; --i) {
    if (v[i] >= v[i + 1]) pos = i;
    ans_front[i] = pos - i + 1;
  }
  pos = 0;
  ans_back[0] = 1;
  for (int i = 1; i < n; ++i) {
    if (v[i] >= v[i - 1]) pos = i;
    ans_back[i] = i - pos + 1;
  }
  if (dfs())
    cout << "Alice\n";
  else
    cout << "Bob\n";
}
