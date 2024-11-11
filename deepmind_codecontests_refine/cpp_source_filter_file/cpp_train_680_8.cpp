#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[510];
int kk[510];
bool allSame(int l, int r) {
  int num = a[l];
  for (int i = l + 1; i <= r; i++) {
    if (a[i] != num) {
      return false;
    }
  }
  return true;
}
int startIdx(int l, int r) {
  int mx = 0;
  int idx = l;
  for (int i = l; i <= r; i++) {
    bool valid = false;
    if (i > l && a[i] > a[i - 1]) {
      valid = true;
    }
    if (i < r && a[i] > a[i + 1]) {
      valid = true;
    }
    if (valid && a[i] >= mx) {
      mx = a[i];
      idx = i;
    }
  }
  return idx;
}
int main() {
  memset(a, 0, sizeof(a));
  memset(kk, 0, sizeof(kk));
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  scanf("%d", &k);
  for (int i = 1; i <= k; i++) {
    scanf("%d", kk + i);
  }
  vector<pair<int, int> > ranges;
  int idx = 1;
  for (int i = 1; i <= k; i++) {
    int num = kk[i];
    int j = idx - 1;
    while (j < n && num > 0) {
      num -= a[++j];
    }
    if (num != 0) {
      printf("NO\n");
      return 0;
    }
    ranges.push_back(make_pair(idx, j));
    idx = j + 1;
  }
  if (idx != n + 1) {
    printf("NO\n");
    return 0;
  }
  vector<string> ans;
  for (int i = 1; i <= ranges.size(); i++) {
    int l = ranges[i - 1].first, r = ranges[i - 1].second;
    if (l == r) {
      continue;
    }
    if (allSame(l, r)) {
      printf("NO\n");
      return 0;
    }
    int sIdx = startIdx(l, r);
    if (sIdx == l) {
      ans.push_back(to_string(i) + " R");
    } else if (sIdx == r) {
      ans.push_back(to_string(i + r - l) + " L");
      sIdx--;
    } else {
      if (a[sIdx] > a[l]) {
        ans.push_back(to_string(i + sIdx - l) + " L");
        sIdx--;
      } else {
        ans.push_back(to_string(i + sIdx - l) + " R");
      }
    }
    int tot = r - l - 1;
    while (sIdx > l) {
      ans.push_back(to_string(sIdx + i - l) + " L");
      sIdx--;
      tot--;
    }
    while (tot > 0) {
      ans.push_back(to_string(sIdx + i - l) + " R");
      tot--;
    }
  }
  printf("YES\n");
  for (auto& str : ans) {
    printf("%s\n", str.c_str());
  }
}
