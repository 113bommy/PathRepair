#include <bits/stdc++.h>
using namespace std;
struct pair2 {
  int first;
  int second;
  pair2(int a1, int a2) {
    first = a1;
    second = a2;
  }
  const bool operator<(const pair2 &two) { return this->first < two.first; }
};
const long long mod = 1000000007;
long long gcd(long long a, long long b) {
  if (b > a) swap(a, b);
  while (a > 0 && b > 0) {
    a %= b;
    swap(a, b);
  }
  return a + b;
}
long long generaterandomnum() {
  return (long long)(rand()) * (RAND_MAX + 1) + rand();
}
int main() {
  ios_base::sync_with_stdio(false);
  int n, start, x;
  cin >> n >> start >> x;
  cout << "? " << start << endl;
  vector<bool> used(n + 1, false);
  int left;
  int leftnext;
  cin >> left >> leftnext;
  used[start] = true;
  if (left >= x) {
    cout << "! " << left << endl;
    return 0;
  }
  for (int i = 0; i < 1100; i++) {
    int x = generaterandomnum() % n + 1;
    int l, ln;
    used[x] = true;
    cout << "? " << x << endl;
    cin >> l >> ln;
    if (l > left && l < x) {
      left = l;
      leftnext = ln;
    }
    if (l == x) {
      cout << "! " << l << endl;
      return 0;
    }
  }
  while (left < x && leftnext != -1) {
    cout << "? " << leftnext << endl;
    cin >> left >> leftnext;
  }
  if (left > x) {
    cout << "! " << left << endl;
    return 0;
  } else {
    cout << "! -1" << endl;
  }
  return 0;
}
