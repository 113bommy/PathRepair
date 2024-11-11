#include <bits/stdc++.h>
using namespace std;
template <typename T>
std::vector<std::vector<std::vector<T>>> make_3d_vector(long long z,
                                                        long long y,
                                                        long long x,
                                                        T value = T{}) {
  return std::vector<std::vector<std::vector<T>>>(
      z, std::vector<std::vector<T>>(y, std::vector<T>(x, value)));
}
template <typename T>
std::vector<std::vector<T>> make_2d_vector(long long z, long long y,
                                           T value = T{}) {
  return std::vector<std::vector<T>>(z, std::vector<T>(y, value));
}
template <typename T>
std::vector<T> make_1d_vector(long long z, T value = T{}) {
  return std::vector<T>(z, value);
}
long long value(char last_char) {
  if (last_char >= '0' && last_char <= '9')
    return last_char - '0';
  else
    return last_char - 'A' + 10;
}
long long power(long long a, long long b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  if (b % 2 == 1) return (power(a, b - 1) * a);
  long long q = power(a, b / 2);
  return (q * q);
}
bool convert(long long n, string s1, string s2) {
  long long sum = 0;
  for (long long i = 0; i < s1.size(); i++) {
    long long x = value(s1[i]);
    sum += (power(n, i) * x);
  }
  if (sum >= 24) {
    return false;
  }
  sum = 0;
  for (long long i = 0; i < s2.size(); i++) {
    long long x = value(s2[i]);
    sum += pow(n, i) * x;
  }
  return sum <= 59;
}
void solve() {
  string s;
  cin >> s;
  string s1 = "", s2 = "";
  bool found = false;
  long long mx = 1;
  for (long long i = 0; i < s.size(); i++) {
    if (s[i] != ':') {
      mx = max(value(s[i]), mx);
    }
  }
  for (auto i : s) {
    if (i == ':') {
      found = true;
    } else if (found) {
      s2.push_back(i);
    } else {
      s1.push_back(i);
    }
  }
  reverse(s1.begin(), s1.end());
  reverse(s2.begin(), s2.end());
  long long ct = 0;
  while (s1.size() != 1 && s1[s1.size() - 1] == '0') {
    s1.pop_back();
  }
  while (s2.size() != 1 && s2[s2.size() - 1] == '0') {
    s2.pop_back();
  }
  if (s1.size() == 1 && s2.size() == 1) {
    if (s1[0] < 'P') {
      cout << -1;
      return;
    }
  }
  for (long long i = mx + 1; i <= 90000; i++) {
    if (convert(i, s1, s2)) {
      cout << i << " ";
      ct++;
    }
  }
  if (!ct) {
    cout << 0;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
}
