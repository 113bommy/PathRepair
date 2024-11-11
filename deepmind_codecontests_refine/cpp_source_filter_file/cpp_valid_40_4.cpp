#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const double eps = 1e-9;
const double pi = acos(-1);
const int inf = 0x3f3f3f3f;
void Print(vector<string> v) {
  for (auto i : v) cout << i << endl;
}
bool lexo_inc(string a, string b) { return a < b; }
bool lexo_dec(string a, string b) { return a > b; }
long long binarySearch(long long arr[], long long l, long long r, long long x) {
  if (r >= l) {
    long long mid = l + (r - l) / 2;
    if (arr[mid] == x) return mid;
    if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);
    return binarySearch(arr, mid + 1, r, x);
  }
  return -1;
}
int main() {
  long long T;
  cin >> T;
  for (long long i = 0; i < T; i++) {
    long long m;
    cin >> m;
    vector<long long> r1(m), r2(m);
    vector<long long> bsum1, sum2;
    long long sum = 0;
    for (long long i = 0; i < m; i++) {
      cin >> r1[i];
      sum += r1[i];
    }
    sum -= r1[0];
    for (long long i = 1; i < m; i++) {
      bsum1.push_back(sum);
      sum -= r1[1];
    }
    bsum1.push_back(sum);
    sum = 0;
    for (long long i = 0; i < m; i++) {
      cin >> r2[i];
      sum2.push_back(sum);
      sum += r2[i];
    }
    long long ans = inf;
    for (long long i = 0; i < m; i++) {
      long long x = max(bsum1[i], sum2[i]);
      ans = min(ans, x);
    }
    cout << ans << endl;
  }
}
