#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 30;
const long long MOD = 1e9 + 7;
const long long MAX = 1e5;
const long long MAXX = 1e5 + 5;
long long powerm(long long a, long long b, long long m) {
  if (b == 0) {
    return 1;
  }
  long long res = powerm(a, b / 2, m);
  if (b % 2) {
    return ((res * res) % m * (a % m)) % m;
  }
  return (res * res) % m;
}
long long power(long long a, long long b) {
  if (b == 0) {
    return 1;
  }
  long long res = power(a, b / 2);
  if (b % 2 == 0) {
    return res * res;
  }
  return res * res * a;
}
long long b[MAX];
void add(long long a, long long x) {
  long long curr = a;
  while (curr < MAX) {
    b[curr] += x;
    curr += curr - (curr & (curr - 1));
  }
  return;
}
long long q(long long r) {
  long long curr = r, res = 0;
  while (curr > 0) {
    res += b[curr];
    curr &= (curr - 1);
  }
  return res;
}
bool cmp(pair<long long, long long>& a, pair<long long, long long>& b) {
  if (a.first == b.first) {
    return a.second < b.second;
  }
  return a.first > b.first;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m;
  cin >> n;
  long long yo[n];
  pair<long long, long long> arr[n];
  for (long long i = 0; i < n; i++) {
    cin >> arr[i].first;
    yo[i] = arr[i].first;
    arr[i].second = i + 1;
  }
  sort(arr, arr + n, cmp);
  cin >> m;
  long long ans[m];
  tuple<long long, long long, long long> r[m];
  for (long long i = 0; i < m; i++) {
    cin >> get<0>(r[i]) >> get<1>(r[i]);
    get<2>(r[i]) = i;
  }
  sort(r, r + m);
  long long curr = 0;
  for (long long i = 0; i < m; i++) {
    while (curr < get<0>(r[i])) {
      add(arr[curr].second, 1);
      curr++;
    }
    long long first = 1, last = n, res = -1;
    while (first <= last) {
      long long mid = (first + last) / 2;
      if (q(mid) >= get<1>(r[i])) {
        res = mid;
        last = mid - 1;
      } else {
        first = mid + 1;
      }
    }
    ans[get<2>(r[i])] = yo[res - 1];
  }
  for (long long i = 0; i < m; i++) {
    cout << ans[i] << "\n";
  }
  return 0;
}
