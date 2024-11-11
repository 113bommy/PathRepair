#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
template <class T = int>
T __rand(T range = numeric_limits<T>::max()) {
  return (T)(rng() % range);
}
template <class T>
ostream& operator,(ostream& out, const T& thing) {
  return out << ", " << thing;
}
template <class U, class V>
ostream& operator<<(ostream& out, const pair<U, V>& p) {
  return (out << "(" << p.first, p.second) << ")";
}
template <class A, class B>
ostream& operator<<(ostream& out, const tuple<A, B>& t) {
  return (out << "(" << get<0>(t), get<1>(t)) << ")";
}
template <class A, class B, class C>
ostream& operator<<(ostream& out, const tuple<A, B, C>& t) {
  return (out << "(" << get<0>(t), get<1>(t), get<2>(t)) << ")";
}
template <class T>
ostream& operator<<(ostream& out, const vector<T>& container) {
  out << "{";
  if (((int)container.size())) out << container[0];
  for (int i = 0; i++ < ((int)container.size()) - 1;) out, container[i];
  return out << "}";
}
template <class x>
vector<typename x::value_type> $v(const x& a) {
  return vector<typename x::value_type>(a.begin(), a.end());
}
template <class u>
vector<typename iterator_traits<u>::value_type> $v(u a, u b) {
  return vector<typename iterator_traits<u>::value_type>(a, b);
}
using ullong = unsigned long long;
int get_n() {
  int n;
  cin >> n;
  return n;
}
template <class Container>
ullong ask(const Container& pos) {
  if (!((int)pos.size())) {
    return 0;
  }
  cout << "? " << ((int)pos.size());
  for (auto i : pos) cout << ' ' << i + 1;
  cout << endl;
  ullong ans;
  cin >> ans;
  return ans;
}
template <class Container>
void answer(const Container& a) {
  cout << "!";
  for (auto i : a) cout << ' ' << i;
  cout << endl;
}
void solve() {
  const int n_bit = 13;
  int n = get_n();
  vector<ullong> ans(n);
  vector<int> assigned_mask(n);
  int u = 0;
  for (int mask = -1; ++mask < (1 << n_bit);) {
    if (__builtin_popcount(mask) != 6) {
      continue;
    }
    assigned_mask[u++] = mask;
    if (u == n) break;
  }
  for (int mask = 1; mask <= (1 << n_bit); mask <<= 1) {
    vector<int> ask_pos, upd_pos;
    for (int i = -1; ++i < n;) {
      if (assigned_mask[i] & mask)
        upd_pos.push_back(i);
      else
        ask_pos.push_back(i);
    }
    auto temp = ask(ask_pos);
    for (auto i : upd_pos) ans[i] |= temp;
  }
  answer(ans);
}
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
