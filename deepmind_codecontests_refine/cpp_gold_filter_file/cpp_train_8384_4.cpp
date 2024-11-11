#include <bits/stdc++.h>
using namespace std;
long double v1, v2, l;
int n;
long double f(long double L) {
  long double first_man_time = L / v2 + (l - L) / v1;
  long double now = L / v2, cur_pos = L;
  for (int i = 1; i < n; i++) {
    long double new_now, new_pos;
    new_now = now + (cur_pos - (now * v1)) / (v1 + v2);
    cur_pos = new_now * v1;
    long double new_time = new_now + (new_now - now) * (v1 + v2) / (v2 - v1);
    if (new_time > first_man_time) return 1;
    cur_pos = (new_time - L / v2) * v1 + L;
    now = new_time;
  }
  return now - first_man_time;
}
long double bin() {
  long double left = 0, right = l;
  for (int i = 0; i < 200; i++) {
    long double middle = (left + right) / 2;
    if (f(middle) < 0)
      left = middle;
    else
      right = middle;
  }
  return left;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int k;
  cin >> n >> l >> v1 >> v2 >> k;
  n = (n + k - 1) / k;
  long double L = bin();
  cout.precision(20);
  cout << fixed;
  cout << L / v2 + (l - L) / v1;
  return 0;
}
