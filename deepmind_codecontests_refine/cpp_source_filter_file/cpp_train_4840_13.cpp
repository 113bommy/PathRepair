#include <bits/stdc++.h>
using namespace std;
template <int POS, class TUPLE>
void deploy(std::ostream &os, const TUPLE &tuple) {}
template <int POS, class TUPLE, class H, class... Ts>
void deploy(std::ostream &os, const TUPLE &t) {
  os << (POS == 0 ? "" : ", ") << get<POS>(t);
  deploy<POS + 1, TUPLE, Ts...>(os, t);
}
template <class T, class U>
std::ostream &operator<<(std::ostream &os, std::pair<T, U> &p) {
  os << "(" << p.first << ", " << p.second << ")";
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
template <class T, class K>
std::ostream &operator<<(std::ostream &os, std::map<T, K> &make_pair) {
  int remain = make_pair.size();
  os << "{";
  for (auto e : make_pair)
    os << "(" << e.first << " -> " << e.second << ")"
       << (--remain == 0 ? "}" : ", ");
  return os;
}
using ll = long long;
int nums[110][110];
int N;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> N;
  for (int i = 0; i < (N); i++) {
    for (int j = 0; j < (N); j++) {
      cin >> nums[i][j];
    }
  }
  vector<int> ans;
  for (int i = 0; i < (N); i++) {
    int t = 0;
    for (int j = 0; j < (N); j++) {
      if (nums[i][j] == 1) {
        t += 1;
      }
      if (nums[i][j] == 3) {
        t += 1;
      }
    }
    if (t % 2 == 0) {
      ans.push_back(i + 1);
    }
  }
  cout << ((int)(ans).size()) << "\n";
  for (int i = 0; i < (((int)(ans).size())); i++) {
    if (i) cout << " ";
    cout << ans[i];
  }
  cout << "\n";
  return 0;
}
