#include <bits/stdc++.h>
using namespace std;
const int MAX = 300100;
char txt[MAX];
int iSA[MAX], SA[MAX];
int cnt[MAX], nxt[MAX];
bool bh[MAX], b2h[MAX];
bool smaller_first_char(int a, int b) { return txt[a] < txt[b]; }
void suffixSort(int n) {
  for (int i = 0; i < n; ++i) {
    SA[i] = i;
  }
  sort(SA, SA + n, smaller_first_char);
  for (int i = 0; i < n; ++i) {
    bh[i] = i == 0 || txt[SA[i]] != txt[SA[i - 1]];
    b2h[i] = false;
  }
  for (int h = 1; h < n; h <<= 1) {
    int buckets = 0;
    for (int i = 0, j; i < n; i = j) {
      j = i + 1;
      while (j < n && !bh[j]) j++;
      nxt[i] = j;
      buckets++;
    }
    if (buckets == n) break;
    for (int i = 0; i < n; i = nxt[i]) {
      cnt[i] = 0;
      for (int j = i; j < nxt[i]; ++j) {
        iSA[SA[j]] = i;
      }
    }
    cnt[iSA[n - h]]++;
    b2h[iSA[n - h]] = true;
    for (int i = 0; i < n; i = nxt[i]) {
      for (int j = i; j < nxt[i]; ++j) {
        int s = SA[j] - h;
        if (s >= 0) {
          int head = iSA[s];
          iSA[s] = head + cnt[head]++;
          b2h[iSA[s]] = true;
        }
      }
      for (int j = i; j < nxt[i]; ++j) {
        int s = SA[j] - h;
        if (s >= 0 && b2h[iSA[s]]) {
          for (int k = iSA[s] + 1; !bh[k] && b2h[k]; k++) b2h[k] = false;
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      SA[iSA[i]] = i;
      bh[i] |= b2h[i];
    }
  }
  for (int i = 0; i < n; ++i) {
    iSA[SA[i]] = i;
  }
}
int lcp[MAX];
void getlcp(int n) {
  for (int i = 0; i < n; ++i) iSA[SA[i]] = i;
  lcp[0] = 0;
  for (int i = 0, h = 0; i < n; ++i) {
    if (iSA[i] > 0) {
      int j = SA[iSA[i] - 1];
      while (i + h < n && j + h < n && txt[i + h] == txt[j + h] &&
             txt[i + h] != 'z' + 1)
        h++;
      lcp[iSA[i]] = h;
      if (h > 0) h--;
    }
  }
}
int dp[20][MAX];
int lg[MAX];
vector<int> add[MAX];
vector<int> del[MAX];
int get(int st, int en) {
  if (st > en) return 1e9;
  int l = en - st + 1;
  int l1 = lg[l];
  return min(dp[l1][st], dp[l1][en - (1 << l1) + 1]);
}
int main() {
  long long pw = 1, k = 0;
  lg[0] = 0;
  for (int i = 1; i < MAX; i++) {
    if (pw * 2 <= i) pw *= 2, k++;
    lg[i] = k;
  }
  scanf("%s", txt);
  int n = strlen(txt);
  suffixSort(n);
  getlcp(n);
  for (int i = 0; i < n; i++) {
    dp[0][i] = lcp[i];
  }
  int sh = 1;
  for (int j = 1; j < 20; j++) {
    for (int i = 0; i < n; i++) {
      dp[j][i] = min(dp[j - 1][i], dp[j - 1][i + sh]);
    }
    sh <<= 1;
  }
  long long res = 0;
  long long mx = 0;
  bool b = 0;
  long long pr = 0;
  map<int, long long> vis;
  for (int i = 1; i < n; i++) {
    int val = lcp[i];
    if (vis.empty())
      pr = mx = 0;
    else
      mx = (--vis.end())->first, pr = (--vis.end())->second;
    long long mx1 = mx + 1;
    long long pr1 = pr;
    while (!vis.empty() && ((--vis.end())->first) > val) {
      mx = (--vis.end())->first, pr = (--vis.end())->second;
      res += pr1 * (mx1 - mx - 1);
      pr1 = pr;
      mx1 = mx;
      vis.erase(--vis.end());
    }
    if (val < mx) {
      res += pr * (mx - val - 1);
    }
    if (vis.count(val)) {
      continue;
    }
    if (val == 0) {
      continue;
    }
    int le = i - 1;
    int l = 0, h = i, ri = i;
    while (l <= h) {
      int m = (l + h) / 2;
      if (get(m + 1, i) >= val) {
        le = m;
        h = m - 1;
      } else
        l = m + 1;
    }
    l = i, h = n - 1, ri = i;
    while (l <= h) {
      int m = (l + h) / 2;
      if (get(i + 1, m) >= val) {
        ri = m;
        l = m + 1;
      } else
        h = m - 1;
    }
    add[le].push_back(val);
    del[ri + 1].push_back(val);
    pr = ((long long)ri - le + 1) * (ri - le + 2) / 2;
    res += ((long long)ri - le + 1) * (ri - le + 2) / 2;
    vis[val] = pr;
  }
  int val = 0;
  if (vis.empty())
    pr = mx = 0;
  else
    mx = (--vis.end())->first, pr = (--vis.end())->second;
  long long mx1 = mx + 1;
  long long pr1 = pr;
  while (!vis.empty() && ((--vis.end())->first) > val) {
    mx = (--vis.end())->first, pr = (--vis.end())->second;
    res += pr1 * (mx1 - mx - 1);
    pr1 = pr;
    mx1 = mx;
    vis.erase(--vis.end());
  }
  if (val < mx) {
    res += pr * (mx - val - 1);
  }
  multiset<int> st;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < add[i].size(); j++) st.insert(add[i][j]);
    for (int j = 0; j < del[i].size(); j++) st.erase(st.find(del[i][j]));
    res += n - SA[i];
    if (st.size()) res -= *(--st.end());
  }
  cout << res << endl;
  return 0;
}
