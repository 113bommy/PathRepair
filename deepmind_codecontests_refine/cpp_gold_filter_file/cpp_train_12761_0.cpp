#include <bits/stdc++.h>
using namespace std;
long long INF = 1e9;
long long MOD = 1e9 + 7;
long long N, M, D, a, b;
vector<pair<long long, long long> > A, B;
long long curwgt, cursgf, curindA, curindB, ans;
bool cmp(pair<long long, long long> a, pair<long long, long long> b) {
  if (a.first == b.first) return a.second > b.second;
  return a.first < b.first;
}
int main() {
  cin >> N >> M >> D;
  for (int i = 0; i < N; ++i) {
    cin >> a >> b;
    A.push_back(make_pair(a, b));
  }
  for (int i = 0; i < M; ++i) {
    cin >> a >> b;
    B.push_back(make_pair(a, b));
  }
  sort(A.begin(), A.end(), cmp);
  sort(B.begin(), B.end(), cmp);
  curindA = N - 1;
  curindB = M - 1;
  curwgt = A.back().second + B.back().second;
  cursgf = A.back().first + B.back().first;
  ans = max(ans, cursgf);
  if (curwgt > D) {
    cout << 0;
    return 0;
  }
  while (curindA != 0 && curwgt + A[curindA - 1].second <= D) {
    --curindA;
    curwgt += A[curindA].second;
    cursgf += A[curindA].first;
  }
  while (curindA != N) {
    while (curindB != 0 && curwgt + B[curindB - 1].second <= D) {
      --curindB;
      curwgt += B[curindB].second;
      cursgf += B[curindB].first;
    }
    ans = max(ans, cursgf);
    curwgt -= A[curindA].second;
    cursgf -= A[curindA].first;
    ++curindA;
  }
  cout << ans;
}
