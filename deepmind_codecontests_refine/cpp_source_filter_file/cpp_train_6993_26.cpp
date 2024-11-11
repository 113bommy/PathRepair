#include <bits/stdc++.h>
using namespace std;
int arr[200000];
int num[200001];
int s[200001];
int e[200001];
int p[200001];
vector<pair<int, int>> v;
set<int> sarr[200001];
int find(int a) {
  if (p[a] < 0) return a;
  return p[a] = find(p[a]);
}
void merge(int a, int b) {
  int pa = find(a);
  int pb = find(b);
  if (pa == pb) return;
  p[pa] += p[pb];
  p[pb] = pa;
}
int main() {
  int ans = 0;
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= 200000; i++) p[i] = -1;
  for (int i = 1; i <= 20000; i++) s[i] = e[i] = -1;
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
    num[arr[i]]++;
    if (s[arr[i]] == -1) {
      s[arr[i]] = i;
      v.push_back({i, arr[i]});
    }
    e[arr[i]] = i;
  }
  sort(v.begin(), v.end());
  int start = v[0].first;
  int end = e[v[0].second];
  for (int i = 1; i < v.size(); i++) {
    if (v[i].first < end) {
      merge(v[i - 1].second, v[i].second);
      if (end < e[v[i].second]) end = e[v[i].second];
    } else {
      start = v[i].first;
      end = e[v[i].second];
    }
  }
  for (int i = 1; i <= 200000; i++)
    if (p[i] > 0) sarr[find(i)].insert(i);
  for (int i = 1; i <= 200000; i++) {
    int total = num[i];
    int temp = num[i];
    if (sarr[i].size() > 0) {
      for (auto elem : sarr[i]) {
        if (temp < num[elem]) temp = num[elem];
        total += num[elem];
      }
    }
    ans = ans + total - temp;
  }
  printf("%d", ans);
  return 0;
}
