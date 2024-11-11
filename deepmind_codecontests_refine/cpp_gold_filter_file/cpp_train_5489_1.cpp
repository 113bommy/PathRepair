#include <bits/stdc++.h>
using namespace std;
string A[105];
int n, i;
bool d;
bool check(string a, string b) {
  bool check;
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] == b[0]) {
      check = 0;
      for (int j = 0, t = i; j < b.size(); ++j, ++t) {
        if (t >= a.size() || a[t] != b[j]) {
          check = 1;
          break;
        }
      }
      if (!check) {
        return 1;
      }
    }
  }
  return 0;
}
int main() {
  for (cin >> n; i < n; ++i) cin >> A[i];
  sort(A, A + n, [](string a, string b) {
    if (a.size() == b.size()) return a < b;
    return a.size() < b.size();
  });
  for (i = 1; i < n; ++i) {
    if (!check(A[i], A[i - 1])) {
      d = 1;
      break;
    }
  }
  if (!d) {
    cout << "YES\n";
    for (i = 0; i < n; ++i) cout << A[i] << endl;
  } else
    cout << "NO\n";
  return 0;
}
