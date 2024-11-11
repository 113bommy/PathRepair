#include <bits/stdc++.h>
using namespace std;
template <typename T>
T gcd(T a, T b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
template <typename P>
P dectobin(P a) {
  if (a == 0)
    return 0;
  else
    return (a % 2 + 10 * dectobin(a / 2));
}
template <typename Y>
Y bintodec(Y a) {
  long long ans = 0, b = 1, t = a;
  while (t) {
    long long ld = t % 10;
    t /= 10;
    ans += ld * b;
    b = b * 2;
  }
  return ans;
}
template <typename H>
H modExp(H x, H n) {
  long long r = 1;
  while (n > 0) {
    if (n % 2 == 1) {
      r = (r * x) % 1000000007;
    }
    x = (x * x) % 1000000007;
    n /= 2;
  }
  return r;
}
template <typename T>
T isPowerOfTwo(T x) {
  return x && (!(x & (x - 1)));
}
template <typename T>
T lcm(T a, T b) {
  return a * b / gcd(a, b);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ostream_iterator<long long> output(cout, " ");
  long long n;
  cin >> n;
  long long arr[n];
  map<long long, long long> make_pair;
  for (long long(i) = (0); i < (n); i++) {
    cin >> arr[i];
    make_pair[arr[i]]++;
  }
  long long m;
  cin >> m;
  long long brr[m];
  for (long long(i) = (0); i < (m); i++) {
    cin >> brr[i];
    make_pair[brr[i]]++;
  }
  for (long long(i) = (0); i < (n); i++) {
    for (long long(j) = (0); j < (m); j++) {
      if (make_pair[arr[i] + brr[j]] == 0) {
        cout << arr[i] << " " << brr[j];
        return 0;
      }
    }
  }
  return 0;
}
