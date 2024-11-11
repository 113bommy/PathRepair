#include <bits/stdc++.h>
using namespace std;
ostream &operator<<(ostream &out, string str) {
  for (char c : str) out << c;
  return out;
}
template <class L, class R>
ostream &operator<<(ostream &out, pair<L, R> p) {
  return out << "(" << p.first << ", " << p.second << ")";
}
template <class T>
auto operator<<(ostream &out, T a) -> decltype(a.begin(), out) {
  out << "{";
  for (auto it = a.begin(); it != a.end(); it = next(it))
    out << (it != a.begin() ? ", " : "") << *it;
  return out << "}";
}
void dump() { cerr << "\n"; }
template <class T, class... Ts>
void dump(T a, Ts... x) {
  cerr << a << ", ";
  dump(x...);
}
template <class T>
int size(T &&a) {
  return a.size();
}
using LL = long long;
using PII = pair<int, int>;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int it = 0; it < t; it++) {
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    vector<PII> ops;
    auto reverse = [&](int l, int r) {
      int len = r - l + 1;
      for (int i = 0; i < len / 2; i++) swap(str[l + i], str[r - i]);
      ops.emplace_back(l + 1, r + 1);
    };
    auto find = [&](int i, char c) {
      for (int j = i; j <= n - 1; j++)
        if (str[j] == c) return j;
    };
    k--;
    int q = n - 2 * k;
    int pos = 0;
    for (int i = 0; i < q / 2; i++) {
      int f = find(pos, '(');
      reverse(pos++, f);
    }
    for (int i = 0; i < q / 2; i++) {
      int f = find(pos, ')');
      reverse(pos++, f);
    }
    for (int i = 0; i < (n - q) / 2; i++) {
      int f = find(pos, '(');
      reverse(pos++, f);
      f = find(pos, ')');
      reverse(pos++, f);
    }
    cout << size(ops) << "\n";
    for (int i = 0; i < size(ops); i++)
      cout << ops[i].first << " " << ops[i].second << "\n";
    false;
  }
}
