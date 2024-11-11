#include <bits/stdc++.h>
using namespace std;
int c[3 * 100000];
int a[3 * 100000];
int main() {
  int n, k;
  cin >> n >> k;
  priority_queue<pair<int, int> > pq;
  for (int i = 0; i < n; i++) {
    int tem;
    cin >> tem;
    c[tem]++;
  }
  for (int i = 0; i <= 2 * 100010; i++) {
    if (c[i]) {
      pq.push(make_pair(c[i], i));
    }
  }
  vector<int> ans;
  for (int i = 0; i < k; i++) {
    pair<int, int> tem = pq.top();
    pq.pop();
    a[tem.second]++;
    ans.push_back(tem.second);
    pq.push(make_pair(tem.first / (a[tem.second] + 1), tem.second));
  }
  for (auto i : ans) cout << i << " ";
  cout << endl;
}
