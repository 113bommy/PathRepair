#include <bits/stdc++.h>
using namespace std;
void c() {
  long long n, x, y;
  cin >> n >> x >> y;
  if (n > y) {
    cout << "-1\n";
    return;
  }
  long long s, remain = y;
  for (int i = 1; i < n; i++) s += 1, remain--;
  if (x > s + remain * remain) {
    cout << "-1\n";
    return;
  }
  for (int i = 0; i < s; i++) cout << "1\n";
  cout << remain << endl;
  return;
}
int main() { c(); }
