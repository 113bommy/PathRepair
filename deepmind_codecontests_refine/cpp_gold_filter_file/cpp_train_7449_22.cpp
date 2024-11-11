#include <bits/stdc++.h>
using namespace std;
long long n, i, j, ans = 0, k, x;
long long a[1000000], sign[1000000], b[1000000];
vector<pair<long long, long long>> V;
bool check_neg() {
  vector<pair<long long, long long>> pos, neg, zero;
  for (int i = 1; i <= n; i++) {
    if (a[i] > 0)
      pos.push_back({a[i], i});
    else if (a[i] == 0)
      zero.push_back({0LL, i});
    else
      neg.push_back({abs(a[i]), i});
  }
  sort(pos.begin(), pos.end());
  sort(neg.begin(), neg.end());
  sort(zero.begin(), zero.end());
  if (neg.size() % 2 == 0) {
    if (zero.size()) {
      neg.push_back({x, zero[0].second});
      sign[zero[0].second] = -1;
      k--;
      zero.erase(zero.begin());
    } else {
      long long X, index;
      if (neg.size()) X = neg[0].first, index = 1;
      if (pos.size())
        if (X > pos[0].first) X = pos[0].first, index = 2;
      if (X / x + 1 <= k) {
        k = k - X / x - 1;
        X = x - X % x;
      } else
        return false;
      if (index == 1) {
        pos.push_back({X, neg[0].second});
        sign[neg[0].second] = 1;
        neg.erase(neg.begin());
      } else {
        neg.push_back({X, pos[0].second});
        sign[pos[0].second] = -1;
        pos.erase(pos.begin());
      }
    }
  }
  if (zero.size() > k) return false;
  long long z = zero.size() / 2;
  if (z % 2) z++;
  k -= zero.size();
  for (int i = 0; i < zero.size(); i++)
    pos.push_back({x, zero[i].second}), sign[zero[i].second] = 1;
  zero.clear();
  priority_queue<pair<long long, long long>, vector<pair<long long, long long>>,
                 greater<pair<long long, long long>>>
      pq;
  for (auto i : neg) pq.push(i);
  for (auto i : pos) pq.push(i);
  while (k > 0) {
    pair<long long, long long> p = pq.top();
    pq.pop();
    p.first += x;
    k--;
    pq.push(p);
  }
  while (!pq.empty()) {
    pair<long long, long long> p = pq.top();
    pq.pop();
    a[p.second] = p.first;
    if (sign[p.second] == -1) a[p.second] *= -1;
  }
  return true;
}
bool check_zero() {
  for (int i = 1; i <= n; i++) {
    if (a[i] == 0) return true;
    long long X = abs(a[i]);
    if (X % x) continue;
    if (X / x <= k) {
      a[i] = 0;
      return true;
    }
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k >> x;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = a[i];
    V.push_back({abs(a[i]), i});
    if (a[i] > 0) sign[i] = 1;
    if (a[i] < 0) sign[i] = -1;
  }
  if (check_neg()) {
    for (i = 1; i <= n; i++) cout << a[i] << " ", ans += abs(b[i] - a[i]);
    return 0;
  } else if (check_zero()) {
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    return 0;
  }
  sort(V.begin(), V.end());
  V[0].first -= (k * x);
  for (auto i : V) {
    a[i.second] = i.first;
    if (sign[i.second] == -1) a[i.second] = a[i.second] * -1;
  }
  for (int i = 1; i <= n; i++) cout << a[i] << " ";
  return 0;
}
