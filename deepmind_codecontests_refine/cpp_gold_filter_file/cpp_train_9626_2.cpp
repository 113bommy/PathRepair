#include <bits/stdc++.h>
using namespace std;
int N, M;
int A[200000], B[200000];
vector<int> v;
bool cmp(pair<int, int> p1, pair<int, int> p2) {
  if (p1.first - p1.second == p2.first - p2.second) return p1.first < p2.first;
  return p1.first - p1.second < p2.first - p2.second;
}
int main() {
  scanf("%d", &N);
  for (int(i) = 0; (i) < (N); (i)++) scanf("%d", &A[i]), v.push_back(A[i]);
  scanf("%d", &M);
  for (int(i) = 0; (i) < (M); (i)++) scanf("%d", &B[i]), v.push_back(B[i]);
  sort(A, A + N);
  sort(B, B + M);
  pair<int, int> res = make_pair(3 * N, 3 * M);
  sort((v).begin(), (v).end());
  (v).erase(unique((v).begin(), (v).end()), (v).end());
  int pa = 0, pbb = 0;
  for (int(i) = 0; (i) < (v.size()); (i)++) {
    while (pa < N && A[pa] == v[i]) pa++;
    while (pbb < M && B[pbb] == v[i]) pbb++;
    res = max(res, make_pair(3 * N - pa, 3 * M - pbb), cmp);
  }
  printf("%d:%d\n", res.first, res.second);
}
