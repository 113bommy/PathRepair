#include <bits/stdc++.h>
using namespace std;
long long pwr(long long base, long long p) {
  long long ans = 1;
  while (p) {
    if (p & 1) ans = (ans * base) % (1000000007LL);
    base = (base * base) % (1000000007LL);
    p /= 2;
  }
  return ans;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int d, endPos;
long long arr[30005];
long long DP[30005][350];
map<int, int> jumps;
int reverse_map[5000];
long long dp(int, int);
int main() {
  ios_base::sync_with_stdio(0);
  int i, n;
  cin >> n >> d;
  for (i = 0; i < n; i++) {
    int foo;
    cin >> foo;
    endPos = foo;
    arr[foo]++;
  }
  int maxjump = 0, minjump = 1000000, temp = d, sum = 0;
  while (sum <= endPos) {
    sum += temp;
    temp--;
    if (temp == 0) break;
  }
  minjump = temp;
  if (minjump == 0) minjump++;
  temp = d, sum = 0;
  while (sum <= endPos) {
    sum += temp;
    temp++;
  }
  maxjump = temp + 1;
  int c = 0;
  for (i = minjump; i <= maxjump; i++) {
    c++;
    jumps[i] = c;
    reverse_map[c] = i;
  }
  memset(DP, -1, sizeof(DP));
  long long ans = dp(d, jumps[d]);
  cout << ans;
  return 0;
}
long long dp(int curr, int lastJump) {
  if (curr + reverse_map[lastJump - 1] > endPos) return arr[curr];
  if (DP[curr][lastJump] != -1) return DP[curr][lastJump];
  long long ans = dp(curr + reverse_map[lastJump], lastJump);
  if (lastJump != 1)
    ans = max(ans, dp(curr + reverse_map[lastJump - 1], lastJump - 1));
  ans = max(ans, dp(curr + reverse_map[lastJump + 1], lastJump + 1));
  ans += arr[curr];
  return DP[curr][lastJump] = ans;
}
