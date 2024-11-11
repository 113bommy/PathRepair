#include <bits/stdc++.h>
using namespace std;
const int N = 110, INF = 1000000000;
;
int n, m;
long long y;
int a[N], b[N];
const int M = 16;
int order[M];
long long bit[1 << M];
long long count(int s) {
  vector<int> v;
  for (int i = 0; i < (int)(n); ++i) v.push_back(i);
  for (int i = 0; i < (int)(s); ++i) v[order[i]] = INF;
  sort(v.begin(), v.end());
  memset(bit, 0, sizeof(bit));
  int n2 = n - s;
  bit[0] = 1;
  for (int bi = 1; bi < (1 << n2); bi++) {
    int ct = 0;
    for (int j = 0; j < (int)(n2); ++j) {
      if (bi & (1 << j)) ct++;
    }
    int e = v[ct - 1];
    assert(e != INF);
    long long ans = 0;
    for (int j = 0; j < (int)(n2); ++j) {
      int d = (1 << j);
      if ((bi & d) == 0) continue;
      int b2 = bi - d;
      bool valid = true;
      for (int k = 0; k < (int)(m); ++k) {
        if (a[k] == s + j) {
          if (b[k] < s) {
            if (order[b[k]] < e) {
              valid = false;
            }
          } else if (bi & (1 << (b[k] - s))) {
            valid = false;
          } else {
          }
        } else if (b[k] == s + j) {
          if (a[k] < s) {
            if (order[a[k]] > e) {
              valid = false;
            }
          } else if (bi & (1 << (a[k] - s))) {
          } else {
            valid = false;
          }
        }
        if (not valid) break;
      }
      if (!valid) continue;
      ans += bit[b2];
    }
    bit[bi] = ans;
  }
  long long res = bit[(1 << n2) - 1];
  return res;
}
int main() {
  scanf("%d%I64d%d", &n, &y, &m);
  for (int i = 0; i < (int)(m); ++i)
    scanf("%d%d", a + i, b + i), a[i]--, b[i]--;
  y -= 2001;
  long long ct = count(0);
  if (y >= ct) {
    printf("The times have changed\n");
  } else {
    vector<int> v;
    for (int i = 0; i < (int)(n); ++i) v.push_back(i);
    v.push_back(INF);
    for (int i = 0; i < (int)(n); ++i) {
      for (int j = 0; v[j] != INF; j++) {
        int vj = v[j];
        order[i] = vj;
        v[j] = INF;
        sort(v.begin(), v.end());
        long long d = count(i + 1);
        if (y >= d)
          y -= d;
        else {
          break;
        }
        assert(v.back() == INF);
        order[i] = INF;
        v.back() = vj;
        sort(v.begin(), v.end());
      }
    }
    for (int i = 0; i < (int)(n); ++i) printf("%d ", order[i] + 1);
    printf("\n");
  }
  return 0;
}
