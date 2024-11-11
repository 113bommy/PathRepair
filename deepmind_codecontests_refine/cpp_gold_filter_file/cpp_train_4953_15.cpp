#include <bits/stdc++.h>
using namespace std;
template <class T>
T Bitcnt(T a) {
  int sum = 0;
  while (a) {
    if (a & 1) sum++;
    a /= 2;
  }
  return sum;
}
template <class T>
T Max3(T a, T b, T c) {
  return max(a, max(b, c));
}
template <class T>
T Lcm(T a, T b) {
  T tmp = __gcd(a, b);
  return (a / tmp) * b;
}
template <class T>
T Pow(T a, T b) {
  T ans = 1;
  T base = a;
  while (b) {
    if (b & 1) ans = (ans * base);
    base = (base * base);
    b /= 2;
  }
  return ans;
}
long long Bigmod(long long a, long long b) {
  long long res = 1;
  long long pw = a % 1000000007LL;
  while (b > 0) {
    if (b & 1) res = (res * pw) % 1000000007LL;
    pw = (pw * pw) % 1000000007LL;
    b /= 2;
  }
  return res;
}
int a_x[] = {1, -1, 0, 0};
int a_y[] = {0, 0, 1, -1};
long long X, Y;
void extend_euclid(long long a, long long b) {
  if (b == 0) {
    X = 1;
    Y = 0;
    return;
  }
  extend_euclid(b, a % b);
  long long x, y;
  x = Y;
  y = X - (a / b) * Y;
  X = x;
  Y = y;
}
long long inverse_modulo(long long a, long long b) {
  extend_euclid(a, b);
  return (X + 1000000007LL) % 1000000007LL;
}
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  if (k == 1 || k > 3) {
    cout << -1;
    return 0;
  } else if (k == 2) {
    if (n <= 4) {
      cout << -1;
      return 0;
    }
    cout << n - 1 << endl;
    for (int i = 1; i < n; i++) {
      cout << i << " " << (i + 1) << endl;
    }
    return 0;
  } else {
    if (n < 4) {
      cout << -1;
      return 0;
    }
    int tot = n;
    tot--;
    if (n != 5)
      tot -= 2;
    else
      tot--;
    tot += n - 2;
    vector<pair<int, int> > ans;
    ans.push_back({1, 2});
    ans.push_back({2, 3});
    ans.push_back({3, 4});
    for (int i = 5; i <= n; i++) {
      ans.push_back({2, i});
      ans.push_back({3, i});
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
      cout << ans[i].first << " " << ans[i].second << endl;
    return 0;
  }
  return 0;
}
