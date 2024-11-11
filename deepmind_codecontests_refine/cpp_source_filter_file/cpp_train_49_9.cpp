#include <bits/stdc++.h>
using namespace std;
int x[50], y[50];
void print_term(int x, int i) {
  cout << "(" << x / 2 << "*((abs((t-" << i - 1 << "))+abs((t-" << i + 1
       << ")))-(abs((t-" << i << "))+abs((t-" << i << ")))))";
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int r;
    cin >> x[i] >> y[i] >> r;
  }
  for (int i = 1; i < n; ++i) {
    cout << '(';
  }
  print_term(x[0], 1);
  for (int i = 1; i < n; ++i) {
    cout << '+';
    print_term(x[i], i + 1);
    cout << ')';
  }
  cout << endl;
  for (int i = 1; i < n; ++i) {
    cout << '(';
  }
  print_term(y[0], 1);
  for (int i = 1; i < n; ++i) {
    cout << '+';
    print_term(y[i], i + 1);
    cout << ')';
  }
  return 0;
}
