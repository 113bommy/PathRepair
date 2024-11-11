#include <bits/stdc++.h>
using namespace std;
long long a[200005];
long long ans[200005];
int n, k, x;
priority_queue<pair<long long, long long>, vector<pair<long long, long long> >,
               greater<pair<long long, long long> > >
    q;
int main() {
  scanf("%d%d%d", &n, &k, &x);
  int sum1 = 0;
  int sum2 = 0;
  int MAX = INT_MIN + 10;
  int MIN = INT_MAX - 10;
  int id1, id2;
  for (int i = 0; i < n; ++i) {
    scanf("%I64d", &a[i]);
    if (a[i] < 0) {
      if (a[i] > MAX) {
        MAX = a[i];
        id1 = i;
      }
      ++sum1;
    }
    if (a[i] >= 0) {
      ++sum2;
      if (a[i] < MIN) {
        MIN = a[i];
        id2 = i;
      }
    }
  }
  if (sum1 % 2) {
    for (int i = 0; i < n; ++i) {
      q.push(make_pair((long long)abs(a[i]), (long long)i));
    }
    while (k--) {
      pair<long long, long long> t = q.top();
      q.pop();
      t.first += x;
      q.push(t);
    }
    while (!q.empty()) {
      pair<long long, long long> t = q.top();
      q.pop();
      if (a[t.second] >= 0)
        ans[t.second] = t.first;
      else
        ans[t.second] = -t.first;
    }
  } else {
    if (MAX == INT_MIN + 10 && MIN == INT_MAX - 10) {
      for (int i = 0; i < n; ++i) {
        if (i < k % n)
          ans[i] = (long long)k / n * x + x;
        else
          ans[i] = (long long)k / n * x;
      }
      ans[0] = -ans[0];
    } else {
      if (MIN <= -MAX && (long long)MIN - (long long)k * x <= 0 ||
          -MAX < MIN && (long long)MAX + (long long)k * x >= 0) {
        if (MIN <= -MAX && (long long)MIN - (long long)k * x <= 0) {
          while (a[id2] >= 0 && k) {
            a[id2] -= x;
            --k;
          }
        } else {
          while (a[id1] <= 0 && k) {
            a[id1] += x;
            --k;
          }
        }
        for (int i = 0; i < n; ++i) {
          q.push(make_pair((long long)abs(a[i]), (long long)i));
        }
        while (k--) {
          pair<long long, long long> t = q.top();
          q.pop();
          t.first += x;
          q.push(t);
        }
        while (!q.empty()) {
          pair<long long, long long> t = q.top();
          q.pop();
          if (a[t.second] >= 0)
            ans[t.second] = t.first;
          else
            ans[t.second] = -t.first;
        }
      } else {
        for (int i = 0; i < n; ++i) {
          q.push(make_pair((long long)abs(a[i]), (long long)i));
        }
        while (k--) {
          pair<long long, long long> t = q.top();
          q.pop();
          t.first -= x;
          q.push(t);
        }
        while (!q.empty()) {
          pair<long long, long long> t = q.top();
          q.pop();
          if (a[t.second] >= 0)
            ans[t.second] = t.first;
          else
            ans[t.second] = -t.first;
        }
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    if (i) printf(" ");
    printf("%I64d", ans[i]);
  }
}
