#include <bits/stdc++.h>
using namespace std;
long long int seed;
mt19937 rng(seed = chrono::steady_clock::now().time_since_epoch().count());
inline long long int rnd(long long int l = 0,
                         long long int r = 0xFFFFFFFFFFFFFFFL) {
  return uniform_int_distribution<long long int>(l, r)(rng);
}
template <typename Arg1, typename Arg2>
ostream& operator<<(ostream& out, const pair<Arg1, Arg2>& a) {
  return out << "(" << a.first << " , " << a.second << ")";
}
template <typename Arg1>
ostream& operator<<(ostream& out, const vector<Arg1>& a) {
  out << "[";
  for (const auto& i : a) out << i << " , ";
  return out << "]";
}
template <typename Arg1>
ostream& operator<<(ostream& out, const set<Arg1>& a) {
  out << "{";
  for (const auto& i : a) out << i << " , ";
  return out << "}";
}
template <typename Arg1, typename Arg2>
ostream& operator<<(ostream& out, const map<Arg1, Arg2>& a) {
  out << "<";
  for (const auto& i : a) out << i << " , ";
  return out << ">";
}
template <typename T, size_t N>
typename enable_if<!is_same<typename remove_cv<T>::type, char>::value,
                   ostream&>::type
operator<<(ostream& out, T (&a)[N]) {
  out << '[';
  for (size_t i = 0; i < N; ++i) out << a[i] << " , ";
  out << ']';
  return out;
}
int bit[1000006] = {0}, n, ct = 0, a[1000006];
void update(int id, int z) {
  while (id <= 1000006) {
    bit[id] = bit[id] + z;
    id += (id & (-id));
  }
}
int query(int id) {
  int ans = 0;
  while (id > 0) {
    ans = ans + bit[id];
    id -= (id & (-id));
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int i;
  cin >> n;
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = n - 1; i >= 0; i--) {
    ct += query(a[i] - 1);
    update(a[i], 1);
  }
  if (((3 * n) & 1) == (ct & 1))
    cout << "Petr";
  else
    cout << "Um_nik";
  return 0;
}
