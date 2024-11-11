#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B, typename C>
struct triple {
  A X;
  B Y;
  C Z;
  triple(A a = 0, B b = 0, C c = 0) : X(a), Y(b), Z(c) {}
};
template <typename A, typename B, typename C>
triple<A, B, C> make_triple(A a = 0, B b = 0, C c = 0) {
  return triple<A, B, C>(a, b, c);
}
template <typename A, typename B, typename C>
bool operator<(const triple<A, B, C>& a, const triple<A, B, C>& b) {
  if (a.X != b.X) return a.X < b.X;
  if (a.Y != b.Y) return a.Y < b.Y;
  return a.Z < b.Z;
}
template <typename T, typename SS>
ostream& operator<<(ostream& ofs, const pair<T, SS>& p) {
  ofs << "( " << p.first << " , " << p.second << " )";
  return ofs;
}
template <typename T>
void print(T a) {
  for (auto i : a) cout << i << ' ';
  cout << '\n';
}
template <typename T>
T max(T a, T b, T c) {
  return max(a, max(b, c));
}
template <typename T>
T min(T a, T b, T c) {
  return min(a, min(b, c));
}
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
signed main() {
  srand(time(NULL));
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  long long n;
  cin >> n;
  n <<= 1;
  vector<long long> a(n);
  for (long long i = 0; i < (n); i++) cin >> a[i];
  sort(a.begin(), a.end());
  long long ans = (a[n / 2 - 1] - a[0]) * (a.back() - a[n / 2]);
  for (long long i = 1; i < n / 2; i++)
    ans = min(ans, (a.back() - a[0]) * (a[i + n / 2 - 1] - a[i]));
  cout << ans << '\n';
}
