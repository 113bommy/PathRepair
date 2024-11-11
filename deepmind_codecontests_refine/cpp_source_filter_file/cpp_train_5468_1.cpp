#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1.01e9;
const double eps = 1e-9;
const int N = 2e5 + 10;
int a[N];
pair<int, int> r[N];
int b[N];
int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  for (int i = 0; (i) < (n); ++i) scanf("%d", a + i);
  for (int i = 0; (i) < (q); ++i) {
    int t, x;
    scanf("%d%d", &t, &x);
    r[x] = make_pair(i + 1, t);
  }
  int last = 0;
  int t = 0;
  for (int i = 0; (i) < (n); ++i) b[i] = a[i];
  multiset<int> second;
  vector<int> v;
  int cnt = n;
  for (int i = n; i >= 1; --i)
    if (r[i].first > last) {
      if (last == 0) {
        last = r[i].first;
        for (int j = 0; (j) < (i); ++j) second.insert(a[j]);
        t = r[i].second;
        cnt = i;
      } else {
        if (t == 2) {
          for (int j = cnt - 1; j >= i; --j) {
            b[j] = *second.begin();
            second.erase(second.begin());
          }
        } else {
          for (int j = cnt - 1; j >= i; --j) {
            b[j] = *second.rbegin();
            second.erase(second.find(b[j]));
          }
        }
        last = r[i].first;
        t = r[i].second;
        cnt = i;
      }
    }
  if (t == 2) {
    for (int j = cnt - 1; j >= 0; --j) {
      b[j] = *second.begin();
      second.erase(second.begin());
    }
  } else {
    for (int j = last - 1; j >= 0; --j) {
      b[j] = *second.rbegin();
      second.erase(second.find(b[j]));
    }
  }
  for (int i = 0; (i) < (n); ++i) printf("%d%c", b[i], " \n"[i + 1 == n]);
  return 0;
}
