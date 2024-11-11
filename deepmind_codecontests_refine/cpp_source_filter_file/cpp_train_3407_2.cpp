#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int INF = 0x7fffffff;
long long p[N];
vector<long long> v[N];
int main() {
  long long a[50];
  a[0] = 1;
  for (int i = 1; i < 32; i++) a[i] = a[i - 1] * 2;
  int n;
  scanf("%d", &n);
  set<long long> s;
  for (int i = 0; i < n; i++) {
    scanf("%I64d", &p[i]);
    s.insert(p[i]);
  }
  int pos = -1;
  for (int i = 0; i < n; i++) {
    v[i].push_back(p[i]);
    for (int j = 0; j < 31; j++) {
      if (s.count(p[i] + a[j]) && s.count(p[i] - a[j])) {
        printf("3\n%I64d %I64d %I64d\n", p[i], p[i] + a[j], p[i] - a[j]);
        return 0;
      } else if (s.count(p[i] + a[j]) && s.count(p[i] + a[j + 1])) {
        printf("3\n%I64d %I64d %I64d\n", p[i], p[i] + a[j], p[i] + a[j + 1]);
        return 0;
      } else if (s.count(p[i] - a[j]) && s.count(p[i] - a[j + 1])) {
        printf("3\n%I64d %I64d %I64d\n", p[i], p[i] - a[j], p[i] - a[j + 1]);
        return 0;
      } else if (v[i].size() == 1 && s.count(p[i] - a[j])) {
        v[i].push_back(p[i] - a[j]);
      } else if (v[i].size() == 1 && s.count(p[i] + a[j])) {
        v[i].push_back(p[i] + a[j]);
      }
    }
    if (pos == -1 && v[i].size() == 2) {
      pos = i;
    }
  }
  if (pos == -1) {
    printf("1\n%I64d\n", v[0][0]);
  } else {
    printf("2\nI64d %I64d\n", v[pos][0], v[pos][1]);
  }
}
