#include <bits/stdc++.h>
using namespace std;
constexpr long long MOD = 1000000007;
constexpr int INF = 0x7f7f7f7f;
constexpr double EPS = 1e-8;
long long fastPow(long long num, long long exp, long long modNum) {
  if (exp == 0) return 1;
  if (exp == 1)
    return num;
  else {
    long long half = fastPow(num, exp / 2, modNum) % modNum;
    if (exp % 2 == 1) {
      return (((half * half) % modNum) * num) % modNum;
    } else {
      return (half * half) % modNum;
    }
  }
}
long long fastPow(long long num, long long exp) {
  if (exp == 0) return 1;
  if (exp == 1)
    return num;
  else {
    long long half = fastPow(num, exp / 2);
    if (exp % 2 == 1) {
      return (((half * half)) * num);
    } else {
      return (half * half);
    }
  }
}
long long getReverse(long long y, long long modNum) {
  return fastPow(y, modNum - 2, modNum) % modNum;
}
long long gcd(long long a, long long b) {
  if (a < b) swap(a, b);
  return (a % b == 0) ? b : gcd(b, a % b);
}
long long find(long long k, vector<long long> &F) {
  return F[k] == k ? k : F[k] = find(F[k], F);
}
template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;
long long up = 0, down = 0;
void update(long long val, bool reversed) {
  if (val > 0) {
    if (!reversed)
      up += val;
    else
      up -= val;
  } else {
    if (!reversed)
      down -= val;
    else
      down += val;
  }
}
void output(long long base) {
  long long sum = base + up;
  if (sum % 2) sum++;
  long long ans = sum / 2;
  ;
  cout << ans << endl;
}
int main(int argn, char **argv) {
  ios::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);
  const long long MOD = 1e9 + 7;
  int T = 1;
  for (int(I) = (0); (I) <= ((T)-1); (I)++) {
    long long n;
    cin >> n;
    vector<long long> arr(n), delta(n + 1);
    for (int(i) = (0); (i) <= ((n)-1); (i)++) {
      cin >> arr[i];
    }
    for (int(i) = (1); (i) <= (n - 1); (i)++) {
      delta[i] = arr[i] - arr[i - 1];
    }
    for (int(i) = (1); (i) <= (n - 1); (i)++) {
      update(delta[i], 0);
    }
    output(arr[0]);
    long long q;
    cin >> q;
    for (int(i) = (0); (i) <= ((q)-1); (i)++) {
      long long l, r, x;
      cin >> l >> r >> x;
      if (l == 1) {
        arr[0] += x;
      }
      if (l > 1) {
        l--;
        update(delta[l], 1);
        delta[l] += x;
        update(delta[l], 0);
      }
      if (r <= n - 1) {
        update(delta[r], 1);
        delta[r] -= x;
        update(delta[r], 0);
      }
      output(arr[0]);
    }
  }
  return 0;
}
