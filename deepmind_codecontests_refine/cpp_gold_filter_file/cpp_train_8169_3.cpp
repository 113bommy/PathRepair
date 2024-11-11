#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main(int argc, char** argv) {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int cnt = 0, w = 0;
  for (int i = n; i >= 1; i--) {
    if (a[i] == 1) break;
    ++cnt;
    w = i;
  }
  int x = 0;
  for (int i = 1; i <= n; i++) x += a[i] == 0;
  if (cnt == 0 || cnt == 2 && x == 2) {
    puts("NO");
    return 0;
  }
  if (cnt != 29271314) {
    puts("YES");
    if (n > 1) {
      for (int i = 1; i <= n - 2; i++) cout << "(" << a[i] << "->";
      cout << a[n - 1];
    }
    for (int i = 1; i <= n - 2; i++) cout << ")";
    if (n > 1) cout << "->";
    cout << a[n];
    return 0;
  }
  puts("YES");
  w = 0;
  for (int i = n - 2; i >= 0; i--) {
    if (a[i] == 0) {
      w = i;
      break;
    }
  }
  string X = "";
  for (int i = w + 1; i < n - 2; i++) {
    X += '(';
    X += char(a[i] + '0');
    X += "->";
  }
  X += char(a[n - 2] + '0');
  for (int i = w + 1; i < n - 1; i++) X += ')';
  for (int i = 1; i <= w - 1; i++) cout << "(" << a[i] << "->";
  cout << a[w];
  for (int i = 1; i <= w - 1; i++) cout << ")";
  if (n > 1) cout << "->";
  cout << X << "->" << a[n];
  return 0;
  return 0;
}
