#include <bits/stdc++.h>
using namespace std;
int count_bit(unsigned x) { return __builtin_popcount(x); }
int first_bit(unsigned x) { return __builtin_ffs(x); }
template <typename T>
T sq(const T& x) {
  return x * x;
}
template <typename T>
void minl(T& a, const T& b) {
  if (a > b) a = b;
}
template <typename T>
void maxl(T& a, const T& b) {
  if (a < b) a = b;
}
template <typename T>
void usort(vector<T>& a) {
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
}
template <typename T>
int index(const vector<T>& a, const T& x) {
  return lower_bound(a.begin(), a.end(), x) - a.begin();
}
template <typename T>
T gcd(T a, T b) {
  while (b) {
    T t = a % b;
    a = b;
    b = t;
  }
  return a;
}
template <typename T>
pair<T, T> operator+(const pair<T, T>& a, const pair<T, T>& b) {
  return pair<T, T>(a.first + b.first, a.second + b.second);
}
template <typename T>
pair<T, T> operator-(const pair<T, T>& a, const pair<T, T>& b) {
  return pair<T, T>(a.first - b.first, a.second - b.second);
}
template <typename A, typename B>
istream& operator>>(istream& i, pair<A, B>& v) {
  return i >> v.first >> v.second;
}
template <typename A, typename B>
B conv(const A& in) {
  stringstream s;
  B out;
  s << in;
  s >> out;
  return out;
}
long long cross(const pair<int, int>& a, const pair<int, int>& b) {
  return (long long)a.first * b.second - (long long)b.first * a.second;
}
long long dot(const pair<int, int>& a, const pair<int, int>& b) {
  return (long long)a.first * b.first + (long long)a.second * b.second;
}
string name[64];
void york() {
  int n;
  cin >> n;
  int win = 0;
  int high = -9999999;
  for (int i = 0; i < n; ++i) {
    cin >> name[i];
    int sum = 0;
    int a, b;
    cin >> a >> b;
    sum += a * 100;
    sum -= a * 50;
    for (int j = 0; j < 5; ++j) {
      int t;
      cin >> t;
      sum += t;
    }
    if (sum > high) {
      high = sum;
      win = i;
    }
  }
  cout << name[win];
}
int main() {
  ios_base::sync_with_stdio(false);
  york();
  return 0;
}
