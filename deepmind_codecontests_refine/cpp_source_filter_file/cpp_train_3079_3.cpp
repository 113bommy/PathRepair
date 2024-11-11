#include <bits/stdc++.h>
using namespace std;
template <class T>
T gcd(T a, T b) {
  return b == 0 ? a : gcd(b, a % b);
}
template <typename T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
template <class T>
T my_pow(T n, T p) {
  if (p == 0) return 1;
  T x = my_pow(n, p / 2);
  x = (x * x);
  if (p & 1) x = (x * n);
  return x;
}
template <class T>
T big_mod(T n, T p, T m) {
  if (p == 0) return (T)1;
  T x = big_mod(n, p / 2, m);
  x = (x * x) % m;
  if (p & 1) x = (x * n) % m;
  return x;
}
template <class T>
T extract(string s, T ret) {
  stringstream ss(s);
  ss >> ret;
  return ret;
}
string itos(long long n) {
  string s;
  while (n) {
    s += (n % 10 + 48);
    n /= 10;
  }
  reverse(s.begin(), s.end());
  return s;
}
long long stoi(string s) {
  long long n = 0;
  for (__typeof(s.size()) i = 0; i < (s.size()); i++) n = n * 10 + (s[i] - 48);
  return n;
}
const int N = 5e5 + 5, MOD = 1e9 + 7;
long long ar[N], br[N];
long long a = 0, b = 0, c = 0, r = 0, rr = 0, f = 0, n, m, t = 0, ks = 0;
string s, ss;
priority_queue<long long> st;
struct info {
  long long x, y, z;
} arr[N];
bool com(info a, info b) { return (a.x) < (b.x); }
int main() {
  cin >> n >> m;
  for (__typeof(n) i = 1; i <= (n); i++) cin >> br[i] >> ar[i];
  long long ans = 0;
  for (__typeof(n) i = 1; i <= (n); i++) {
    arr[i].x = br[i];
    arr[i].y = ar[i];
    arr[i].z = i;
  }
  sort(arr, arr + n, com);
  for (__typeof(n) i = 1; i <= (n); i++) {
    if (st.size() < m)
      st.push(-arr[i].y);
    else if (st.size() >= m and -st.top() < arr[i].y) {
      st.pop();
      st.push(-arr[i].y);
    }
    if ((ans < (-st.top() - arr[i].x + 1) and st.size() >= m)) {
      ans = (-st.top() - arr[i].x + 1);
      r = arr[i].x;
    }
  }
  cout << ans << endl;
  if (not ans)
    for (__typeof(m) i = 0; i < (m); i++) cout << i + 1 << " ";
  for (__typeof(n) i = 1; i <= (n); i++) {
    if (m <= 0 or not ans) break;
    if (arr[i].x <= r and (ans + r - 1) <= arr[i].y) {
      m--;
      cout << arr[i].z << " ";
    }
  }
  cout << endl;
  return 0;
}
