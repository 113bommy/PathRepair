#include <bits/stdc++.h>
using namespace std;
struct cmp {
  bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
    return a.first > b.first;
  }
};
int days[300001];
int arr[300001];
int main() {
  int n, k;
  vector<pair<int, int> > events_list;
  priority_queue<pair<int, int> > q;
  cin >> n >> k;
  long long s = 0;
  for (int i = 1; i <= n; i++) {
    pair<int, int> read;
    read.second = i;
    cin >> read.first;
    events_list.push_back(read);
  }
  for (int i = 0; i < k; i++) {
    q.push(events_list[i]);
  }
  for (int i = k; i < n + k; i++) {
    if (i < n) {
      q.push(events_list[i]);
    }
    auto x = q.top();
    q.pop();
    arr[x.second] = i + 1;
    s += ((arr[x.second] - x.second) * x.first);
  }
  cout << s << endl;
  for (int i = 1; i <= n; i++) {
    cout << arr[i] << " ";
  }
  return 0;
}
