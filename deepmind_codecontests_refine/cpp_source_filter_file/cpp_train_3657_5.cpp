#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int N, A[500005];
int B[500005];
long long pref[500005];
int cnt[500005];
long long asum;
int check(int D) {
  long long sSum = 0;
  long long numK = 0;
  int ind = 1, indAdd = -1;
  bool added = false;
  for (int i = 0; i <= N + 1; i++) cnt[i] = 0;
  for (int i = 1; i <= N + 1; i++) {
    if (!added && (D >= A[ind] || i == N + 1)) {
      indAdd = ind;
      B[ind++] = D;
      added = true;
    }
    if (i < N + 1) B[ind++] = A[i];
  }
  for (int i = 1; i <= N + 1; i++) pref[i] = pref[i - 1] + B[i];
  for (long long k = N + 1; k >= 1; k--) {
    if (k + 1 <= N + 1) {
      if (B[k + 1] < k) {
        cnt[B[k + 1]]++;
        sSum += B[k + 1];
      } else
        numK++;
    }
    sSum -= cnt[k] * k;
    numK += cnt[k];
    if (pref[k] > k * (k - 1) + sSum + numK * k) {
      if (indAdd <= k)
        return 2;
      else
        return 0;
    }
  }
  return 1;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
    asum += A[i];
  }
  sort(A + 1, A + N + 1);
  reverse(A + 1, A + N + 1);
  int low = -1, high = N + 1;
  while (low + 2 < high) {
    int mid = (low + high) / 2;
    if (mid % 2 != asum % 2) mid++;
    if (check(mid) == 0)
      low = mid;
    else
      high = mid;
  }
  int L = low;
  if (L % 2 != asum % 2) L++;
  if (check(L) != 1) L += 2;
  low = -1;
  high = N + 1;
  while (low + 2 < high) {
    int mid = (low + high) / 2;
    if (mid % 2 != asum % 2) mid++;
    if (check(mid) == 2)
      high = mid;
    else
      low = mid;
  }
  int R = high;
  if (R % 2 != asum % 2) R--;
  if (check(R) != 1) R -= 2;
  if (L > R)
    cout << -1 << endl;
  else {
    for (int i = L; i <= R; i += 2) cout << i << ' ';
    cout << endl;
  }
  return 0;
}
