#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > A;
int ANS[101000];
int main() {
  int N;
  scanf("%d", &N);
  A.resize(N);
  for (int i = 0; i < N; i++) {
    A[i].second = i;
    scanf("%d", &A[i].first);
  }
  sort(A.begin(), A.end());
  int prev = 0;
  int count = 1000;
  int maxx = 1000;
  bool ok = 1;
  int maxcount = -1;
  for (int i = 0; i < N; i++) {
    if ((A[i].first != prev && count > maxx) || A[i].first > prev + 1) {
      ok = 0;
      break;
    }
    if (A[i].first == prev + 1) {
      maxx = count;
      count = 0;
      prev = A[i].first;
    }
    count++;
    ANS[A[i].second] = count;
    maxcount = max(maxcount, count);
  }
  if (count > maxx) ok = 0;
  if (ok) {
    printf("%d\n", maxcount);
    for (int i = 0; i < N; i++) printf("%d ", ANS[i]);
    printf("\n");
  } else
    printf("-1\n");
}
