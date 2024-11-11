#include <bits/stdc++.h>
using namespace std;
vector<int> wholesquares;
int age(int i) {
  int low = 0, high = wholesquares.size() - 1, mid, ans;
  while (low <= high) {
    mid = (low + high) / 2;
    if (wholesquares[mid] <= i) {
      low = mid + 1;
      ans = mid;
    } else {
      high = mid - 1;
    }
  }
  return ans;
}
bool cmp(pair<int, int> &a, pair<int, int> &b) {
  return a.first < b.first or a.second > b.second;
}
int pore(int i) {
  int low = 0, high = wholesquares.size() - 1, mid, ans;
  while (low <= high) {
    mid = (low + high) / 2;
    if (wholesquares[mid] > i) {
      high = mid - 1;
      ans = mid;
    } else {
      low = mid + 1;
    }
  }
  return ans;
}
int main() {
  for (int i = 0; i * i <= 1e9; i++) wholesquares.push_back(i * i);
  wholesquares.push_back(31623 * 31623);
  int n;
  scanf("%d", &n);
  int a[n];
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  vector<pair<int, int>> dist;
  for (int i = 0; i < n; i++) {
    int x = age(a[i]);
    int y = pore(a[i]);
    int mn = min(a[i] - wholesquares[x], wholesquares[y] - a[i]);
    if (mn == 0) {
      if (a[i])
        dist.push_back({mn, 1});
      else
        dist.push_back({mn, 2});
    } else {
      dist.push_back({mn, 0});
    }
  }
  sort(dist.begin(), dist.end(), cmp);
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    if (i < n / 2)
      sum += dist[i].first;
    else
      sum += dist[i].second;
  }
  printf("%lld\n", sum);
}
