#include <bits/stdc++.h>
using namespace std;
const long long int INF = 2000000000000000000;
long long int MOD(long long int a, long long int b) {
  if (a > b)
    return a - b;
  else
    return b - a;
}
long long int max3(long long int a, long long int b, long long int c) {
  return max(c, max(a, b));
}
long long int min3(long long int a, long long int b, long long int c) {
  return min(a, min(b, c));
}
long long int power(long long int x, long long int y) {
  long long int res = 1;
  x = x;
  while (y > 0) {
    if (y & 1) res = (res * x);
    y = y >> 1;
    x = (x * x);
  }
  return res;
}
long long int logg(long long int a) {
  long long int x = 0;
  while (a > 1) {
    x++;
    a /= 2;
  }
  return x;
}
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int n, k;
  cin >> n >> k;
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if (k <= n || n == 4) {
    cout << -1;
    return 0;
  } else {
    vector<int> ans1;
    vector<int> ans2;
    ans1.push_back(a);
    ans1.push_back(c);
    for (int i = 1; i <= n; i++) {
      if (i != a && i != b && i != c && i != d) {
        ans1.push_back(i);
      }
    }
    ans1.push_back(d);
    ans1.push_back(b);
    ans2.push_back(c);
    ans2.push_back(a);
    for (int i = 1; i <= n; i++) {
      if (i != a && i != b && i != c && i != d) {
        ans2.push_back(i);
      }
    }
    ans2.push_back(b);
    ans2.push_back(d);
    for (int i = 0; i < n; i++) {
      cout << ans1[i] << ' ';
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
      cout << ans2[i] << ' ';
    }
  }
}
