#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int LN = 21;
const long long mod = 1e9 + 7;
const long long INF = 1LL << 57;
long long n, m, u, v, k, t, q, a, h;
int arr[N], mask[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long sum = 0;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i] >> mask[i];
    sum += arr[i];
  }
  if (sum < 0) {
    for (int i = 1; i <= n; ++i) arr[i] *= -1;
    sum *= -1;
  }
  long long curMask = 0;
  for (long long i = 1; i < (1LL << 62); i *= 2) {
    long long curSum = 0;
    for (int j = 1; j <= n; ++j) {
      if ((i & mask[j]) && (i * 2 > mask[j])) {
        curSum += arr[j];
      }
    }
    if (curSum > 0) {
      curMask |= i;
      for (int j = 1; j <= n; ++j)
        if (i & mask[j]) arr[j] *= -1;
    }
  }
  cout << curMask << endl;
}
