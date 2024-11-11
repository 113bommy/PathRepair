#include <bits/stdc++.h>
using namespace std;
const int N = 207;
int n, k, check[N], m[N], res;
vector<int> kq;
struct vcl {
  int first;
  int second;
  int vt;
};
bool cmp(vcl a, vcl b) {
  if (a.first == b.first) return a.second < b.second;
  return a.first < b.first;
};
vcl a[N];
int bs(int l, int r, int x) {
  if (a[r].first <= x) return r;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (a[mid].first <= x && a[mid + 1].first > x)
      return mid;
    else if (a[mid].first <= x)
      l = mid + 1;
    else
      r = mid - 1;
  }
  return -1;
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first >> a[i].second;
    m[a[i].first]++;
    m[a[i].second + 1]--;
    a[i].vt = i;
  }
  sort(a + 1, a + 1 + n, cmp);
  for (int i = 1; i <= a[n].second; i++) {
    m[i] += m[i - 1];
  }
  priority_queue<pair<int, int>, vector<pair<int, int> >,
                 greater<pair<int, int> > >
      pq;
  for (int i = 1; i <= a[n].second; i++) {
    if (m[i] <= k) continue;
    int p = bs(1, n, i);
    int del = m[i] - k;
    for (int j = p; j >= 1; j--) {
      if (a[j].second >= i && check[j] == 0) {
        pq.push(pair<int, int>(a[j].second, j));
        if (pq.size() > del) pq.pop();
      }
    }
    while (pq.size() != 0) {
      int r = pq.top().first;
      int pos = pq.top().second;
      check[pos] = 1;
      for (int t = a[pos].first; t <= r; t++) {
        m[t]--;
      }
      pq.pop();
      res++;
      kq.push_back(a[pos].vt);
    }
  }
  cout << res << endl;
  for (int i = 0; i < kq.size(); i++) {
    cout << kq[i] << " ";
  }
}
