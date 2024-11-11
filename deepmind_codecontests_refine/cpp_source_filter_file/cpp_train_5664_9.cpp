#include <bits/stdc++.h>
using namespace std;
int n;
map<int, int> mp;
int a[400000];
int b[400000];
bool cmp(const pair<int, int> a, const pair<int, int> b) {
  return a.first < b.first;
}
map<int, int>::iterator get(int k) {
  return --upper_bound(mp.begin(), mp.end(), make_pair(k, 0), cmp);
}
void doit(int k) {
  map<int, int>::iterator i = get(k);
  if (i->second > k) mp[k + 1] = i->second;
  if (i->first < k) i->second = k - 1;
  mp[k] = k;
  if (k != 1) {
    if (a[k - 1] <= a[k]) {
      i = get(k - 1);
      mp.erase(get(k));
      i->second = k;
    }
  }
  if (k != n) {
    if (a[k] <= a[k + 1]) {
      i = get(k + 1);
      int z = i->second;
      mp.erase(i);
      get(k)->second = z;
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int j;
    scanf("%d", &j);
    b[i + 1] = j;
    a[j] = i;
  }
  mp[1] = 1;
  int cr = a[1];
  int prev = 1;
  for (int i = 2; i <= n; i++)
    if (cr <= a[i]) {
      mp[prev] = i;
      cr = a[i];
    } else {
      cr = a[i];
      prev = i;
      mp[prev] = prev;
    }
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int q, j1, j2;
    scanf("%d%d%d", &q, &j1, &j2);
    if (q == 1)
      printf("%d\n", distance(get(j1), get(j2)) + 1);
    else {
      swap(a[b[j1]], a[b[j2]]);
      swap(b[j1], b[j2]);
      doit(j1);
      doit(j2);
    }
  }
  return 0;
}
