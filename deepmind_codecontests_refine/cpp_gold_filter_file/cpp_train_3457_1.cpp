#include <bits/stdc++.h>
using namespace std;
vector<int> ad[5005];
int a[5005], b[5005], c[5005];
int last[5005];
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i] >> c[i];
    last[i] = i;
    ad[i].push_back(i);
  }
  while (m--) {
    int u, v;
    cin >> u >> v;
    ad[u - 1].push_back(v - 1);
    last[v - 1] = max(last[v - 1], u - 1);
  }
  priority_queue<int, vector<int>, greater<int>> pq;
  long long int sum = 0;
  bool flag = true;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    while (!pq.empty() && k < a[i]) {
      sum -= pq.top();
      k++;
      pq.pop();
    }
    if (k < a[i]) {
      flag = false;
      break;
    } else {
      k += b[i];
      v.clear();
      for (auto g : ad[i]) {
        if (last[g] == i) {
          v.push_back(c[g]);
        }
      }
      while (!pq.empty()) {
        sum -= pq.top();
        k++;
        v.push_back(pq.top());
        pq.pop();
      }
      sort(v.begin(), v.end());
      reverse(v.begin(), v.end());
      for (int j = 0; j < v.size() && k; j++) {
        pq.push(v[j]);
        k--;
        sum += v[j];
      }
    }
  }
  if (!flag) {
    cout << -1 << endl;
  } else {
    cout << sum << endl;
  }
}
