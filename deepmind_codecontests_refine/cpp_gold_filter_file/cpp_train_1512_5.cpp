#include <bits/stdc++.h>
using namespace std;
inline int in() {
  int x;
  scanf("%d", &x);
  return x;
}
inline long long inL() {
  long long x;
  scanf("%lld", &x);
  return x;
}
string toString(long long n) {
  stringstream ss;
  ss << n;
  return ss.str();
}
long long toNumber(string s) {
  stringstream ss;
  long long n;
  ss << s;
  ss >> n;
  return n;
}
const int N = 15;
long long a[N];
int main() {
  int n = in();
  vector<long long> a(n);
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    a[i] = inL();
    sum += a[i];
  }
  sort(a.begin(), a.end(), greater<long long>());
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    long long x = sum / n;
    if (i < sum % n) x += 1;
    ans += abs(x - a[i]);
  }
  cout << ans / 2 << '\n';
  return 0;
}
