#include <bits/stdc++.h>
using namespace std;
void fastio() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
template <typename T>
T POW(T B, T P) {
  if (P == 0) return 1;
  if (P & 1)
    return B * POW(B, P - 1);
  else
    return (POW(B, P / 2)) * (POW(B, P / 2));
}
long long powmod(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % 1000000007;
    a = a * a % 1000000007;
    b >>= 1;
  }
  return ans;
}
long long prime[1000000];
bool visprime[1000000];
void sieve() {
  int k = 0;
  for (int i = 2; i * i <= 1000000; i++) {
    if (visprime[i] == false) {
      for (int j = i * i; j <= 1000000; j += i) {
        visprime[j] = true;
      }
    }
  }
  for (int i = 2; i <= 1000000; i++) {
    if (visprime[i] == false) prime[k++] = i;
  }
}
int main() {
  int n, k;
  cin >> n >> k;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  int cnt = 0;
  int mx = -1;
  if (k == 1) return cout << 0 << endl, 0;
  for (int i = 1; i < n; i++) {
    if (arr[i] != arr[i - 1])
      cnt++;
    else {
      mx = max(cnt, mx);
      cnt = 1;
    }
  }
  mx = max(cnt, mx);
  cout << mx << endl;
}
