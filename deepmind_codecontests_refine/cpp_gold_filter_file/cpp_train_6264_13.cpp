#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
void yes() {
  cout << "YES\n";
  return;
}
void no() {
  cout << "NO\n";
  return;
}
template <class T>
void out(T temp) {
  cout << temp << endl;
  return;
}
void out(double temp) {
  cout << setprecision(7) << fixed << temp << endl;
  return;
}
void out(long double temp) {
  cout << setprecision(7) << fixed << temp << endl;
  return;
}
void init() {}
void solve(int case_no) {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 1; i < n - 1; i++) {
    if (a[i] < a[i - 1] && a[i] < a[i + 1]) return no();
  }
  yes();
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  srand(time(NULL));
  init();
  int t = 1;
  for (int i = 1; i <= t; i++) solve(i);
}
