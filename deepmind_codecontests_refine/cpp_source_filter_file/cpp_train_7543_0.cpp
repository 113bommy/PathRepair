#include <bits/stdc++.h>
using namespace std;
int n;
int A[100005];
int B[100005];
int C[100005];
long long lef = 0;
long long righ = 0;
int get(long long &ans) {
  for (int i = 0; i < n; i++) {
    if (n % 2 == 1 && i == n / 2) {
      if ((B[A[i]] + C[A[i]]) % 2 == 0) break;
      B[A[i]]--;
    }
    if (i < n / 2) {
      B[A[i]]--;
      C[A[i]]++;
      if (B[A[i]] < C[A[i]]) break;
    } else if (i > n / 2) {
      if (A[i] != A[n - i - 1]) break;
    }
    ans++;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> A[i], B[A[i]]++;
  bool git = true;
  for (int i = 0; i < n / 2; i++)
    if (A[i] != A[n - i - 1]) git = false;
  if (git) {
    cout << (long long)(n + 1) * n / 2 << endl;
    return 0;
  }
  long long cnt = 0;
  for (int i = 1; i <= n; i++) cnt += B[i] % 2, B[i] = 0;
  if ((n % 2 == 1 && cnt > 1) || (n % 2 == 0 && cnt > 0)) {
    cout << 0 << endl;
    return 0;
  }
  cnt = 0;
  for (int i = 0; i < n / 2; i++) {
    if (A[i] == A[n - i - 1])
      cnt++;
    else
      break;
  }
  lef = righ = cnt + 1;
  for (int i = cnt; i < n - cnt; i++) {
    A[i - cnt] = A[i];
  }
  n = (n - cnt) - (cnt + 1) + 1;
  for (int i = 0; i < n; i++) B[A[i]]++;
  get(lef);
  memset(B, 0, sizeof(B));
  memset(C, 0, sizeof(C));
  for (int i = 0; i < n; i++) B[A[i]]++;
  reverse(A, A + n);
  get(righ);
  cout << lef * (cnt + 1) + righ * (cnt + 1) - (cnt + 1) * (cnt + 1) << endl;
}
