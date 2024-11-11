#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007LL;
inline long long max(long long a, int32_t b) { return a > b ? a : b; }
inline long long max(int32_t a, long long b) { return a > b ? a : b; }
inline long long min(long long a, int32_t b) { return a < b ? a : b; }
inline long long min(int32_t a, long long b) { return a < b ? a : b; }
long long d4_1[4] = {1, 0, -1, 0};
long long d4_2[4] = {0, 1, 0, -1};
long long d8_1[8] = {1, 1, 1, -1, -1, -1, 0, 0};
long long d8_2[8] = {0, -1, 1, 0, -1, 1, 1, -1};
long long seed;
mt19937 rng(seed = chrono::steady_clock::now().time_since_epoch().count());
inline long long rand(long long l = 0, long long r = 1e18) {
  return uniform_int_distribution<long long>(l, r)(rng);
}
long long solve(vector<long long> v, long long last) {
  long long low = 0;
  long long n = v.size();
  long long high = n - 1;
  long long ans = 0;
  while (low <= high) {
    long long mid = (low + high) / 2;
    if (v[mid] < last) {
      ans = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return v[ans];
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(10);
  long long t = 1;
  while (t--) {
    string s;
    cin >> s;
    string t;
    cin >> t;
    long long n = s.length();
    vector<long long> v[26];
    for (long long i = 0; s[i] != '\0'; i++) {
      v[s[i] - 'a'].push_back(i);
    }
    long long ans[300005] = {0};
    long long j = 0;
    long long index;
    for (long long i = 0; s[i] != '\0'; i++) {
      if (s[i] == t[j]) {
        ans[i] = 1;
        j++;
      }
      if (j == t.length()) {
        index = i;
        break;
      }
    }
    long long result = n - index - 1;
    long long last = n;
    for (long long i = n - 1; i >= 0; i--) {
      if (ans[i] == 1) {
        result = max(result, last - i - 1);
        last = solve(v[s[i] - 'a'], last);
      }
      if (i == 0) {
        result = max(result, last - i);
      }
    }
    cout << result << "\n";
  }
}
