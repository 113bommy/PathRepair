#include <bits/stdc++.h>
using namespace std;
int n;
int a[200005];
int t[200005];
vector<pair<int, int> > v;
priority_queue<int> pq;
bool comp2(pair<int, int>& a, pair<int, int>& b) {
  if (a.first == b.first) return a.second > b.second;
  return a.first < b.first;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  for (int i = 0; i < n; i++) {
    v.push_back({a[i], t[i]});
  }
  sort(v.begin(), v.end(), comp2);
  int cur = 0;
  int inque = 0;
  int sum = 0;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (pq.empty()) {
      if (v[i].first == v[i + 1].first) {
        inque = v[i].first + 1;
        while (v[i].first == v[i + 1].first) {
          pq.push(v[i + 1].second);
          sum += v[i + 1].second;
          i++;
        }
        ans += sum;
      } else {
        continue;
      }
    } else {
      if (inque == v[i].first) {
        pq.push(v[i].second);
        sum += v[i].second;
        continue;
      }
      while (!pq.empty() && inque < v[i].first) {
        int top = pq.top();
        pq.pop();
        sum -= top;
        ans += sum;
        inque++;
      }
      if (!pq.empty()) {
        sum += v[i].second;
        pq.push(v[i].second);
      } else {
        if (v[i].first == v[i + 1].first) {
          inque = v[i].first + 1;
          while (v[i].first == v[i + 1].first) {
            pq.push(v[i + 1].second);
            sum += v[i + 1].second;
            i++;
          }
          ans += sum;
        }
      }
    }
  }
  while (!pq.empty()) {
    sum -= pq.top();
    pq.pop();
    ans += sum;
  }
  cout << ans;
  return 0;
}
