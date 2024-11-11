#include <bits/stdc++.h>
using namespace std;
const int Q = 2e5 + 5;
const int N = 1e5 + 5;
const int MAX = 1e9;
struct node {
  node *left, *right;
  int val;
  node* build(int start, int end) {
    val = 0;
    if (start != end) {
      left = new node, right = new node;
      int mid = (start + end) / 2;
      left = left->build(start, mid), right = right->build(mid + 1, end);
    }
    return this;
  }
  node* update(int start, int end, int x, int v) {
    int mid = (start + end) / 2;
    if (start == end) {
      val = v;
    } else if (x <= mid) {
      left = left->update(start, mid, x, v);
      val = min(left->val, right->val);
    } else {
      right = right->update(mid + 1, end, x, v);
      val = min(right->val, left->val);
    }
    return this;
  }
  int query(int start, int end, int a, int b) {
    int mid = (start + end) / 2;
    if (start >= a && end <= b)
      return val;
    else if (b <= mid)
      return left->query(start, mid, a, b);
    else if (a > mid)
      return right->query(mid + 1, end, a, b);
    else
      return min(left->query(start, mid, a, b),
                 right->query(mid + 1, end, a, b));
  }
};
pair<int, pair<pair<int, int>, pair<int, int>>> queries[Q];
pair<int, int> points[Q];
int ans[Q];
bool cmpQ1(pair<int, pair<pair<int, int>, pair<int, int>>>& a,
           pair<int, pair<pair<int, int>, pair<int, int>>>& b) {
  return a.second.second.second < b.second.second.second;
}
bool cmpQ2(pair<int, pair<pair<int, int>, pair<int, int>>>& a,
           pair<int, pair<pair<int, int>, pair<int, int>>>& b) {
  return a.second.second.first < b.second.second.first;
}
bool cmpP1(pair<int, int>& a, pair<int, int>& b) { return a.second < b.second; }
bool cmpP2(pair<int, int>& a, pair<int, int>& b) { return a.first < b.first; }
int main() {
  int n, m, k, q;
  scanf("%d %d %d %d", &n, &m, &k, &q);
  for (int i = 1; i <= k; i++)
    scanf("%d %d", &points[i].first, &points[i].second);
  for (int i = 1; i <= q; i++)
    scanf("%d %d %d %d", &queries[i].second.first.first,
          &queries[i].second.first.second, &queries[i].second.second.first,
          &queries[i].second.second.second),
        queries[i].first = i;
  sort(points + 1, points + 1 + k, cmpP1);
  sort(queries + 1, queries + 1 + q, cmpQ1);
  node* root = new node;
  root = root->build(1, n);
  int j = 1;
  for (int i = 1; i <= q; i++) {
    while (j <= n && points[j].second <= queries[i].second.second.second) {
      root = root->update(1, n, points[j].first, points[j].second);
      j++;
    }
    int s = root->query(1, n, queries[i].second.first.first,
                        queries[i].second.second.first);
    if (s >= queries[i].second.first.second && s != 1e9) {
      ans[queries[i].first] = 1;
    }
  }
  sort(points + 1, points + 1 + k, cmpP2);
  sort(queries + 1, queries + 1 + q, cmpQ2);
  root = new node;
  root = root->build(1, m);
  j = 1;
  for (int i = 1; i <= q; i++) {
    while (j <= n && points[j].first <= queries[i].second.second.first) {
      root = root->update(1, m, points[j].second, points[j].first);
      j++;
    }
    int s = root->query(1, m, queries[i].second.first.second,
                        queries[i].second.second.second);
    if (s >= queries[i].second.first.first && s != 1e9) {
      ans[queries[i].first] = 1;
    }
  }
  for (int i = 1; i <= q; i++) {
    if (ans[i] == 1)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
