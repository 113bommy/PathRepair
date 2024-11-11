#include <bits/stdc++.h>
using namespace std;
void printvec(std::vector<long long> v) {
  long long n = v.size();
  for (long long i = 0; i < n; i++) cout << v[i] << " ";
  cout << endl;
}
long long mod = 1e9 + 7;
long long power(long long x, unsigned long long y) {
  long long temp;
  if (y == 0) return 1;
  temp = power(x, y / 2);
  if (y % 2 == 0)
    return temp * temp;
  else
    return x * temp * temp;
}
long long binarySearch(vector<long long> arr, long long l, long long r,
                       long long x) {
  if (r >= l) {
    long long mid = l + (r - l) / 2;
    if (arr[mid] == x) return mid;
    if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);
    return binarySearch(arr, mid + 1, r, x);
  }
  return -1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T = 1;
  cin >> T;
  while (T--) {
    long long n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    std::vector<long long> p(m);
    for (long long i = 0; i < m; i++) cin >> p[i];
    std::vector<long long> v(n, 0);
    for (long long i = 0; i < m; i++) {
      v[p[i] - 1]++;
    }
    for (long long i = n - 1; i > 0; i--) {
      v[i - 1] = v[i - 1] + v[i];
    }
    for (long long i = 0; i < n; i++) {
      v[i]++;
    }
    std::vector<long long> ans(26, 0);
    for (long long i = 0; i < n; i++) {
      ans[((int)(s[i]) - 97)] += v[i];
    }
    for (long long i = 0; i < 26; i++) {
      cout << ans[i] << " ";
    }
    cout << endl;
  }
}
