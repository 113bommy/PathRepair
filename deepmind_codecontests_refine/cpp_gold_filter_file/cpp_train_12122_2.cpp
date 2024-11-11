#include <bits/stdc++.h>
using namespace std;
string tos(int a) {
  ostringstream os("");
  os << a;
  return os.str();
}
int n, m, A[101];
int main() {
  while (cin >> n >> m) {
    int prev = n + 1;
    for (int j = (int)0; j < (int)m; ++j) {
      int t;
      cin >> t;
      if (t < prev) {
        for (int i = (int)t; i < (int)prev; ++i) A[i] = t;
        prev = t;
      }
    }
    for (int i = (int)1; i < (int)n + 1; ++i) cout << A[i] << ' ';
    cout << endl;
  }
  return 0;
}
