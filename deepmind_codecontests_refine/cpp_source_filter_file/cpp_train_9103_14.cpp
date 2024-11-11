#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > ans1, ans2;
void maxSum1(int n, int a[]) {
  int i, j;
  for (i = 0; i < n; ++i) {
    for (j = i + 1; j < n; ++j) {
      if (a[i] < (a[i] ^ a[j])) {
        a[i] ^= a[j];
        ans1.push_back(make_pair(i, j));
      }
    }
    for (j = i + 1; j < n; ++j) {
      if (a[j] > (a[i] ^ a[j])) {
        a[j] ^= a[i];
        ans1.push_back(make_pair(j, i));
      }
    }
  }
  for (i = n - 1; i >= 0; --i) {
    for (j = i + 1; j < n; ++j) {
      if (a[i] > (a[i] ^ a[j])) {
        a[i] ^= a[j];
        ans1.push_back(make_pair(i, j));
      }
    }
  }
}
int id[10005];
int a[10005], b[10005];
int has[33];
bool cmp(int i, int j) { return a[i] > a[j]; }
void maxSum2(int n, int a[]) {
  int i, j;
  for (i = 0; i < n; ++i) {
    for (j = i + 1; j < n; ++j) {
      if (a[id[i]] < (a[id[i]] ^ a[id[j]])) {
        a[id[i]] ^= a[id[j]];
        ans2.push_back(make_pair(id[i], id[j]));
      }
    }
    for (j = i + 1; j < n; ++j) {
      if (a[id[j]] > (a[id[i]] ^ a[id[j]])) {
        a[id[j]] ^= a[id[i]];
        ans2.push_back(make_pair(id[j], id[i]));
      }
    }
  }
  for (i = n - 1; i >= 0; --i) {
    for (j = i + 1; j < n; ++j) {
      if (a[id[i]] > (a[id[i]] ^ a[id[j]])) {
        a[id[i]] ^= a[id[j]];
        ans2.push_back(make_pair(id[i], id[j]));
      }
    }
  }
}
int main() {
  int n, i, j, k;
  while (scanf("%d", &n) != EOF) {
    for (i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (i = 0; i < n; ++i) scanf("%d", &b[i]);
    ans1.clear();
    maxSum1(n, a);
    memset(has, 0, sizeof(has));
    for (i = 0; i < n; ++i) {
      for (j = 0; j < 30; ++j) {
        if (1 & (b[i] >> j)) has[j] = 1;
      }
    }
    for (i = 0; i < n; ++i) {
      for (j = 30; j >= 0; --j) {
        if (1 & (a[i] >> j)) {
          break;
        }
      }
      if (j >= 0 && has[j] == 0) {
        a[i] = 0;
        ans1.push_back(make_pair(i, i));
      }
    }
    ans2.clear();
    for (i = 0; i < n; ++i) id[i] = i;
    sort(id, id + n, cmp);
    maxSum2(n, b);
    for (i = 0; i < n; ++i) {
      for (k = 30; k >= 0; --k) {
        if (a[id[i]] & (1 << k)) break;
      }
      if (k >= 0 && (b[id[i]] & (1 << k)) == 0) {
        a[id[i]] = 0;
        ans1.push_back(make_pair(id[i], id[i]));
      }
      a[id[i]] ^= b[id[i]];
      for (j = i + 1; j < n && a[id[i]]; ++j) {
        if (a[id[i]] ^ a[id[j]] < a[id[i]]) {
          a[id[i]] ^= a[id[j]];
          ans1.push_back(make_pair(id[i], id[j]));
        }
      }
    }
    for (i = 0; i < n; ++i) {
      if (a[i] != 0) break;
    }
    if (i != n)
      puts("-1");
    else {
      printf("%d\n", ans1.size() + ans2.size());
      for (i = 0; i < ans1.size(); ++i) {
        printf("%d %d\n", ans1[i].first + 1, ans1[i].second + 1);
      }
      for (i = ans2.size() - 1; i >= 0; --i) {
        printf("%d %d\n", ans2[i].first + 1, ans2[i].second + 1);
      }
    }
  }
}
