#include <bits/stdc++.h>
using ll = long long;
template <class t, class u, class... w>
auto operator<<(t& o, u a) -> decltype(a.print(a), o) {
  return o << "{", a.print(), o << "}";
}
using namespace std;
void DD(...) {}
using Pii = pair<int, int>;
template <class t, class u, class... w>
void DD(t s, u a, w... k) {
  while (*s && *s != ',') cerr << *s++;
  cerr << ": " << a << *s++;
  DD(s, k...);
}
template <class t, class u, class... w>
auto operator<<(t& o, u a) -> decltype((a).begin(), (a).end(), o) {
  return o << "[",
         [&]() {
           for (auto i : a) o << i << ", ";
         }(),
         o << "]";
}
using Vi = vector<int>;
template <class t, class u, class... w>
auto operator<<(t& o, u a) -> decltype(get<1>(a), o) {
  return o << "(" << a.first << ", " << a.second << ")";
}
int n;
void solve0() {
  if (n % 2) {
    cout << "NO\n";
    return;
  }
  Vi perm(n);
  for (int k = n; k > 0;) {
    int i, p = 1;
    while ((p << 1) <= k) p <<= 1;
    for (i = 0; p + i - 1 <= k; i++) {
      perm[p + i - 2] = p - i;
      perm[p - i - 1] = p + i - 1;
    }
    k = p - i - 1;
  }
  cout << "YES\n";
  for (auto& first : (perm)) cout << first << " ";
  cout << endl;
}
void solve1() {
  if (n <= 5 || __builtin_popcount(n) == 1) {
    cout << "NO\n";
    return;
  }
  Vi perm(min(n, 7));
  iota((perm).begin(), (perm).end(), 1);
  do {
    for (int i = (0); i < (int((perm).size())); i++)
      if (perm[i] == i + 1 || (perm[i] & (i + 1)) == 0) goto nope;
    break;
  nope:;
  } while (next_permutation((perm).begin(), (perm).end()));
  perm.resize(n);
  for (int i = 8; i <= n; i <<= 1) {
    for (int j = 0; j < i && i + j <= n; j++) {
      perm[i + j - 1] = i + ((j + 1) % min(i, n - i + 1));
    }
  }
  cout << "YES\n";
  for (auto& first : (perm)) cout << first << " ";
  cout << endl;
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(10);
  cin >> n;
  solve0();
  solve1();
  return 0;
}
