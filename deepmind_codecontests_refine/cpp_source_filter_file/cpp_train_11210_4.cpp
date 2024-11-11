#include <bits/stdc++.h>
using namespace std;
template <class T, class... U>
void input(T&& a, U&&... b) {
  cin >> forward<T>(a);
  (int[]){(cin >> forward<U>(b), 0)...};
}
template <class T, class... U>
void output(T&& a, U&&... b) {
  cout << forward<T>(a);
  (int[]){(cout << forward<U>(b), 0)...};
}
template <class T, class... U>
void debug(T&& a, U&&... b) {
  cerr << "[debug]";
  cerr << forward<T>(a);
  (int[]){(cerr << forward<U>(b), 0)...};
}
void no() { output("NO\n"); }
void yes() { output("YES\n"); }
void error() {
  cerr << "ERROR\n";
  exit(1);
}
void solve() {}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  debug("compiled\n");
  int n;
  input(n);
  int a[n];
  for (int i = (0); i <= (n - 1); i++) input(a[i]);
  ;
  debug(string(20, '=') + '\n');
  if (n == 1 || (n == 2 && a[0] == a[1])) {
    output("-1\n");
  } else {
    output("1\n", *min_element(a, a + n), '\n');
  }
}
