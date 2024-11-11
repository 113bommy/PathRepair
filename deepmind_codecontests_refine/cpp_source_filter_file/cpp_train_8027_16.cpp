#include <bits/stdc++.h>
using namespace std;
map<string, long long int> month;
void Month() {
  month["January"] = 1, month["February"] = 2, month["March"] = 3,
  month["April"] = 4, month["May"] = 5, month["June"] = 6;
  month["July"] = 7, month["August"] = 8, month["September"] = 9,
  month["October"] = 10, month["November"] = 11, month["December"] = 12;
}
long long int A[1000000];
long long int B[1000000];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<long long int> v;
  long long int n, k, sum = 0, res = 0, p = 0;
  cin >> n >> k;
  for (long long int i = 0; i < n; i++) cin >> A[i], sum += A[i];
  if (sum % k != 0) {
    cout << "NO" << endl;
    return 0;
  };
  sum /= k;
  for (long long int i = 0; i < n; i++) {
    res += A[i];
    p++;
    if (res == sum)
      v.push_back(p), p = 0, res = 0;
    else if (res > sum) {
      cout << "NO" << endl;
      return 0;
    };
  }
  cout << "YES" << endl;
  for (long long int i = 0; i < v.size(); i++) cout << v[i] << " ";
  return 0;
}
