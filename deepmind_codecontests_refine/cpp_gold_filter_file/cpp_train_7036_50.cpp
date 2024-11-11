#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a * (b / gcd(a, b)); }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long v;
  cin >> v;
  for (long long i = 0; i < v; i++) {
    vector<long double> arr(250);
    for (long long j = 0; j < 250; j++) cin >> arr[j];
    long double avg1 = 0;
    for (long long j = 0; j < 250; j++) avg1 += arr[j];
    avg1 /= 250.0;
    sort(arr.begin(), arr.end());
    long double v1 = ((arr[249] - arr[0]) * (arr[249] - arr[0])) / 12.0;
    long double v2 = 0;
    for (long long j = 0; j < 250; j++)
      v2 += ((avg1 - arr[j]) * (avg1 - arr[j]));
    v2 /= 250.0;
    long double avg2 = 0;
    if (abs(v2 - avg1) > abs(v1 - v2))
      cout << "uniform\n";
    else
      cout << "poisson\n";
  }
  return 0;
}
