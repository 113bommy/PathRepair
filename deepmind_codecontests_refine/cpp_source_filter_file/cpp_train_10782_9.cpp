#include <bits/stdc++.h>
using namespace std;
bool check_prime(long long n) {
  long long flag = 0;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      flag = 1;
      break;
    }
  }
  if (n == 1)
    return false;
  else if (flag == 0 || n == 2 || n == 3) {
    return true;
  } else {
    return false;
  }
}
long long BE(long long x, long long n, long long m) {
  long long result = 1;
  while (n > 0) {
    if (n % 2 == 1) result = result * x % m;
    x = x * x % m;
    n = n / 2;
  }
  return result;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  long long a, b, c;
  cin >> a >> b >> c;
  long long m;
  cin >> m;
  vector<pair<long long, string>> v1;
  vector<pair<long long, string>> v2;
  vector<pair<long long, string>> v;
  for (long long i = 0; i < m; i++) {
    long long x;
    cin >> x;
    string y;
    cin >> y;
    v.push_back(make_pair(x, y));
  }
  long long cnt = 0;
  long long sum = 0;
  long long ca = 0;
  long long cb = 0;
  long long cc = 0;
  sort(v.begin(), v.end());
  for (long long i = 0; i < v.size(); i++) {
    if (v[i].second == "USB" && ca < a) {
      cnt++;
      sum += v[i].first;
      ca++;
    } else if (v[i].second == "PS/2" && cb < c) {
      cnt++;
      sum += v[i].first;
      cb++;
    } else if (cc < c) {
      cnt++;
      sum += v[i].first;
      cc++;
    }
  }
  cout << cnt << " " << sum << '\n';
  return 0;
}
