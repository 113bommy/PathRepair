#include <bits/stdc++.h>
using namespace std;
inline long long max2(long long a, long long int b) {
  return (a) > (b) ? (a) : (b);
}
inline long long max3(long long a, long long b, long long c) {
  return (a) > (b) ? ((a) > (c) ? (a) : (c)) : ((b) > (c) ? (b) : (c));
}
inline long long min2(long long a, long long b) {
  return (a) < (b) ? (a) : (b);
}
inline long long min3(long long a, long long b, long long c) {
  return (a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c));
}
using namespace std;
int dr8[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dc8[] = {1, -1, 0, 0, -1, 1, -1, 1};
int dr4[] = {0, 1, -1, 0};
int dc4[] = {1, 0, 0, -1};
long long n;
bool checkHalf(long long k) {
  long long rem = n, use = 0, eat = 0;
  while (rem) {
    use = min(k, rem);
    eat += use;
    rem -= use;
    rem -= rem / 10;
  }
  return eat * 2 >= n;
}
long long binsearch() {
  long long lo = 1, hi = n, mid, ans = -1;
  while (lo <= hi) {
    mid = (lo + hi) / 2;
    if (checkHalf(mid)) {
      ans = mid;
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  long long min_k = binsearch();
  cout << min_k;
}
