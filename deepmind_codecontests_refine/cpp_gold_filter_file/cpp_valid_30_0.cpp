#include <bits/stdc++.h>
using namespace std;
int f[1000005];
int Find(int first) {
  if (f[first] == first) return first;
  return f[first] = Find(f[first]);
}
int cnt[1000005];
int prime[1000005];
vector<int> v[1000005];
void solve() {
  int n, q;
  scanf("%d %d", &n, &q);
  int a[200005];
  for (int i = 1; i <= 1000000; i++) f[i] = i;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    cnt[a[i]]++;
  }
  fill(prime, prime + 1000005, 1);
  for (int i = 2; i < 1000005; i++) {
    if (prime[i]) {
      for (int j = i * 2; j < 1000005; j += i) prime[j] = 0;
    }
  }
  for (int i = 2; i < 1000005; i++) {
    int last = -1;
    if (prime[i])
      for (int j = i; j < 1000005; j += i) {
        if (cnt[j]) {
          if (last == -1)
            last = Find(j);
          else {
            f[Find(j)] = last;
          }
        }
      }
  }
  for (int i = 2; i < 1000005; i++) {
    int last = -1;
    if (prime[i]) {
      for (int j = i; j < 1000005; j += i) {
        if (cnt[j]) {
          last = Find(j);
          break;
        }
      }
      for (int j = i; j < 1000005; j += i) {
        if (cnt[j - 1]) {
          v[j].push_back(last);
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    v[a[i] + 1].push_back(Find(a[i]));
  }
  vector<pair<int, int> > s;
  for (int i = 1; i <= 1000001; i++) {
    if (v[i].size()) {
      sort(v[i].begin(), v[i].end());
      v[i].resize(unique(v[i].begin(), v[i].end()) - v[i].begin());
      for (int j = 0; j < v[i].size(); j++) {
        for (int k = j + 1; k < v[i].size(); k++) {
          if (v[i][j] < v[i][k])
            s.push_back(make_pair(v[i][j], v[i][k]));
          else {
            s.push_back(make_pair(v[i][k], v[i][j]));
          }
        }
      }
    }
  }
  sort(s.begin(), s.end());
  while (q--) {
    int first, second;
    scanf("%d %d", &first, &second);
    first = Find(a[first]);
    second = Find(a[second]);
    if (first > second) swap(first, second);
    if (first == second)
      printf("0\n");
    else {
      auto it = lower_bound(s.begin(), s.end(), make_pair(first, second));
      if (it != s.end() && *it == make_pair(first, second))
        printf("1\n");
      else
        printf("2\n");
    }
  }
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
