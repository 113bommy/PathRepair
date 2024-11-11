#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << "! 1 1" << endl;
    return;
  }
  char c;
  int min = 1;
  int max = 2;
  cout << "? " << min << " " << max << endl;
  cin >> c;
  if (c == '>') swap(min, max);
  for (int i = 3; i <= n; i += 2) {
    if (i == n) {
      cout << "? " << min << " " << i << endl;
      cin >> c;
      if (c != '<') min = i;
      cout << "? " << max << " " << i << endl;
      cin >> c;
      if (c != '>') max = i;
      break;
    }
    int a, b;
    cout << "? " << i << " " << (i + 1) << endl;
    cin >> c;
    if (c == '<') {
      a = i;
      b = i + 1;
    } else {
      a = i + 1;
      b = i;
    }
    cout << "? " << min << " " << a << endl;
    cin >> c;
    if (c != '<') min = a;
    cout << "? " << max << " " << b << endl;
    cin >> c;
    if (c != '>') max = b;
  }
  cout << "! " << min << " " << max << endl;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) solve();
}
