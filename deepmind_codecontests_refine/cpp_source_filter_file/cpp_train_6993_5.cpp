#include <bits/stdc++.h>
using namespace std;
const int n = 2e5 + 10;
int N, Q;
vector<int> A;
int maxP[n];
int cnt[n];
int main() {
  cin >> N >> Q;
  A.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    maxP[A[i]] = i + 1;
    cnt[A[i]]++;
  }
  int sum = N;
  int to = 1, maxCnt = 0;
  for (int i = 0; i < N; i++) {
    if (i < to) {
      to = max(to, maxP[A[i]]);
      maxCnt = max(maxCnt, cnt[A[i]]);
    } else {
      sum -= maxCnt;
      maxCnt = 0;
      to = maxP[A[i]];
    }
  }
  sum -= maxCnt;
  cout << sum << endl;
  return 0;
}
