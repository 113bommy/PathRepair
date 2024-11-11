#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << '{';
  string sep;
  for (const auto &x : v) os << sep << x, sep = ", ";
  return os << '}';
}
template <typename T, size_t size>
ostream &operator<<(ostream &os, const array<T, size> &arr) {
  os << '{';
  string sep;
  for (const auto &x : arr) os << sep << x, sep = ", ";
  return os << '}';
}
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
auto random_address = [] {
  char *p = new char;
  delete p;
  return (uint64_t)p;
};
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count() *
               (random_address() | 1));
const int RANDOM_ITERS = 15;
const int ALL = 2047;
int N;
vector<int> order;
map<pair<int, int>, int> save;
int query(int a, int b) {
  if (a > b) swap(a, b);
  if (save.find({a, b}) != save.end()) return save[{a, b}];
  cout << "? " << a + 1 << ' ' << b + 1 << endl;
  int result;
  cin >> result;
  save[{a, b}] = result;
  if (result == -1) exit(0);
  return result;
}
int get_next_index() {
  int index = order.back();
  order.pop_back();
  return index;
}
int evaluate(int x) {
  int result = ALL;
  for (int iter = 0; iter < RANDOM_ITERS; iter++) {
    int y;
    do {
      y = int(rng() % N);
    } while (x == y);
    result &= query(x, y);
  }
  return result;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> N;
  order.resize(N);
  for (int i = 0; i < N; i++) order[i] = i;
  shuffle(order.begin(), order.end(), rng);
  int current = get_next_index();
  int value = evaluate(current);
  while (value != 0) {
    int index = get_next_index();
    if (query(current, index) == value) {
      current = index;
      value = evaluate(current);
    }
  }
  vector<int> answer(N, 0);
  for (int i = 0; i < N; i++)
    if (i != current) answer[i] = query(i, current);
  cout << '!';
  for (int x : answer) cout << ' ' << x;
  cout << endl;
}
