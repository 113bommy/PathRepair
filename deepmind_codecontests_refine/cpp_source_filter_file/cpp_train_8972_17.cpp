#include <bits/stdc++.h>
using namespace std;
int n, b[1005];
long long a[1005];
vector<int> A, B, ansA, ansB;
vector<pair<long long, long long> > tA, tB;
long long qry(int x, int y, int z, int w) {
  printf("%d %d %d %d\n", x, y, z, w);
  fflush(stdout);
  long long ret;
  scanf("%lld", &ret);
  return ret;
}
int main() {
  scanf("%d", &n);
  for (int i = 3; i <= n; i++) {
    if (qry(2, 1, i, 2) == 1)
      A.push_back(i);
    else
      B.push_back(i);
  }
  if (A.size()) {
    int m = A.size();
    for (int i = 0; i < m; i++) a[i] = qry(1, 1, 2, A[i]);
    int pos = -1;
    for (int i = 0; i < m; i++)
      if (pos == -1 || a[i] > a[pos]) pos = i;
    tA.clear();
    tB.clear();
    for (int i = 0; i < m; i++) {
      if (pos == i) continue;
      if (qry(2, 1, A[pos], A[i]) == -1)
        tA.push_back((pair<long long, long long>){a[i], A[i]});
      else
        tB.push_back((pair<long long, long long>){a[i], A[i]});
    }
    sort(tA.begin(), tA.end());
    sort(tB.begin(), tB.end());
    reverse(tB.begin(), tB.end());
    for (auto x : tA) ansA.push_back(x.second);
    ansA.push_back(A[pos]);
    for (auto x : tB) ansA.push_back(x.second);
  }
  if (B.size()) {
    int m = A.size();
    for (int i = 0; i < m; i++) a[i] = qry(1, 1, 2, A[i]);
    int pos = -1;
    for (int i = 0; i < m; i++)
      if (pos == -1 || a[i] > a[pos]) pos = i;
    tA.clear();
    tB.clear();
    for (int i = 0; i < m; i++) {
      if (pos == i) continue;
      if (qry(2, 2, A[pos], A[i]) == -1)
        tA.push_back((pair<long long, long long>){a[i], A[i]});
      else
        tB.push_back((pair<long long, long long>){a[i], A[i]});
    }
    sort(tA.begin(), tA.end());
    sort(tB.begin(), tB.end());
    reverse(tB.begin(), tB.end());
    for (auto x : tA) ansB.push_back(x.second);
    ansB.push_back(A[pos]);
    for (auto x : tB) ansB.push_back(x.second);
  }
  printf("0 1 ");
  for (auto x : ansA) printf("%d ", x);
  printf("2 ");
  for (auto x : ansB) printf("%d ", x);
  puts("");
  return 0;
}
