#include <bits/stdc++.h>
using namespace std;
int A[200002], T[200002];
vector<pair<int, int> > P, B;
vector<int> R;
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &A[i]);
    P.push_back({A[i], i});
  }
  sort(P.begin(), P.end());
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    a--, b--;
    if (A[a] > A[b]) {
      T[a]++;
    } else if (A[a] < A[b]) {
      T[b]++;
    }
  }
  R = vector<int>(n);
  int last = -1, cnt = 0;
  for (int i = 0; i < n; i++) {
    int id = P[i].second;
    R[id] = i - T[id];
    if (P[i].first == last) {
      R[id] -= cnt;
      cnt++;
    } else {
      cnt = 1;
      last = P[i].first;
    }
  }
  for (int i = 0; i < n; i++) printf("%d ", R[i]);
  printf("\n");
}
