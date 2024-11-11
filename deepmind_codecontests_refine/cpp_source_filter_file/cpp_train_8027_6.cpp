#include <bits/stdc++.h>
using namespace std;
int ar[100001];
int n, k;
void f(int x) {
  int acc = 0, c = 0;
  for (int i = 1; i <= n; i++) {
    acc += ar[i];
    if (acc == x) {
      c++;
      acc = 0;
    }
  }
  if (acc == 0 && c == k) {
    cout << "YES\n";
    acc = 0, c = 0;
    for (int i = 1; i <= n; i++) {
      c++;
      acc += ar[i];
      if (acc == x) {
        cout << c << " ";
        c = 0;
        acc = 0;
      }
    }
    exit(0);
  }
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> ar[i];
  int s = 0;
  for (int i = 1; i <= n; i++) s += ar[i];
  for (int i = 1; i <= sqrt(s); i++) {
    if (s % i == 0) {
      f(i);
      f(s / i);
    }
  }
  cout << "NO\n";
}
