#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
ostream& operator<<(ostream& out, const pair<A, B>& a) {
  out << "(" << a.first << "," << a.second << ")";
  return out;
}
template <typename T, size_t N>
ostream& operator<<(ostream& out, const array<T, N>& a) {
  out << "[";
  bool first = true;
  for (auto& v : a) {
    out << (first ? "" : ", ");
    out << v;
    first = 0;
  }
  out << "]";
  return out;
}
template <typename T>
ostream& operator<<(ostream& out, const vector<T>& a) {
  out << "[";
  bool first = true;
  for (auto& v : a) {
    out << (first ? "" : ", ");
    out << v;
    first = 0;
  }
  out << "]";
  return out;
}
template <typename T, class Cmp>
ostream& operator<<(ostream& out, const set<T, Cmp>& a) {
  out << "{";
  bool first = true;
  for (auto& v : a) {
    out << (first ? "" : ", ");
    out << v;
    first = 0;
  }
  out << "}";
  return out;
}
template <typename U, typename T, class Cmp>
ostream& operator<<(ostream& out, const map<U, T, Cmp>& a) {
  out << "{";
  bool first = true;
  for (auto& p : a) {
    out << (first ? "" : ", ");
    out << p.first << ":" << p.second;
    first = 0;
  }
  out << "}";
  return out;
}
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}
void solve() {
  string s;
  int n = 8;
  int white = 0, black = 0;
  while (n--) {
    cin >> s;
    for (int i = 0; i < 8; i++) {
      if (s[i] == 'Q') white += 9;
      if (s[i] == 'R') white += 5;
      if (s[i] == 'B') white += 3;
      if (s[i] == 'N') white += 1;
      if (s[i] == 'P') white += 1;
      if (s[i] == 'q') black += 9;
      if (s[i] == 'r') black += 5;
      if (s[i] == 'b') black += 3;
      if (s[i] == 'n') black += 1;
      if (s[i] == 'p') black += 1;
    }
  }
  if (white == black)
    cout << "Draw"
         << "\n";
  else if (white > black)
    cout << "White"
         << "\n";
  else
    cout << "Black"
         << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test = 1;
  while (test--) {
    solve();
  }
  return 0;
}
