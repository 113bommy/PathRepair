#include <bits/stdc++.h>
using namespace std;
int n, k, b[100010];
int func(int n) {
  if (n == 0 || n == 2) return 0;
  if (n == 1 || n == 3) return 1;
  if (n == 4) return 2;
  if (n % 2) return 0;
  if (func(n / 2) == 1) return 2;
  return 1;
}
int func1(int n) {
  if (n == 0 || n == 3) return 0;
  if (n == 1 || n == 4) return 1;
  if (n == 2) return 2;
  if (n % 2) return 0;
  return 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  vector<int> a;
  cin >> n >> k;
  a.resize(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int s;
  if (k % 2) {
    s = func(a[0]);
    for (int i = 1; i < n; i++) s = s ^ func(a[i]);
  } else {
    s = func1(a[0]);
    for (int i = 1; i < n; i++) s = s ^ func1(a[i]);
  }
  if (s)
    cout << "Kevin";
  else
    cout << "Nicky";
  return 0;
}
