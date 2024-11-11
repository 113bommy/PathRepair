#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[100010];
bool mark[100010];
bool fill(const vector<int> &position, int low, int high) {
  if (low >= high) return false;
  if (position.empty()) return true;
  if (low + 1 >= high) return false;
  deque<int> values;
  if (low < 0 && high > 0) {
    values.push_back(0);
    while (values.size() < position.size()) {
      if (values.back() + 1 >= high && values.front() - 1 <= low)
        return false;
      else if (values.front() - 1 <= low ||
               (values.back() + 1 < high && values.back() <= -values.front()))
        values.push_back(values.back() + 1);
      else
        values.push_front(values.front() - 1);
    }
  } else if (high <= 0) {
    values.push_front(high - 1);
    while (values.size() < position.size()) {
      if (values.front() - 1 <= low) return false;
      values.push_front(values.front() - 1);
    }
  } else {
    values.push_back(low + 1);
    while (values.size() < position.size()) {
      if (values.back() + 1 >= high) return false;
      values.push_back(values.back() + 1);
    }
  }
  for (int i = 0; i < position.size(); i++) a[position[i]] = values[i];
  return true;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    if (s == "?")
      mark[i] = true;
    else
      a[i] = strtol(s.c_str(), 0, 10);
  }
  for (int i = 1; i <= k; i++) {
    int low = -2e9;
    vector<int> position;
    for (int j = i;; j += k) {
      if (j > n || !mark[j]) {
        int high;
        if (j <= n)
          high = a[j];
        else
          high = 2e9;
        if (!fill(position, low, high)) {
          cout << "Incorrect sequence\n";
          return 0;
        }
        position.clear();
        low = high;
        if (j > n) break;
      } else
        position.push_back(j);
    }
  }
  for (int i = 1; i <= n; i++) cout << a[i] << " ";
  return 0;
}
