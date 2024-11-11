#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <int n, class... T>
typename enable_if<(n >= sizeof...(T))>::type __output_tuple(
    ostream &, tuple<T...> const &) {}
template <int n, class... T>
typename enable_if<(n < sizeof...(T))>::type __output_tuple(
    ostream &os, tuple<T...> const &t) {
  os << (n == 0 ? "" : ", ") << get<n>(t);
  __output_tuple<n + 1>(os, t);
}
template <class... T>
ostream &operator<<(ostream &os, tuple<T...> const &t) {
  os << "(";
  __output_tuple<0>(os, t);
  os << ")";
  return os;
}
template <class T, class U>
ostream &operator<<(ostream &os, pair<T, U> const &p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}
template <class T>
ostream &operator<<(ostream &os, const stack<T> &a) {
  os << "{";
  for (auto tmp = a; tmp.size(); tmp.pop())
    os << (a.size() == tmp.size() ? "" : ", ") << tmp.top();
  os << "}";
  return os;
}
template <class T, class Container, class Compare>
ostream &operator<<(ostream &os, priority_queue<T, Container, Compare> a) {
  os << "{ (top) ";
  while (a.size()) os << a.top() << (a.size() == 1 ? "" : ", "), a.pop();
  os << " }";
  return os;
}
template <class T, class Container>
ostream &operator<<(ostream &os, queue<T, Container> a) {
  os << "{ ";
  while (a.size()) os << a.front() << (a.size() == 1 ? "" : ", "), a.pop();
  os << " }";
  return os;
}
template <class T,
          class = typename iterator_traits<decltype(begin(T()))>::value_type,
          class = typename enable_if<!is_same<T, string>::value>::type>
ostream &operator<<(ostream &os, const T &a) {
  for (auto ite = begin(a); ite != end(a); ++ite)
    os << (ite == begin(a) ? "" : " ") << *ite;
  return os;
}
void NO() {
  cout << -1 << endl;
  exit(0);
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n;
  string s, t;
  cin >> n;
  cin >> s >> t;
  vector<int> c(n);
  int ans = 0;
  vector<int> can(n);
  auto check = [&](int i) {
    if (c[i] == 0) return can[i] = false;
    if (c[i] > 0) {
      return can[i] = s[i] != '9' && s[i + 1] != '9';
    } else {
      return can[i] = s[i] != '0' && s[i + 1] != '9';
    }
  };
  set<int> st;
  for (int i = 0; i < n; i++) {
    c[i] = int(t[i] - s[i]);
    if (i) c[i] -= c[i - 1];
    ans += abs(c[i]);
    check(i);
    if (can[i]) st.emplace(i);
  }
  if (c.back()) NO();
  cout << ans << "\n";
  int o = 0;
  const int O = 1e5;
  while (o < O && st.size()) {
    o++;
    int i = *st.begin();
    st.erase(st.begin());
    if (c[i] > 0) {
      s[i]++;
      s[i + 1]++;
      c[i]--;
      cout << i + 1 << " " << 1 << "\n";
    } else {
      s[i]--;
      s[i + 1]--;
      c[i]++;
      cout << i + 1 << " " << -1 << "\n";
    }
    if (i) check(i - 1);
    check(i);
    check(i + 1);
    if (i) {
      if (can[i - 1])
        st.emplace(i - 1);
      else
        st.erase(i - 1);
    }
    if (can[i]) st.emplace(i);
    if (can[i + 1])
      st.emplace(i + 1);
    else
      st.erase(i + 1);
  }
  return 0;
}
