#include <bits/stdc++.h>
using namespace std;
int DEBUG = 1;
vector<int> p, q;
vector<int> fp, fq;
vector<int> a, fa;
int sum(vector<int>& t, int r) {
  int result = 0;
  for (; r >= 0; r = (r & (r + 1)) - 1) result += t[r];
  return result;
}
void inc(vector<int>& t, int i, int delta) {
  for (; i < t.size(); i = (i | (i + 1))) t[i] += delta;
}
int kth(vector<int>& t, int f) {
  int l = 0, r = t.size();
  while (l != r - 1) {
    int m = (l + r) / 2;
    if (sum(t, m) >= f)
      r = m;
    else
      l = m;
  }
  return l;
}
int main() {
  int n;
  scanf("%d", &n);
  a.resize(n), fa.resize(n + 1);
  p.resize(n), q.resize(n), fp.resize(n + 1), fq.resize(n + 1);
  for (int i = 0; i < (int)n; i++) scanf("%d", &p[i]);
  for (int i = 0; i < (int)n; i++) scanf("%d", &q[i]);
  int t = 0;
  for (int i = n - 1; i >= 0; i--) {
    inc(fp, p[i] + 1, 1);
    inc(fq, q[i] + 1, 1);
    int w = (sum(fp, p[i]) + sum(fq, q[i]) + t) % (n - i);
    t = (sum(fp, p[i]) + sum(fq, q[i])) / (n - i);
    a[i] = w;
  }
  for (int i = 0; i < (int)n; i++) inc(fa, i + 1, 1);
  for (int i = 0; i < (int)n; i++)
    a[i] = kth(fa, a[i] + 1), inc(fa, a[i] + 1, -1);
  for (int i = 0; i < (int)n; i++) printf("%d ", a[i]);
  return 0;
}
