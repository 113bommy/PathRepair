#include <bits/stdc++.h>
using namespace std;
long long n, m, i, j, k, ans, t, x, tmp, mx, mn, curr, flag;
long long arr[1000005];
vector<long long> vec;
string s;
map<long long, long long> mpp;
int main() {
  long long l = -1000000000;
  long long r = 1000000000;
  cin >> n;
  for (i = 0; i < n; i++) cin >> arr[i];
  cin >> s;
  for (i = 4; i < s.length(); i++) {
    if (s[i] == s[i - 1]) continue;
    if (s[i] == '1') {
      l = max(l,
              max(arr[i] + 1, max(arr[i - 1] + 1,
                                  max(arr[i - 2] + 1,
                                      max(arr[i - 3] + 1, arr[i - 4] + 1)))));
    } else {
      r = min(r,
              min(arr[i] - 1, min(arr[i - 1] - 1,
                                  min(arr[i - 2] - 1,
                                      min(arr[i - 3] - 1, arr[i - 4] + 1)))));
    }
  }
  cout << l << " " << r;
  return 0;
}
