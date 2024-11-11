#include <bits/stdc++.h>
using namespace std;
int n, m;
const int mxN = 2e5 + 10;
vector<int> arr(mxN);
vector<pair<int, int> > offers(mxN);
bool isPossible(int day) {
  vector<int> lst(n, -1);
  for (int i = 0; i < m; i++) {
    if (offers[i].first <= day) {
      lst[offers[i].second] = max(lst[offers[i].second], offers[i].first);
    }
  }
  vector<vector<int> > off(2 * mxN);
  for (int i = 0; i < n; i++) {
    if (lst[i] != -1) {
      off[lst[i]].push_back(i);
    }
  }
  int curr_money = 0;
  vector<int> need = arr;
  for (int i = 0; i <= day; i++) {
    ++curr_money;
    if (i > mxN || off[i].size() == 0) {
      continue;
    }
    for (auto it : off[i]) {
      if (curr_money >= need[it]) {
        curr_money -= need[it];
        need[it] = 0;
      } else {
        need[it] -= curr_money;
        curr_money = 0;
        break;
      }
    }
  }
  return accumulate(need.begin(), need.end(), 0) * 2 <= curr_money;
}
long long int binarySearch(int low, int high) {
  int answer;
  while (high >= low) {
    int mid = (low + high) / 2;
    if (isPossible(mid)) {
      answer = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return answer;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> offers[i].first >> offers[i].second;
    offers[i].first--;
    offers[i].second--;
  }
  cout << binarySearch(1, 2 * mxN) + 1 << "\n";
  return 0;
}
