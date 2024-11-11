#include <bits/stdc++.h>
using namespace std;
typedef priority_queue<long long, vector<long long>, greater<long long>>
    minHeap;
long long INF = 1e17;
const int N = 2e6 + 33;
const long long MD = 24;
inline long long mul(long long a, long long b) { return (a * b) % MD; }
inline long long po(long long a, long long b) {
  long long ans = 1;
  while (b > 0) {
    if (b & 1) ans = mul(ans, a);
    a = mul(a, a);
    b /= 2;
  }
  return ans;
}
long long n, m, t, k;
long long arr[N];
long long x;
string s;
pair<int, int> b[N];
long long ps[N], B[N];
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k >> m >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    if (a == 0) {
      if (b < k) {
        k -= b;
        n -= b;
      } else if (b > k) {
        n = b;
      }
    } else {
      if (b <= k) {
        n++;
        k++;
      } else {
        n++;
      }
    }
    cout << n << " " << k << endl;
  }
  return 0;
}
