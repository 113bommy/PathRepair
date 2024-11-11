#include <bits/stdc++.h>
using namespace std;
template <int POS, class TUPLE>
void deploy(std::ostream &os, const TUPLE &tuple) {}
template <int POS, class TUPLE, class H, class... Ts>
void deploy(std::ostream &os, const TUPLE &t) {
  os << (POS == 0 ? "" : ", ") << get<POS>(t);
  deploy<POS + 1, TUPLE, Ts...>(os, t);
}
template <class... Ts>
std::ostream &operator<<(std::ostream &os, const std::tuple<Ts...> &t) {
  os << "(";
  deploy<0, std::tuple<Ts...>, Ts...>(os, t);
  os << ")";
  return os;
}
template <class T>
std::ostream &operator<<(std::ostream &os, std::vector<T> &v) {
  int remain = v.size();
  os << "{";
  for (auto e : v) os << e << (--remain == 0 ? "}" : ", ");
  return os;
}
template <class T>
std::ostream &operator<<(std::ostream &os, std::set<T> &v) {
  int remain = v.size();
  os << "{";
  for (auto e : v) os << e << (--remain == 0 ? "}" : ", ");
  return os;
}
template <class T>
std::ostream &operator<<(std::ostream &os, std::queue<T> q) {
  os << "{";
  for (; !q.empty(); q.pop()) {
    os << q.front() << (q.size() != 1 ? ", " : "}");
  }
  return os;
}
template <class T>
std::ostream &operator<<(std::ostream &os, std::priority_queue<T> q) {
  os << "{";
  for (; !q.empty(); q.pop()) {
    os << q.top() << (q.size() != 1 ? ", " : "}");
  }
  return os;
}
template <class T, class K>
std::ostream &operator<<(std::ostream &os, std::map<T, K> &make_pair) {
  int remain = make_pair.size();
  os << "{";
  for (auto e : make_pair)
    os << "(" << e.first << " -> " << e.second << ")"
       << (--remain == 0 ? "}" : ", ");
  return os;
}
template <class T, class K>
std::ostream &operator<<(std::ostream &os,
                         std::unordered_map<T, K> &make_pair) {
  int remain = make_pair.size();
  os << "{";
  for (auto e : make_pair)
    os << "(" << e.first << " -> " << e.second << ")"
       << (--remain == 0 ? "}" : ", ");
  return os;
}
int n;
string a;
string b;
double calc(char c) {
  double res = 0;
  double left = 0;
  double right = 0;
  for (int i = 0; i < (n); i++) {
    if (b[i] == c) {
      right += n - i;
    }
  }
  for (int i = 0; i < (n); i++) {
    if (a[i] == c) {
      res += right * (i + 1);
      res += left * (n - i);
    }
    if (b[i] == c) {
      right -= n - i;
      left += i + 1;
    }
  }
  return res;
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  cin >> a;
  cin >> b;
  double child = 0;
  double mom = 0;
  for (char c = 'A'; c <= 'Z'; c++) {
    child += calc(c);
  }
  for (int i = 1; i < (n + 1); i++) {
    mom += i * i;
  }
  cout << fixed << setprecision(10) << child / mom << "\n";
  return 0;
}
