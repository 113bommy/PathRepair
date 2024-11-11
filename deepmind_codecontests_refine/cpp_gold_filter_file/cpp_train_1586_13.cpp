#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<long long, long long> &a,
               const pair<long long, long long> &b) {
  return (a.second < b.second);
}
long long maxSubArraySum(long long a[], long long size) {
  long long max_so_far = INT_MIN, max_ending_here = 0;
  for (long long i = 0; i < size; i++) {
    max_ending_here = max_ending_here + a[i];
    if (max_so_far < max_ending_here) max_so_far = max_ending_here;
    if (max_ending_here < 0) max_ending_here = 0;
  }
  return max_so_far;
}
long long findSubarraySum(long long arr[], long long n, long long sum = 0) {
  unordered_map<long long, long long> prevSum;
  long long res = 0;
  long long currsum = 0;
  for (long long i = 0; i < n; i++) {
    currsum += arr[i];
    if (currsum == sum) res++;
    if (prevSum.find(currsum - sum) != prevSum.end())
      res += (prevSum[currsum - sum]);
    prevSum[currsum]++;
  }
  return res;
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long powmp(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  map<int, int> p;
  while (t--) {
    p.clear();
    long long n, m;
    cin >> n >> m;
    long long a[n];
    for (long long i = 0; i < n; i++) cin >> a[i];
    for (long long i = 0; i < m; i++) {
      long long x;
      cin >> x;
      x--;
      p[x]++;
    }
    int flag = 0;
    for (long long i = 0; i < n - 1; i++) {
      for (long long j = 0; j < n - i; j++) {
        if (a[j] > a[j + 1]) {
          if (p[j] != 0)
            swap(a[j], a[j + 1]);
          else {
            flag++;
            break;
          }
        }
      }
      if (flag) break;
    }
    if (flag)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
}
