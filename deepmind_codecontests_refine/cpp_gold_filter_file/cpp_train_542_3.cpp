#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, Q, a[N], tt[N], pos3[N], pos4[N];
array<int, 3> ans3[N];
array<int, 4> ans4[N];
int main() {
  memset(pos3, 63, sizeof(pos3));
  memset(pos4, 63, sizeof(pos4));
  scanf("%d%d", &n, &Q);
  for (int i = (1); i <= (n); ++i) scanf("%d", &a[i]);
  set<int> S;
  vector<int> mn, mx;
  int l1 = 1, l2 = 1;
  for (int i = n, j; i >= 1; i = j) {
    j = i;
    while (j >= 1 && a[i] == a[j]) --j;
    while (((int)(mn).size()) && a[i] < a[mn.back()]) {
      if (!--tt[mn.back()]) S.insert(mn.back());
      mn.pop_back();
      l1 = 0;
    }
    while (((int)(mx).size()) && a[i] > a[mx.back()]) {
      if (!--tt[mx.back()]) S.insert(mx.back());
      mx.pop_back();
      l2 = 0;
    }
    int k1 = lower_bound(mn.begin(), mn.end(), i,
                         [&](int k1, int k2) { return a[k1] < a[k2]; }) -
             mn.begin() - 1;
    int k2 = lower_bound(mx.begin(), mx.end(), i,
                         [&](int k1, int k2) { return a[k1] > a[k2]; }) -
             mx.begin() - 1;
    pos3[i] = i + max(l1, l2) + 1;
    if (pos3[i] <= n) {
      ans3[i] = {i, pos3[i] - 1, pos3[i]};
    }
    if (k1 != -1 && k2 != -1) {
      auto it = S.upper_bound(max(mn[k1], mx[k2]));
      if (it != S.end()) {
        pos4[i] = *it;
        k1 = *lower_bound(mn.begin(), mn.end(), *it, greater<int>());
        k2 = *lower_bound(mx.begin(), mx.end(), *it, greater<int>());
        ans4[i] = {i, min(k1, k2), max(k1, k2), *it};
      }
    }
    if (pos4[i + 1] < pos4[i]) {
      pos4[i] = pos4[i + 1];
      ans4[i] = ans4[i + 1];
    }
    if (pos3[i + 1] < pos3[i]) {
      pos3[i] = pos3[i + 1];
      ans3[i] = ans3[i + 1];
    }
    mn.push_back(i);
    mx.push_back(i);
    ++l1, ++l2;
    tt[i] += 2;
    for (int k = (i - 1); k >= (j + 1); --k) {
      mn.push_back(k);
      mx.push_back(k);
      ++l1, ++l2;
      tt[k] += 2;
      pos4[k] = pos4[k + 1], ans4[k] = ans4[k + 1];
      pos3[k] = pos3[k + 1], ans3[k] = ans3[k + 1];
    }
  }
  for (int _ = (1); _ <= (Q); ++_) {
    int l, r;
    scanf("%d%d", &l, &r);
    if (pos4[l] <= r) {
      puts("4");
      for (auto x : ans4[l]) printf("%d ", x);
      puts("");
    } else if (pos3[l] <= r) {
      puts("3");
      for (auto x : ans3[l]) printf("%d ", x);
      puts("");
    } else
      puts("0");
  }
  return 0;
}
