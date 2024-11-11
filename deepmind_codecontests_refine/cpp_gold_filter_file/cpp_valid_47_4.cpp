#include <bits/stdc++.h>
using namespace std;
template <typename __T1, typename __T2>
ostream &operator<<(ostream &out, pair<__T1, __T2> &__VAR) {
  cout << "[" << __VAR.first << ", " << __VAR.second << "]";
  return out;
}
template <typename __T>
ostream &operator<<(ostream &out, vector<__T> &__VAR) {
  cout << "[";
  for (int i = 0; i <= (int)__VAR.size() - 2; i++) cout << __VAR[i] << ", ";
  if (__VAR.size() > 0) cout << __VAR[__VAR.size() - 1];
  cout << "]" << endl;
  return out;
}
const int INF = 1e9;
vector<int> a, aa;
int get_or(int i, int j) {
  cout << "or " << i << ' ' << j << endl;
  int val;
  cin >> val;
  return val;
}
int get_and(int i, int j) {
  cout << "and " << i << ' ' << j << endl;
  int val;
  cin >> val;
  return val;
}
int get_a(int a_and_b, int a_and_c, int b_and_c, int a_or_b, int a_or_c,
          int b_or_c) {
  int A = a_and_b;
  int pos = a_or_b - a_and_b;
  pos -= pos & b_and_c;
  A += pos & a_or_c;
  return A;
}
tuple<int, int, int> solve(int a, int b, int c) {
  int a_and_b = get_and(a, b);
  int a_and_c = get_and(a, c);
  int b_and_c = get_and(b, c);
  int a_or_b = get_or(a, b);
  int a_or_c = get_or(a, c);
  int b_or_c = get_or(b, c);
  int A = get_a(a_and_b, a_and_c, b_and_c, a_or_b, a_or_c, b_or_c);
  int B = get_a(a_and_b, b_and_c, a_and_c, a_or_b, b_or_c, a_or_c);
  int C = get_a(a_and_c, b_and_c, a_and_b, a_or_c, b_or_c, a_or_b);
  return {A, B, C};
}
int solve2(int A, int And, int Or) {
  int B = And;
  int pos = Or - And;
  pos -= pos & A;
  return B + pos;
}
int main() {
  ios_base::sync_with_stdio(0);
  int N, K;
  cin >> N >> K;
  a.resize(N + 1, 0);
  int last = 0;
  for (int i = 1; i + 2 <= N; i += 3) {
    auto tup = solve(i, i + 1, i + 2);
    auto [A, B, C] = tup;
    a[i] = A;
    a[i + 1] = B;
    a[i + 2] = C;
    last = i + 2;
  }
  for (int i = last + 1; i <= N; i++) {
    int And = get_and(i - 1, i);
    int Or = get_or(i - 1, i);
    a[i] = solve2(a[i - 1], And, Or);
  }
  sort(a.begin(), a.end());
  cout << "finish " << a[K] << endl;
  return 0;
}
