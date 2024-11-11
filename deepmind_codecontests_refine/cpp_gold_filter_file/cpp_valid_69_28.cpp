#include <bits/stdc++.h>
using namespace std;
long long prime(int n) {
  if (n == 1) return 0;
  if (n == 2 || n == 3) return 1;
  if (n % 2 == 0 || n % 3 == 0) return 0;
  for (long long i = 5; i * i <= n; i += 6) {
    if (n % i == 0 || n % (i + 2) == 0) {
      return 0;
    }
  }
  return 1;
}
template <typename T>
void print_vector(vector<T> &vec) {
  for (auto elem : vec) cout << elem;
  cout << endl;
}
template <typename T>
void print_vector_rev(vector<T> &vec) {
  for (auto it = vec.rbegin; it != vec.rend; it++) cout << *it << endl;
  cout << endl;
}
template <typename T>
void sort_inc(vector<T> &vec) {
  sort(vec.begin(), vec.end());
}
template <typename T>
void sort_dec(vector<T> &vec) {
  sort(vec.rbegin(), vec.rend());
}
template <typename T>
void inp(T &a) {
  cin >> a;
}
template <typename T>
void inp(T &a, T &b) {
  cin >> a >> b;
}
template <typename T>
void inp(T &a, T &b, T &c) {
  cin >> a >> b >> c;
}
template <typename T>
void inp(T &a, T &b, T &c, T &d) {
  cin >> a >> b >> c >> d;
}
template <typename T>
void inp(T &a, T &b, T &c, T &d, T &e) {
  cin >> a >> b >> c >> d >> e;
}
template <typename T>
void inp(vector<T> &vec) {
  for (int i = 0; i < vec.size(); i++) cin >> vec[i];
}
vector<string> power2(61);
void initialize() {
  for (int i = 0; i <= 60; i++) {
    power2[i] = to_string((long long)pow(2, i));
  }
}
void solve1() {
  long long n;
  inp(n);
  string input = to_string(n);
  long long ans = INT_MAX;
  for (int i = 0; i <= 60; i++) {
    long long k = 0, cc = 0;
    for (int j = 0; j < input.length(); j++) {
      if (k < power2[i].length() && power2[i][k] == input[j]) {
        k++;
        cc++;
      }
    }
    if (cc == power2[i].length()) {
      ans = min(ans, (long long)(input.length() - cc));
    } else {
      ans =
          min(ans, (long long)(input.length() - cc + power2[i].length() - cc));
    }
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  initialize();
  long long t;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    solve1();
  }
  return 0;
}
