#include <bits/stdc++.h>
using namespace std;
stack<pair<int, int> > s;
int a[100005];
int res[100005];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  vector<pair<int, int> > v;
  for (int i = n - 1; i >= 0; i--) {
    if (v.size() == 0) {
      res[i] = -1;
      v.push_back(make_pair(a[i], i));
      continue;
    }
    if (a[i] == v[v.size() - 1].first) {
      res[i] = -1;
      continue;
    }
    if (a[i] < v[v.size() - 1].first) {
      res[i] = -1;
      v.push_back(make_pair(a[i], i));
      continue;
    }
    if (v[0].first < a[i]) {
      res[i] = i - 1;
      continue;
    }
    int l = 0;
    int d = v.size();
    while (l < d) {
      int mid = l + (d - l) / 2;
      if (v[mid].first >= a[i])
        l = mid + 1;
      else
        d = mid;
    }
    res[i] = v[l].second - i - 1;
  }
  for (int i = 0; i < n; i++) {
    if (i != 0) printf(" ");
    printf("%d", res[i]);
  }
  printf("\n");
  return 0;
}
