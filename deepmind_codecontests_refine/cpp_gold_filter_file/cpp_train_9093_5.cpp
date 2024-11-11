#include <bits/stdc++.h>
using namespace std;
const int INF = 999999999;
const double EPSILON = 0.00000001;
const long long MOD = 1000000007;
vector<int> a;
int n, h;
int ans[200005];
int idx[200005];
int get_min(int i) {
  int ret = a[0] + a[i];
  if (i > 1) ret = ((ret) < (a[0] + a[1] + h) ? (ret) : (a[0] + a[1] + h));
  if (i > 2) ret = ((ret) < (a[1] + a[2]) ? (ret) : (a[1] + a[2]));
  return ret;
}
int get_max(int j) {
  int ret = a[n - 1] + a[j] + h;
  if (j < n - 2)
    ret = ((ret) > (a[n - 1] + a[n - 2]) ? (ret) : (a[n - 1] + a[n - 2]));
  if (j < n - 3)
    ret = ((ret) > (a[n - 2] + a[n - 3]) ? (ret) : (a[n - 2] + a[n - 3]));
  return ret;
}
int main() {
  int MIN, MAX;
  cin >> n >> h;
  vector<pair<int, int> > stuff;
  for (int i = 0; i < n; i++) {
    int z;
    scanf("%d", &z);
    ;
    stuff.push_back(make_pair(z, i));
  }
  sort(stuff.begin(), stuff.end());
  for (int i = 0; i < n; i++) {
    a.push_back(stuff[i].first);
    idx[stuff[i].second] = i;
  }
  if (n == 2) {
    cout << "0\n1 1\n";
    return 0;
  }
  int bestj = -1;
  int best = a[n - 1] + a[n - 2];
  for (int j = n - 2; j >= 0; j--) {
    MAX = get_max(j);
    if (MAX < best) {
      best = MAX;
      bestj = j;
    }
  }
  int besti = 0;
  best = INF;
  for (int i = 2; i < n; i++) {
    int j;
    if (i < bestj)
      j = bestj;
    else if (i > bestj)
      j = i - 1;
    else if (i == bestj)
      j = i;
    MIN = get_min(i);
    MAX = get_max(j);
    if (MAX - MIN < best) {
      best = MAX - MIN;
      besti = i;
    }
  }
  MIN = ((a[0] + a[1] + h) < (a[1] + a[2]) ? (a[0] + a[1] + h) : (a[1] + a[2]));
  MAX = ((a[n - 1] + a[n - 2]) > (a[n - 1] + a[0] + h) ? (a[n - 1] + a[n - 2])
                                                       : (a[n - 1] + a[0] + h));
  if (MAX - MIN < best) {
    best = MAX - MIN;
    besti = n;
  }
  MIN = a[0] + a[1];
  MAX = a[n - 1] + a[n - 2];
  if (MAX - MIN < best) {
    best = MAX - MIN;
    besti = 1;
    bestj = -1;
  }
  MIN = a[0] + a[1];
  MAX = a[n - 1] + a[1] + h;
  if (n > 3)
    MAX = ((MAX) > (a[n - 1] + a[n - 2]) ? (MAX) : (a[n - 1] + a[n - 2]));
  if (MAX - MIN < best) {
    best = MAX - MIN;
    besti = 1;
    bestj = 1;
  }
  if (besti == n) {
    ans[0] = 1;
    for (int k = 1; k < n; k++) ans[k] = 2;
  } else if (besti == 1) {
    if (bestj == -1) {
      for (int k = 0; k < n; k++) ans[k] = 1;
    } else {
      ans[0] = ans[1] = 1;
      for (int k = 2; k < n; k++) ans[k] = 2;
    }
  } else {
    if (besti < bestj) {
      ans[0] = 1;
      for (int k = 1; k < besti; k++) ans[k] = 2;
      for (int k = besti; k <= bestj; k++) ans[k] = 1;
      for (int k = bestj + 1; k < n; k++) ans[k] = 2;
    } else if (besti > bestj) {
      ans[0] = 1;
      for (int k = 1; k < besti; k++) ans[k] = 2;
      for (int k = besti; k < n; k++) ans[k] = 1;
    } else if (besti == bestj) {
      ans[0] = 1;
      for (int k = 1; k < besti; k++) ans[k] = 2;
      ans[besti] = 1;
      for (int k = besti + 1; k < n; k++) ans[k] = 2;
    }
  }
  cout << best << endl;
  for (int i = 0; i < n; i++) {
    if (i) putchar(' ');
    printf("%d", ans[idx[i]]);
  }
  putchar('\n');
  return 0;
}
