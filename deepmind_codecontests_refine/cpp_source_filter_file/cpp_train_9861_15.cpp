#include <bits/stdc++.h>
using namespace std;
typedef struct {
  int p, c, idx;
  long long sum;
} Knight;
bool cmp1(const Knight &a, const Knight &b) { return a.p < b.p; }
bool cmp(const Knight &a, const Knight &b) { return a.idx < b.idx; }
int main() {
  int n, k;
  cin >> n >> k;
  vector<Knight> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].p;
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i].c;
    a[i].idx = i;
  }
  sort(a.begin(), a.end(), cmp1);
  priority_queue<int> pq;
  pq.push(-a[0].c);
  if (k != 0) {
    for (int i = 1; i < k; i++) {
      a[i].sum = a[i - i].sum + a[i - 1].c;
      pq.push(-a[i].c);
    }
    int minn = -pq.top();
    long long maxSum = a[k - 1].sum + a[k - 1].c;
    a[k].sum = maxSum;
    if (minn < a[k].c) {
      maxSum -= minn;
      maxSum += a[k].c;
      pq.pop();
      pq.push(-a[k].c);
    }
    for (int i = k + 1; i < n; i++) {
      a[i].sum = maxSum;
      minn = -pq.top();
      if (minn < a[i].c) {
        maxSum -= minn;
        maxSum += a[i].c;
        pq.pop();
        pq.push(-a[i].c);
      }
    }
  }
  sort(a.begin(), a.end(), cmp);
  for (auto x : a) {
    cout << x.c + x.sum << ' ';
  }
  return 0;
}
