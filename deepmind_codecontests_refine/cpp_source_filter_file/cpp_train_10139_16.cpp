#include <bits/stdc++.h>
using namespace std;
template <typename T>
istream& operator>>(istream& input, vector<T>& s) {
  for (T& a : s) {
    input >> a;
  }
  return input;
}
template <typename T>
ostream& operator<<(ostream& output, vector<T>& s) {
  for (T& a : s) {
    output << a << ' ';
  }
  output << endl;
  return output;
}
template <typename T>
T max(T a, T b, T c) {
  return max(a, max(b, c));
}
template <typename T>
T min(T a, T b, T c) {
  return min(a, min(b, c));
}
template <typename T>
T gcd(T a, T b) {
  return !b ? a : gcd(b, a % b);
}
template <typename T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
template <typename T>
bool isPrime(T a) {
  if (a == 1)
    return false;
  else if (a == 2)
    return true;
  else if (!(a % 2))
    return false;
  else {
    for (unsigned long long i = 3; i * i <= a; i += 2) {
      if (!(a % i)) return false;
    }
  }
  return true;
}
int vsum(vector<int> vec) {
  int sum = 0;
  for (auto t : vec) sum += t;
  return sum;
}
void solve() {
  int a, b;
  cin >> a >> b;
  for (long long i = 0; i < (b); ++i) {
    cout << a / b + (a % b >= i) << " ";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int t = 1;
  while (t--) {
    solve();
  }
}
