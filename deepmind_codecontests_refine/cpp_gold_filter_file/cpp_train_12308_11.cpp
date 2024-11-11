#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> arr;
  arr.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i].first;
    arr[i].second = i;
  }
  vector<int> t;
  t.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  sort(arr.begin(), arr.end());
  long long sum = 0;
  int cur_val = -1;
  long long result = 0;
  multiset<int> times;
  for (int i = 0; i < n;) {
    while (times.size() != 0 && arr[i].first != cur_val) {
      cur_val++;
      auto it = times.end();
      --it;
      sum -= *it;
      result += sum;
      times.erase(it);
    }
    if (times.size() == 0) {
      cur_val = arr[i].first;
    }
    times.insert(t[arr[i].second]);
    sum += t[arr[i].second];
    i++;
    while (i < n && arr[i].first == cur_val) {
      times.insert(t[arr[i].second]);
      sum += t[arr[i++].second];
    }
    cur_val++;
    auto it = times.end();
    --it;
    sum -= *it;
    result += sum;
    times.erase(it);
  }
  while (times.size() != 0) {
    cur_val++;
    auto it = times.end();
    --it;
    sum -= *it;
    result += sum;
    times.erase(it);
  }
  cout << result;
  return 0;
}
