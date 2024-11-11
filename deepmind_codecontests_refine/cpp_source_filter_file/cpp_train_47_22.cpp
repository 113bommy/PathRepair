#include <bits/stdc++.h>
using namespace std;
long long max(long long b, long long a) {
  if (b > a)
    return b;
  else
    return a;
}
long long min(long long b, long long a) {
  if (b < a)
    return b;
  else
    return a;
}
long long Abs(long long b) { return max(b, -b); }
void print(vector<pair<long long, long long> > &v) {
  for (long long i = 0; i < v.size(); i++)
    cout << v[i].first << " " << v[i].second << endl;
  cout << endl;
}
void print(long long arr[], long long n) {
  for (long long i = 0; i < n; i++) cout << arr[i] << " ";
  cout << endl;
}
bool sortbysec(const pair<pair<long long, long long>, long long> &a,
               const pair<pair<long long, long long>, long long> &b) {
  return (a.first.second < b.first.second);
}
int32_t main() {
  long long n;
  cin >> n;
  long long x[n + 1], h[n + 1];
  for (long long i = 0; i < n; i++) {
    cin >> x[i] >> h[i];
  }
  x[n] = 4e9;
  long long m = x[0];
  long long cnt = 1;
  for (long long i = 1; i < n; i++) {
    if (x[i] + h[i] < m) {
      m = x[i];
      cnt++;
    } else if (x[i] + h[i] < x[i + 1]) {
      m = x[i] + h[i];
      cnt++;
    } else
      m = x[i];
  }
  cout << cnt << endl;
}
