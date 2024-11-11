#include <bits/stdc++.h>
using namespace std;
int N;
int A[5002], B[5002];
int pos[5002];
bool compare(const int& i1, const int& i2) { return A[i1] < A[i2]; }
int main() {
  cin.sync_with_stdio(false);
  cin >> N;
  for (int i = 1; i <= N; ++i) {
    cin >> A[i] >> B[i];
    pos[i] = i;
  }
  sort(pos + 1, pos + N + 1, compare);
  int pnow = 0;
  for (int i = 1; i <= N; ++i) {
    int now = i, minnow = 0x3f3f3f3f, maxnow = 0;
    while (now <= N && A[pos[i]] == A[pos[now]]) {
      minnow = min(minnow, B[pos[now]]);
      maxnow = max(maxnow, B[pos[now]]);
      ++now;
    }
    if (minnow >= pnow)
      pnow = maxnow;
    else
      pnow = A[pos[i]];
    i = now - 1;
  }
  cout << pnow << '\n';
}
