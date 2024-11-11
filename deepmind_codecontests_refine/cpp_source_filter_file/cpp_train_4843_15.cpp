#include <bits/stdc++.h>
using namespace std;
template <typename Head>
void myprint(Head a) {
  cout << a << '\n';
}
template <typename Head, typename... Tail>
void myprint(Head a, Tail... t) {
  cout << a << ' ';
  myprint(t...);
}
int main() {
  ios_base::sync_with_stdio(false);
  int i, j;
  long long A, cf, cm, M;
  int n;
  cin >> n;
  ;
  cin >> A;
  cin >> cf;
  cin >> cm;
  cin >> M;
  vector<pair<long long, int> > arr;
  for (i = 0; i < n; i++) {
    long long temp;
    cin >> temp;
    arr.push_back(make_pair(temp, i));
  }
  sort((arr).begin(), (arr).end());
  reverse((arr).begin(), (arr).end());
  vector<long long> pref(n);
  pref[0] = arr[0].first;
  for (i = 1; i < n; i++) pref[i] = pref[i - 1] + arr[i].first;
  long long mn = arr[n - 1].first;
  i = 0, j = 0;
  long long ans = 0;
  int ians, jans;
  long long xans;
  while (i <= n && j <= n) {
    long long cost1 = i > 0 ? (long long)i * A - pref[i - 1] : 0;
    long long m = M - cost1;
    if (m < 0) break;
    j = max(i, j);
    if (j == n) {
      long long tans = (long long)i * cf + cm * (i < n ? mn : A);
      if (ans < tans) {
        ans = tans;
        ians = i;
        jans = j;
        xans = -1;
      }
      i++;
      continue;
    }
    long long x = m + (pref[n - 1] - (j > 0 ? pref[j - 1] : 0));
    x /= (n - j);
    if (x < arr[j].first) {
      j++;
      continue;
    }
    x = min(x, A);
    long long tans = (long long)i * cf + x * cm;
    if (ans < tans) {
      ans = tans;
      ians = i;
      jans = j;
      xans = x;
    }
    i++;
  }
  cout << ans << '\n';
  for (i = 0; i < ians; i++) arr[i].first = A;
  for (j = jans; j < n; j++) arr[j].first = xans;
  vector<long long> ans_arr(n);
  for (i = 0; i < n; i++) ans_arr[arr[i].second] = arr[i].first;
  for (i = 0; i < n; i++) cout << ans_arr[i] << ' ';
  cout << '\n';
}
