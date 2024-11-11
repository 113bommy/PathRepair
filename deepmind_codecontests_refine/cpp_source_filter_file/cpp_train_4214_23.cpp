#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int n;
bool check(vector<int> b) {
  sort(b.begin(), b.end());
  if (b[0] + b[1] + b[2] + b[3] == 2 * (b[1] + b[2]) &&
      b[1] + b[2] == 2 * (b[3] - b[0]))
    return true;
  return false;
}
int main() {
  cin >> n;
  for (int i = 0, x; i < n; i++) cin >> x, a.push_back(x);
  sort(a.begin(), a.end());
  if (n == 0)
    cout << "YES\n"
         << "1 1 3 3";
  if (n == 1) cout << "YES\n" << a[0] << "\n" << 3 * a[0] << "\n" << 3 * a[0];
  if (n == 2) {
    if (3 * a[0] < a[1])
      cout << "NO";
    else
      cout << "YES\n" << 4 * a[0] - a[1] << "\n" << 3 * a[0];
  }
  if (n == 3) {
    a.push_back(3 * a[0]);
    if (check(a)) {
      cout << "YES\n" << 3 * a[0];
      return 0;
    }
    a.pop_back();
    a.push_back(a[0] + a[2] - a[1]);
    if (check(a)) {
      cout << "YES\n" << a[0] + a[2] - a[1];
      return 0;
    }
    a.pop_back();
    a.push_back(a[2] / 3);
    if (check(a)) {
      cout << "YES\n" << a[2] / 2;
      return 0;
    }
    a.pop_back();
    cout << "NO";
  }
  if (n == 4) {
    if (check(a))
      cout << "YES";
    else
      cout << "NO";
  }
  return 0;
}
