#include <bits/stdc++.h>
using namespace std;
const long long MAX = 4e6;
vector<long long> vec[200000];
long long N, T, ok, cur = 2, arr[MAX], res[MAX], cnt[MAX], prime[MAX];
void cal() {
  prime[0] = 1;
  prime[1] = 1;
  for (long long A = 2; A < MAX; A++)
    if (!prime[A]) {
      if (A <= 100000) vec[A].push_back(A);
      for (long long B = A + A; B < MAX; B += A) {
        prime[B] = 1;
        if (B <= 100000) vec[B].push_back(A);
      }
    }
  return;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cal();
  cin >> N;
  for (long long A = 1; A <= N; A++) cin >> arr[A];
  for (long long A = 1; A <= N; A++) {
    if (ok == 0)
      for (auto B : vec[arr[A]]) {
        cnt[B]++;
        if (cnt[B] > 1) ok = 1;
      }
    if (ok == 0)
      res[A] = arr[A];
    else if (ok == 1) {
      for (auto B : vec[arr[A]]) cnt[B]--;
      cur = arr[A] + 1;
      while (true) {
        T = 0;
        for (auto B : vec[cur]) T += cnt[B];
        if (T == 0) {
          res[A] = cur;
          for (auto B : vec[cur]) cnt[B]++;
          break;
        }
        cur++;
      }
      cur = 2;
      ok = 2;
    } else {
      while ((prime[cur]) or (cnt[cur])) cur++;
      res[A] = cur++;
    }
  }
  for (long long A = 1; A <= N; A++) cout << res[A] << " ";
  return 0;
}
